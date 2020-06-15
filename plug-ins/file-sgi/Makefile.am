## Process this file with automake to produce Makefile.in

libglimpsebase = $(top_builddir)/libglimpsebase/libglimpsebase-$(GIMP_API_VERSION).la
libglimpsecolor = $(top_builddir)/libglimpsecolor/libglimpsecolor-$(GIMP_API_VERSION).la
libglimpseconfig = $(top_builddir)/libglimpseconfig/libglimpseconfig-$(GIMP_API_VERSION).la
libglimpsemath = $(top_builddir)/libglimpsemath/libglimpsemath-$(GIMP_API_VERSION).la
libglimpseui = $(top_builddir)/libglimpse/libglimpseui-$(GIMP_API_VERSION).la
libglimpsewidgets = $(top_builddir)/libglimpsewidgets/libglimpsewidgets-$(GIMP_API_VERSION).la
libglimpse = $(top_builddir)/libglimpse/libglimpse-$(GIMP_API_VERSION).la

if OS_WIN32
mwindows = -mwindows
endif

if HAVE_WINDRES
include $(top_srcdir)/build-aux/windows/gimprc-plug-ins.rule
file_sgi_RC = file-sgi.rc.o
endif

AM_LDFLAGS = $(mwindows)

libexecdir = $(gimpplugindir)/plug-ins/file-sgi

libexec_PROGRAMS = file-sgi

file_sgi_SOURCES = \
	sgi.c		\
	sgi-lib.c	\
	sgi-lib.h

AM_CPPFLAGS = \
	-I$(top_srcdir)	\
	$(GTK_CFLAGS)	\
	$(GEGL_CFLAGS) \
	-I$(includedir)

LDADD = \
	$(libglimpseui)		\
	$(libglimpsewidgets)	\
	$(libglimpseconfig)	\
	$(libglimpsemath)		\
	$(libglimpse)		\
	$(libglimpsecolor)		\
	$(libglimpsebase)		\
	$(GTK_LIBS)		\
	$(GEGL_LIBS)		\
	$(RT_LIBS)		\
	$(INTLLIBS)		\
	$(file_sgi_RC)
