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
#ifndef QPDFENGINE_H
#define QPDFENGINE_H

#include <QtPrintSupport/private/qprintengine_pdf_p.h>

QT_BEGIN_NAMESPACE

class QUbuntuPrintEnginePrivate;

class QUbuntuPrintEngine : public QPdfPrintEngine
{
    Q_DECLARE_PRIVATE(QUbuntuPrintEngine)
public:
    QUbuntuPrintEngine(QPrinter::PrinterMode m);
    virtual ~QUbuntuPrintEngine();
};

class QUbuntuPrintEnginePrivate : public QPdfPrintEnginePrivate
{
    Q_DECLARE_PUBLIC(QUbuntuPrintEngine)
public:
    QUbuntuPrintEnginePrivate(QPrinter::PrinterMode m);
    ~QUbuntuPrintEnginePrivate();

    bool openPrintDevice() Q_DECL_OVERRIDE;
    void closePrintDevice() Q_DECL_OVERRIDE;
private:
    bool m_output_filename_auto;
};

QT_END_NAMESPACE

#endif // QPDFENGINE_H
