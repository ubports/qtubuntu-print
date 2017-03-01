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

#define PRINTER_NAME QStringLiteral("fakeprinter")

// This test ensures that we are able to load a plugin not from the system
// Qt uses the first found plugin which will be the libfakeprint.so which has
// been copied into fakeprinter/printsupport/libfakeprint.so (relative to this)
class TestFakePrinterInfo : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        QCoreApplication::addLibraryPath("fakeprint");
    }

    void testAvailablePrinterNames()
    {
        QCOMPARE(QPrinterInfo::availablePrinterNames(), QStringList() << PRINTER_NAME);
    }
    void testDefaultPrinterName()
    {
        QCOMPARE(QPrinterInfo::defaultPrinterName(), PRINTER_NAME);
    }
};

QTEST_GUILESS_MAIN(TestFakePrinterInfo)
#include "tst_fakeprinterinfo.moc"
