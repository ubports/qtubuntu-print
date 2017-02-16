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
#include <QtPrintSupport/qpa/qplatformprintplugin.h>
#include <QtCore/QStringList>

#include "qubuntuprintsupport_p.h"

QT_BEGIN_NAMESPACE

#define I18N_DOMAIN "qtubuntu-print"

class QUbuntuPrintSupportPlugin : public QPlatformPrinterSupportPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformPrinterSupportFactoryInterface_iid FILE "qtubuntu-print.json")

public:
    QStringList keys() const;
    QPlatformPrinterSupport *create(const QString &) Q_DECL_OVERRIDE;
};

QStringList QUbuntuPrintSupportPlugin::keys() const
{
    return QStringList(QStringLiteral("qtubuntu-print"));
}

QPlatformPrinterSupport *QUbuntuPrintSupportPlugin::create(const QString &key)
{
    if (key.compare(key, QLatin1String("qtubuntu-print"), Qt::CaseInsensitive) == 0)
        return new QUbuntuPrintSupport;
    return 0;
}

QT_END_NAMESPACE

#include "main.moc"
