/*
 * Copyright (C) 2017 Canonical Ltd
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
#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtPrintSupport/QPrinterInfo>
#include <QtTest/QSignalSpy>
#include <QtTest/QTest>

#define PRINTER_NAME QStringLiteral("Ubuntu Printing Service")
#define PRINTER_LOCATION QStringLiteral("Internal")

// This test ensures that we are able to load a plugin qtubuntu-print and it
// acts as expected
// Qt uses the first found plugin which will be the libqtubuntu-print.so which
// has been copied into qtubuntu-print/printsupport/libqtubuntu-print.so
// (relative to this)
class TestPrinterInfo : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        QCoreApplication::addLibraryPath("qtubuntu-print");
    }

    void testAvailablePrinterNames()
    {
        QCOMPARE(QPrinterInfo::availablePrinterNames(), QStringList() << PRINTER_NAME);
    }
    void testDefaultPrinterName()
    {
        QCOMPARE(QPrinterInfo::defaultPrinterName(), PRINTER_NAME);
    }
    void testMakeModel()
    {
        QCOMPARE(QPrinterInfo::printerInfo(PRINTER_NAME).makeAndModel(), PRINTER_NAME);
    }
    void testLocation()
    {
        QCOMPARE(QPrinterInfo::printerInfo(PRINTER_NAME).location(), PRINTER_LOCATION);
    }
};

QTEST_GUILESS_MAIN(TestPrinterInfo)
#include "tst_printerinfo.moc"
