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
#ifndef QUBUNTUPRINTDEVICE_H
#define QUBUNTUPRINTDEVICE_H

#include <qpa/qplatformprintdevice.h>

QT_BEGIN_NAMESPACE

#define PRINTER_NAME "Printing Service"

class QUbuntuPrintDevice : public QPlatformPrintDevice
{
public:
    QUbuntuPrintDevice();
    explicit QUbuntuPrintDevice(const QString &id);

    bool isValid() const Q_DECL_OVERRIDE;
};

#endif // QUBUNTUPRINTDEVICE_H
