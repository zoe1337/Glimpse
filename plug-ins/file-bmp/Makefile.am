## Process this file with automake to produce Makefile.in

libglimpseui = $(top_builddir)/libglimpse/libglimpseui-$(GIMP_API_VERSION).la
libglimpsebase = $(top_builddir)/libglimpsebase/libglimpsebase-$(GIMP_API_VERSION).la
libglimpsecolor = $(top_builddir)/libglimpsecolor/libglimpsecolor-$(GIMP_API_VERSION).la
libglimpseconfig = $(top_builddir)/libglimpseconfig/libglimpseconfig-$(GIMP_API_VERSION).la
libglimpsemath = $(top_builddir)/libglimpsemath/libglimpsemath-$(GIMP_API_VERSION).la $(libm)
libglimpsemodule = $(top_builddir)/libglimpsemodule/libglimpsemodule-$(GIMP_API_VERSION).la
libglimpse = $(top_builddir)/libglimpse/libglimpse-$(GIMP_API_VERSION).la
libglimpsewidgets = $(top_builddir)/libglimpsewidgets/libglimpsewidgets-$(GIMP_API_VERSION).la

if OS_WIN32
mwindows = -mwindows
endif

if HAVE_WINDRES
include $(top_srcdir)/build-aux/windows/gimprc-plug-ins.rule
file_bmp_RC = file-bmp.rc.o
endif

AM_LDFLAGS = $(mwindows)

libexecdir = $(gimpplugindir)/plug-ins/file-bmp

libexec_PROGRAMS = file-bmp

file_bmp_SOURCES = \
	bmp.c		\
	bmp.h		\
	bmp-load.c	\
	bmp-load.h	\
	bmp-save.c	\
	bmp-save.h

AM_CPPFLAGS = \
	-I$(top_srcdir)	\
	$(GTK_CFLAGS)	\
	$(GEGL_CFLAGS) \
	-I$(includedir)

LDADD = \
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
	$(file_bmp_RC)
