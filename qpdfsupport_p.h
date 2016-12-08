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
#ifndef QPDFSUPPORT_H
#define QPDFSUPPORT_H

#include <qpa/qplatformprintersupport.h>
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QPDFSupport : public QPlatformPrinterSupport
{
public:
    QPDFSupport();
    ~QPDFSupport();

    QPrintEngine *createNativePrintEngine(QPrinter::PrinterMode printerMode) Q_DECL_OVERRIDE;
    QPaintEngine *createPaintEngine(QPrintEngine *printEngine, QPrinter::PrinterMode) Q_DECL_OVERRIDE;

    QPrintDevice createPrintDevice(const QString &id) Q_DECL_OVERRIDE;
    QStringList availablePrintDeviceIds() const Q_DECL_OVERRIDE;
    QString defaultPrintDeviceId() const Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QPDFSUPPORT_H
