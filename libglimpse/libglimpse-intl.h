/* libglimpse - The Glimpse Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * libglimpse-intl.h
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

#ifndef __libglimpse_INTL_H__
#define __libglimpse_INTL_H__

#ifndef GETTEXT_PACKAGE
#error "config.h must be included prior to libglimpse-intl.h"
#endif

#include <libintl.h>


#define  _(String) dgettext (GETTEXT_PACKAGE "-libglimpse", String)
#define Q_(String) g_dpgettext (GETTEXT_PACKAGE "-libglimpse", String, 0)
#define C_(Context,String) g_dpgettext (GETTEXT_PACKAGE "-libglimpse", Context "\004" String, strlen (Context) + 1)

#undef gettext
#define gettext(String) dgettext (GETTEXT_PACKAGE "-libglimpse", String)

#undef ngettext
#define ngettext(String1, String2, number) dngettext (GETTEXT_PACKAGE "-libglimpse", String1, String2, number)

#define N_(String) (String)
#define NC_(Context,String) (String)


#endif /* __libglimpse_INTL_H__ */
