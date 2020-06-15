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
libm = -lm
endif

if HAVE_WINDRES
include $(top_srcdir)/build-aux/windows/gimprc-plug-ins.rule
file_psd_RC = file-psd.rc.o
endif

AM_LDFLAGS = $(mwindows)

libexecdir = $(gimpplugindir)/plug-ins/file-psd

libexec_PROGRAMS = \
	file-psd

file_psd_SOURCES = \
	psd.c			\
	psd.h			\
	psd-util.c		\
	psd-util.h		\
	psd-load.c		\
	psd-load.h		\
	psd-save.c		\
	psd-save.h		\
	psd-thumb-load.c	\
	psd-thumb-load.h	\
	psd-image-res-load.c	\
	psd-image-res-load.h	\
	psd-layer-res-load.c	\
	psd-layer-res-load.h

EXTRA_DIST = \
	TODO.txt		\
	new-resource-ids.txt

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"file-psd\"	\
	-I$(top_srcdir)			\
	$(GTK_CFLAGS)			\
	$(EXIF_CFLAGS)			\
	$(GEGL_CFLAGS)			\
	-I$(includedir)

file_psd_LDADD = \
	$(libm)			\
	$(libglimpseui)		\
	$(libglimpsewidgets)	\
	$(libglimpseconfig)	\
	$(libglimpse)		\
	$(libglimpsecolor)		\
	$(libglimpsemath)		\
	$(libglimpsebase)		\
	$(JPEG_LIBS)		\
	$(GTK_LIBS)		\
	$(GEGL_LIBS)		\
	$(EXIF_LIBS)		\
	$(IPTCDATA_LIBS)	\
	$(RT_LIBS)		\
	$(INTLLIBS)		\
	$(Z_LIBS)		\
	$(file_psd_RC)
