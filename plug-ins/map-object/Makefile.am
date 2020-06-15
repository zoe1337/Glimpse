## Process this file with automake to produce Makefile.in

if OS_WIN32
mwindows = -mwindows
else
libm = -lm
endif

libglimpsebase = $(top_builddir)/libglimpsebase/libglimpsebase-$(GIMP_API_VERSION).la
libglimpsecolor = $(top_builddir)/libglimpsecolor/libglimpsecolor-$(GIMP_API_VERSION).la
libglimpseconfig = $(top_builddir)/libglimpseconfig/libglimpseconfig-$(GIMP_API_VERSION).la
libglimpsemath = $(top_builddir)/libglimpsemath/libglimpsemath-$(GIMP_API_VERSION).la
libglimpseui = $(top_builddir)/libglimpse/libglimpseui-$(GIMP_API_VERSION).la
libglimpsewidgets = $(top_builddir)/libglimpsewidgets/libglimpsewidgets-$(GIMP_API_VERSION).la
libglimpse = $(top_builddir)/libglimpse/libglimpse-$(GIMP_API_VERSION).la

if HAVE_WINDRES
include $(top_srcdir)/build-aux/windows/gimprc-plug-ins.rule
map_object_RC = map-object.rc.o
endif

AM_LDFLAGS = $(mwindows)

libexecdir = $(gimpplugindir)/plug-ins/map-object

libexec_PROGRAMS = map-object

map_object_SOURCES = \
	arcball.c		\
	arcball.h		\
	map-object-apply.c	\
	map-object-apply.h	\
	map-object-image.c	\
	map-object-image.h	\
	map-object-main.c	\
	map-object-main.h	\
	map-object-preview.c	\
	map-object-preview.h	\
	map-object-shade.c	\
	map-object-shade.h	\
	map-object-stock.c	\
	map-object-stock.h	\
	map-object-ui.c		\
	map-object-ui.h

AM_CPPFLAGS = \
	-I$(top_srcdir)	\
	$(GTK_CFLAGS)	\
	$(GEGL_CFLAGS) \
	-I$(includedir)

LDADD = \
	$(libm)			\
	$(libglimpseui)		\
	$(libglimpsewidgets)	\
	$(libglimpseconfig)	\
	$(libglimpse)		\
	$(libglimpsecolor)		\
	$(libglimpsemath)		\
	$(libglimpsebase)		\
	$(GTK_LIBS)		\
	$(GEGL_LIBS)		\
	$(RT_LIBS)		\
	$(INTLLIBS)		\
	$(map_object_RC)
