/*
 * Copyright (C) 2016 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored-by: Andrew Hayzen <andrew.hayzen@canonical.com>
 */
#include <com/ubuntu/content/hub.h>
#include <com/ubuntu/content/item.h>
#include <com/ubuntu/content/peer.h>
#include <com/ubuntu/content/store.h>
#include <com/ubuntu/content/transfer.h>
#include <com/ubuntu/content/type.h>

#include <QDebug>
#include <QtCore/QDateTime>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtCore/QStandardPaths>
#include <QtCore/QUrl>

#include "qpdfdevice_p.h"
#include "qpdfengine_p.h"

QT_BEGIN_NAMESPACE

QPDFEngine::QPDFEngine(QPrinter::PrinterMode m)
    : QPdfPrintEngine(*new QPDFEnginePrivate(m))
{
    Q_D(QPDFEngine);
}

QPDFEngine::~QPDFEngine()
{

}

QPDFEnginePrivate::QPDFEnginePrivate(QPrinter::PrinterMode m)
    : QPdfPrintEnginePrivate(m),
    m_output_filename_auto(false)
{
}

QPDFEnginePrivate::~QPDFEnginePrivate()
{

}

bool QPDFEnginePrivate::openPrintDevice()
{
    if (outDevice)
        return false;

    if (outputFileName.isEmpty()) {
        QDir dir(QStandardPaths::writableLocation(QStandardPaths::TempLocation));

        if (!dir.exists()) {
            dir.mkpath(".");
        }

        QFileInfo fileInfo(dir.path(), QDateTime::currentDateTime().toString(Qt::ISODate));
        outputFileName = fileInfo.absoluteFilePath();
        m_output_filename_auto = true;
    }

    QFile *file = new QFile(outputFileName);

    if (!file->open(QFile::WriteOnly|QFile::Truncate)) {
        qDebug() << "Cannot write to the location.";
        delete file;
        return false;
    }

    outDevice = file;

    return true;
}

void QPDFEnginePrivate::closePrintDevice()
{
    QPdfPrintEnginePrivate::closePrintDevice();

    if (outDevice) {
        outDevice->close();
    }

    // Transfer via content-hub
    com::ubuntu::content::Hub *hub = com::ubuntu::content::Hub::Client::instance();
    com::ubuntu::content::Type documentType = com::ubuntu::content::Type::Known::documents();

    com::ubuntu::content::Peer peer = com::ubuntu::content::Peer{"ubuntu-printing-app"};

    QVector<com::ubuntu::content::Item> items;

    // Content-hub needs file:///path not /path
    QUrl url(outputFileName);
    url.setScheme("file");
    items.append(com::ubuntu::content::Item(url.toString()));

    com::ubuntu::content::Transfer *transfer = hub->create_export_to_peer_for_type(peer, documentType);

    if (transfer != Q_NULLPTR) {
        transfer->start();
        transfer->charge(items);
    } else {
        qWarning() << "Transfer failed to create, likely cannot find Peer: ubuntu-printing-app";
    }

    // If we set the filename, reset it
    if (m_output_filename_auto) {
        m_output_filename_auto = false;
        outputFileName = "";
    }
}
