/*
 * Copyright © 2014, 2017 Canonical Ltd.
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
 * Authored by: Ken VanDine <ken.vandine@canonical.com>
 *              Andrew Hayzen <andrew.hayzen@canonical.com>
 */

#define NO_TR_OVERRIDE
#include "i18n.h"

#include <libintl.h>

QT_BEGIN_NAMESPACE

void initTr(const char *domain, const char *localeDir)
{
    bindtextdomain(domain, localeDir);
    textdomain(domain);
}

QString __(const char *text, const char *domain)
{
    return QString::fromUtf8(dgettext(domain, text));
}

QT_END_NAMESPACE
