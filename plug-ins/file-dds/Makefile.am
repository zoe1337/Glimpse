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
else
libm     = -lm
endif

if HAVE_WINDRES
include $(top_srcdir)/build-aux/windows/gimprc-plug-ins.rule
file_dds_RC = file-dds.rc.o
endif

AM_LDFLAGS = $(mwindows)
AM_CFLAGS = -fno-strict-aliasing

libexecdir = $(gimpplugindir)/plug-ins/file-dds

libexec_PROGRAMS = file-dds

file_dds_SOURCES = \
	dds.c			\
	dds.h			\
	color.c			\
	color.h			\
	ddsplugin.h		\
	ddsread.c		\
	ddswrite.c		\
	dxt.c			\
	dxt.h			\
	dxt_tables.h	\
	endian_rw.h		\
	imath.h			\
	mipmap.c		\
	mipmap.h		\
	misc.c			\
	misc.h			\
	mktables.c		\
	vec.h

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
	$(libm)			\
	$(GTK_LIBS)		\
	$(GEGL_LIBS)		\
	$(RT_LIBS)		\
	$(INTLLIBS)		\
	$(file_dds_RC)
