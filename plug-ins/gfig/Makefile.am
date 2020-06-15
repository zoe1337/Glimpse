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
gfig_RC = gfig.rc.o
endif

AM_LDFLAGS = $(mwindows)

SUBDIRS = gfig-examples images

libexecdir = $(gimpplugindir)/plug-ins/gfig

libexec_PROGRAMS = gfig

gfig_SOURCES = \
	gfig.c			\
	gfig.h			\
	gfig-arc.c		\
	gfig-arc.h		\
	gfig-bezier.c		\
	gfig-bezier.h		\
	gfig-circle.c		\
	gfig-circle.h		\
	gfig-dialog.c		\
	gfig-dialog.h		\
	gfig-dobject.c		\
	gfig-dobject.h		\
	gfig-ellipse.c		\
	gfig-ellipse.h		\
	gfig-grid.c		\
	gfig-grid.h		\
	gfig-line.c		\
	gfig-line.h		\
	gfig-poly.c		\
	gfig-poly.h		\
	gfig-preview.c		\
	gfig-preview.h		\
	gfig-rectangle.c	\
	gfig-rectangle.h	\
	gfig-spiral.c		\
	gfig-spiral.h		\
	gfig-star.c		\
	gfig-star.h		\
	gfig-stock.c		\
	gfig-stock.h		\
	gfig-style.c		\
	gfig-style.h    	\
	gfig-types.h

EXTRA_DIST = README

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
	$(RT_LIBS)		\
	$(INTLLIBS)		\
	$(gfig_RC)
