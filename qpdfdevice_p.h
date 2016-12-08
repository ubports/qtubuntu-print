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
#ifndef QPDFDEVICE_H
#define QPDFDEVICE_H

#include <qpa/qplatformprintdevice.h>

QT_BEGIN_NAMESPACE

#define PRINTER_NAME "Printing Service"

class QPDFDevice : public QPlatformPrintDevice
{
public:
    QPDFDevice();
    explicit QPDFDevice(const QString &id);

    bool isValid() const Q_DECL_OVERRIDE;
};

#endif // QPDFDEVICE_H
