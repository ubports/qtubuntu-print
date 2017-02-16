/*
 * Copyright (C) 2016 Canonical Ltd
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

#include "i18n.h"
#include "qubuntuprintdevice_p.h"

QUbuntuPrintDevice::QUbuntuPrintDevice()
{

}

QUbuntuPrintDevice::QUbuntuPrintDevice(const QString &id)
{
    Q_UNUSED(id)

    // have to set ID otherwise printer has no name
    // and QPrinter ends up thinking it is not a NativePrinter
    // which then allows the user to change the output filename
    m_id = id;
    m_name = __("Printing Service");
    m_location = __("Internal");
    m_makeAndModel = __("PDF Printing Service");

    // Disable collate, copies and duplex as they don't make sense
    m_supportsCollateCopies = false;
    m_supportsMultipleCopies = false;
    m_haveDuplexModes = false;
}

bool QUbuntuPrintDevice::isValid() const
{
    return true;
}
