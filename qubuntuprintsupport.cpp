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
#include <QtPrintSupport/qprintengine.h>
#include <QtPrintSupport/private/qprintdevice_p.h>

#include "i18n.h"
#include "qubuntuprintdevice_p.h"
#include "qubuntuprintengine_p.h"
#include "qubuntuprintsupport_p.h"

QT_BEGIN_NAMESPACE

#define I18N_DOMAIN "qtubuntu-print"

QUbuntuPrintSupport::QUbuntuPrintSupport()
{
    initTr(I18N_DOMAIN, NULL);
}

QUbuntuPrintSupport::~QUbuntuPrintSupport()
{

}

QPrintEngine *QUbuntuPrintSupport::createNativePrintEngine(QPrinter::PrinterMode printerMode)
{
    return new QUbuntuPrintEngine(printerMode);
}

QPaintEngine *QUbuntuPrintSupport::createPaintEngine(QPrintEngine *printEngine, QPrinter::PrinterMode printerMode)
{
    Q_UNUSED(printerMode)
    return static_cast<QUbuntuPrintEngine *>(printEngine);
}

QPrintDevice QUbuntuPrintSupport::createPrintDevice(const QString &id)
{
    return QPlatformPrinterSupport::createPrintDevice(new QUbuntuPrintDevice(id));
}

QStringList QUbuntuPrintSupport::availablePrintDeviceIds() const
{
    return QStringList(__(PRINTER_NAME));
}

QString QUbuntuPrintSupport::defaultPrintDeviceId() const
{
    return __(PRINTER_NAME);
}

QT_END_NAMESPACE
