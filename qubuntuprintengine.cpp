/*
 * Copyright (C) 2016 Canonical Ltd
 *
 * This file is part of qtubuntu-print.
 *
 * qtubuntu-print is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * qtubuntu-print is distributed in the hope that it will be useful,
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
#include <QtCore/QStandardPaths>
#include <QtCore/QTemporaryFile>
#include <QtCore/QUrl>
#include <QtWidgets/QMessageBox>

#include "i18n.h"

#include "qubuntuprintdevice_p.h"
#include "qubuntuprintengine_p.h"

QT_BEGIN_NAMESPACE

QUbuntuPrintEngine::QUbuntuPrintEngine(QPrinter::PrinterMode m)
    : QPdfPrintEngine(*new QUbuntuPrintEnginePrivate(m))
{
    Q_D(QUbuntuPrintEngine);
}

QUbuntuPrintEngine::~QUbuntuPrintEngine()
{

}

QUbuntuPrintEnginePrivate::QUbuntuPrintEnginePrivate(QPrinter::PrinterMode m)
    : QPdfPrintEnginePrivate(m),
    m_output_filename_auto(false)
{
}

QUbuntuPrintEnginePrivate::~QUbuntuPrintEnginePrivate()
{

}

bool QUbuntuPrintEnginePrivate::openPrintDevice()
{
    if (outDevice)
        return false;

    if (outputFileName.isEmpty()) {
        QTemporaryFile *file = new QTemporaryFile();

        if (file->open()) {
            outputFileName = file->fileName();
            m_output_filename_auto = true;

            outDevice = file;
        } else {
            qDebug() << "Failed to open file";
            delete file;
            return false;
        }
    }

    return true;
}

void QUbuntuPrintEnginePrivate::closePrintDevice()
{
    if (m_output_filename_auto) {
        // ensure file is closed and flushed
        if (outDevice) {
            outDevice->close();
        }

        // Transfer via content-hub
        com::ubuntu::content::Hub *hub = com::ubuntu::content::Hub::Client::instance();
        com::ubuntu::content::Peer peer = com::ubuntu::content::Peer{PRINTING_APP_ID};

        QVector<com::ubuntu::content::Item> items;

        // Content-hub needs file:///path not closePrintDevice/path
        QUrl url(outputFileName);
        url.setScheme("file");
        items.append(com::ubuntu::content::Item(url.toString()));

        com::ubuntu::content::Transfer *transfer = hub->create_export_to_peer(peer);

        if (transfer != Q_NULLPTR) {
            transfer->charge(items);
        } else {
            qWarning() << "Transfer failed to create, likely cannot find Peer:" << PRINTING_APP_ID;
            QMessageBox::warning(Q_NULLPTR,
                                 __("Printing failed"),
                                 __("Unable to find ubuntu-printing-app, please ensure that it is installed"));
        }

        // If we set the filename, reset it
        m_output_filename_auto = false;
        outputFileName = "";
    }

    QPdfPrintEnginePrivate::closePrintDevice();

    if (outDevice) {
        outDevice->close();

        delete outDevice;
        outDevice = Q_NULLPTR;
    }
}
