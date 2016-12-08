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
#ifndef QPDFENGINE_H
#define QPDFENGINE_H

#include <QtPrintSupport/private/qprintengine_pdf_p.h>

QT_BEGIN_NAMESPACE

class QPDFEnginePrivate;

class QPDFEngine : public QPdfPrintEngine
{
    Q_DECLARE_PRIVATE(QPDFEngine)
public:
    QPDFEngine(QPrinter::PrinterMode m);
    virtual ~QPDFEngine();
};

class QPDFEnginePrivate : public QPdfPrintEnginePrivate
{
    Q_DECLARE_PUBLIC(QPDFEngine)
public:
    QPDFEnginePrivate(QPrinter::PrinterMode m);
    ~QPDFEnginePrivate();

    bool openPrintDevice() Q_DECL_OVERRIDE;
    void closePrintDevice() Q_DECL_OVERRIDE;
private:
    bool m_output_filename_auto;
};

QT_END_NAMESPACE

#endif // QPDFENGINE_H
