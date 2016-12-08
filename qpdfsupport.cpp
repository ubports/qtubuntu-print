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
#include <QtPrintSupport/qprintengine.h>
#include <QtPrintSupport/private/qprintdevice_p.h>

#include "qpdfdevice_p.h"
#include "qpdfengine_p.h"
#include "qpdfsupport_p.h"

QT_BEGIN_NAMESPACE

QPDFSupport::QPDFSupport()
{

}

QPDFSupport::~QPDFSupport()
{

}

QPrintEngine *QPDFSupport::createNativePrintEngine(QPrinter::PrinterMode printerMode)
{
    return new QPDFEngine(printerMode);
}

QPaintEngine *QPDFSupport::createPaintEngine(QPrintEngine *printEngine, QPrinter::PrinterMode printerMode)
{
    Q_UNUSED(printerMode)
    return static_cast<QPDFEngine *>(printEngine);
}

QPrintDevice QPDFSupport::createPrintDevice(const QString &id)
{
    return QPlatformPrinterSupport::createPrintDevice(new QPDFDevice(id));
}

QStringList QPDFSupport::availablePrintDeviceIds() const
{
    return QStringList(QStringLiteral(PRINTER_NAME));
}

QString QPDFSupport::defaultPrintDeviceId() const
{
    return QStringLiteral(PRINTER_NAME);
}

QT_END_NAMESPACE
