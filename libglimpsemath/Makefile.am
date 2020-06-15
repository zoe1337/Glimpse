## Process this file with automake to produce Makefile.in

libglimpsebase = $(top_builddir)/libglimpsebase/libglimpsebase-$(GIMP_API_VERSION).la

if PLATFORM_WIN32
no_undefined = -no-undefined
endif

if PLATFORM_WIN32
else
libm = -lm
endif

if OS_WIN32
gimpmath_def = gimpmath.def
libglimpsemath_export_symbols = -export-symbols $(srcdir)/gimpmath.def

install-libtool-import-lib:
	$(INSTALL) .libs/libglimpsemath-$(GIMP_API_VERSION).dll.a $(DESTDIR)$(libdir)
	$(INSTALL) $(srcdir)/gimpmath.def $(DESTDIR)$(libdir)

uninstall-libtool-import-lib:
	-rm $(DESTDIR)$(libdir)/libglimpsemath-$(GIMP_API_VERSION).dll.a
	-rm $(DESTDIR)$(libdir)/gimpmath.def
else
install-libtool-import-lib:
uninstall-libtool-import-lib:
endif

if MS_LIB_AVAILABLE
noinst_DATA = gimpmath-$(GIMP_API_VERSION).lib

install-ms-lib:
	$(INSTALL) gimpmath-$(GIMP_API_VERSION).lib $(DESTDIR)$(libdir)

uninstall-ms-lib:
	-rm $(DESTDIR)$(libdir)/gimpmath-$(GIMP_API_VERSION).lib

gimpmath-@GIMP_API_VERSION@.lib: gimpmath.def
	lib -name:libglimpsemath-$(GIMP_API_VERSION)-@LT_CURRENT_MINUS_AGE@.dll -def:gimpmath.def -out:$@

else
install-ms-lib:
uninstall-ms-lib:
endif

libglimpsemathincludedir = $(includedir)/gimp-$(GIMP_API_VERSION)/libglimpsemath

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"libglimpseMath\"	\
	-DGIMP_MATH_COMPILATION		\
	-I$(top_srcdir)			\
	$(GLIB_CFLAGS)			\
	-I$(includedir)

EXTRA_DIST = \
	gimpmath.def

lib_LTLIBRARIES = libglimpsemath-@GIMP_API_VERSION@.la

libglimpsemath_@GIMP_API_VERSION@_la_SOURCES = \
	gimpmath.h	\
	gimpmathtypes.h	\
	gimpmatrix.c	\
	gimpmatrix.h	\
	gimpmd5.c	\
	gimpmd5.h	\
	gimpvector.c	\
	gimpvector.h

libglimpsemathinclude_HEADERS = \
	gimpmath.h	\
	gimpmathtypes.h	\
	gimpmatrix.h	\
	gimpmd5.h	\
	gimpvector.h

libglimpsemath_@GIMP_API_VERSION@_la_LDFLAGS = \
	-version-info $(LT_VERSION_INFO)	\
	$(no_undefined)				\
	$(libglimpsemath_export_symbols)

EXTRA_libglimpsemath_@GIMP_API_VERSION@_la_DEPENDENCIES = $(gimpmath_def)

libglimpsemath_@GIMP_API_VERSION@_la_LIBADD = \
	$(libglimpsebase)	\
	$(GLIB_LIBS)	\
	$(libm)


install-data-local: install-ms-lib install-libtool-import-lib

uninstall-local: uninstall-ms-lib uninstall-libtool-import-lib
