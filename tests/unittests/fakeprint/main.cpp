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
#include <QtPrintSupport/qpa/qplatformprintersupport.h>
#include <QtPrintSupport/qpa/qplatformprintplugin.h>
#include <QtCore/QStringList>

#define JSON_KEY "fakeprint"
#define PRINTER_NAME "fakeprinter"

QT_BEGIN_NAMESPACE


class QFakePrintSupport : public QPlatformPrinterSupport
{
public:
    QStringList availablePrintDeviceIds() const Q_DECL_OVERRIDE;
    QString defaultPrintDeviceId() const Q_DECL_OVERRIDE;
};

QStringList QFakePrintSupport::availablePrintDeviceIds() const
{
    return QStringList(PRINTER_NAME);
}

QString QFakePrintSupport::defaultPrintDeviceId() const
{
    return PRINTER_NAME;
}


class QFakePrintSupportPlugin : public QPlatformPrinterSupportPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformPrinterSupportFactoryInterface_iid FILE "fakeprint.json")

public:
    QStringList keys() const;
    QPlatformPrinterSupport *create(const QString &) Q_DECL_OVERRIDE;
};

QStringList QFakePrintSupportPlugin::keys() const
{
    return QStringList(QStringLiteral(JSON_KEY));
}

QPlatformPrinterSupport *QFakePrintSupportPlugin::create(const QString &key)
{
    if (key.compare(key, QLatin1String(JSON_KEY), Qt::CaseInsensitive) == 0)
        return new QFakePrintSupport;
    return 0;
}

QT_END_NAMESPACE

#include "main.moc"
