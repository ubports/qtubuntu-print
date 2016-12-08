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
#include "qpdfdevice_p.h"

QPDFDevice::QPDFDevice()
{

}

QPDFDevice::QPDFDevice(const QString &id)
{
    Q_UNUSED(id)

    // have to set ID otherwise printer has no name
    // and QPrinter ends up thinking it is not a NativePrinter
    // which then allows the user to change the output filename
    m_id = id;
    m_name = QStringLiteral(PRINTER_NAME);
    m_location = QStringLiteral("Internal");
    m_makeAndModel = QStringLiteral("PDF Printing Service");
}

bool QPDFDevice::isValid() const
{
    return true;
}
