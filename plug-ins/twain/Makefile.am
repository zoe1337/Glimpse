## Process this file with automake to produce Makefile.in

libglimpsebase = $(top_builddir)/libglimpsebase/libglimpsebase-$(GIMP_API_VERSION).la
libglimpsecolor = $(top_builddir)/libglimpsecolor/libglimpsecolor-$(GIMP_API_VERSION).la
libglimpseconfig = $(top_builddir)/libglimpseconfig/libglimpseconfig-$(GIMP_API_VERSION).la
libglimpsemath = $(top_builddir)/libglimpsemath/libglimpsemath-$(GIMP_API_VERSION).la
libglimpseui = $(top_builddir)/libglimpse/libglimpseui-$(GIMP_API_VERSION).la
libglimpsewidgets = $(top_builddir)/libglimpsewidgets/libglimpsewidgets-$(GIMP_API_VERSION).la
libglimpse = $(top_builddir)/libglimpse/libglimpse-$(GIMP_API_VERSION).la

libexecdir = $(gimpplugindir)/plug-ins/twain

libexec_PROGRAMS = twain


if OS_WIN32
twain_LDFLAGS = -mwindows -luser32

twainplatform = tw_win.c
endif

if HAVE_WINDRES
include $(top_srcdir)/build-aux/windows/gimprc-plug-ins.rule
twain_RC = twain.rc.o
endif


twain_SOURCES = \
	tw_func.c	\
	tw_func.h	\
	tw_util.c	\
	tw_util.h	\
	twain.c		\
	twain.h		\
	tw_local.h	\
	tw_platform.h	\
	$(twainplatform)

EXTRA_DIST = \
	README		\
	gimp-twain.png	\
	tw_dump.c	\
	tw_dump.h	\
	tw_win.c

AM_CPPFLAGS = \
	-I$(top_srcdir)	\
	$(GTK_CFLAGS)	\
	$(GEGL_CFLAGS)	\
	-I$(includedir)

LDADD = \
	$(libglimpse)	\
	$(libglimpsecolor)	\
	$(libglimpsebase)	\
	$(GLIB_LIBS)	\
	$(GEGL_LIBS)	\
	$(RT_LIBS)	\
	$(INTLLIBS)	\
	$(twain_LIBS)	\
	$(twain_RC)
