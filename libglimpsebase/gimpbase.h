/* libglimpse - The Glimpse Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

#ifndef __GIMP_BASE_H__
#define __GIMP_BASE_H__

#define __GIMP_BASE_H_INSIDE__

#include <libglimpsebase/gimpbasetypes.h>

#include <libglimpsebase/gimpchecks.h>
#include <libglimpsebase/gimpcpuaccel.h>
#include <libglimpsebase/gimpdatafiles.h>
#include <libglimpsebase/gimpenv.h>
#include <libglimpsebase/gimplimits.h>
#include <libglimpsebase/gimpmemsize.h>
#include <libglimpsebase/gimpmetadata.h>
#include <libglimpsebase/gimpparasite.h>
#include <libglimpsebase/gimprectangle.h>
#include <libglimpsebase/gimpunit.h>
#include <libglimpsebase/gimputils.h>
#include <libglimpsebase/gimpversion.h>
#include <libglimpsebase/gimpvaluearray.h>

#ifndef G_OS_WIN32
#include <libglimpsebase/gimpsignal.h>
#endif

#undef __GIMP_BASE_H_INSIDE__

#endif  /* __GIMP_BASE_H__ */
