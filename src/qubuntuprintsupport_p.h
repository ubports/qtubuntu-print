/*
 * Copyright (C) 2016-2017 Canonical Ltd
 *
 * This file is part of qtubuntu-print.
 *
 * qtubuntu-print is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * qtubuntu-print is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with qtubuntu-print.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored-by: Andrew Hayzen <andrew.hayzen@canonical.com>
 */
#ifndef QUBUNTUPRINTSUPPORT_H
#define QUBUNTUPRINTSUPPORT_H

#include <QtPrintSupport/qpa/qplatformprintersupport.h>
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QUbuntuPrintSupport : public QPlatformPrinterSupport
{
public:
    QUbuntuPrintSupport();
    ~QUbuntuPrintSupport();

    QPrintEngine *createNativePrintEngine(QPrinter::PrinterMode printerMode, const QString &deviceId = QString()) Q_DECL_OVERRIDE;
    QPaintEngine *createPaintEngine(QPrintEngine *printEngine, QPrinter::PrinterMode) Q_DECL_OVERRIDE;

    QPrintDevice createPrintDevice(const QString &id) Q_DECL_OVERRIDE;
    QStringList availablePrintDeviceIds() const Q_DECL_OVERRIDE;
    QString defaultPrintDeviceId() const Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QUBUNTUPRINTSUPPORT_H
