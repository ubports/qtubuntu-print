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
#include <qpa/qplatformprintplugin.h>
#include <QtCore/QStringList>

#include "qpdfsupport_p.h"

QT_BEGIN_NAMESPACE

class QPDFSupportPlugin : public QPlatformPrinterSupportPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformPrinterSupportFactoryInterface_iid FILE "pdf.json")

public:
    QStringList keys() const;
    QPlatformPrinterSupport *create(const QString &) Q_DECL_OVERRIDE;
};

QStringList QPDFSupportPlugin::keys() const
{
    return QStringList(QStringLiteral("pdfsupport"));
}

QPlatformPrinterSupport *QPDFSupportPlugin::create(const QString &key)
{
    if (key.compare(key, QLatin1String("pdfsupport"), Qt::CaseInsensitive) == 0)
        return new QPDFSupport;
    return 0;
}

QT_END_NAMESPACE

#include "main.moc"
