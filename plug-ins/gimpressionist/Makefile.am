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

SUBDIRS = Brushes Paper Presets

if HAVE_WINDRES
include $(top_srcdir)/build-aux/windows/gimprc-plug-ins.rule
gimpressionist_RC = gimpressionist.rc.o
endif

AM_CPPFLAGS = \
	-DDEFAULTPATH=\""~/$(gimpdir)/gimpressionist:$(gimpdatadir)/gimpressionist"\"	\
	-I$(top_srcdir)	\
	$(GTK_CFLAGS)	\
	$(GEGL_CFLAGS)	\
	-I$(includedir)

AM_LDFLAGS = $(mwindows)


libexecdir = $(gimpplugindir)/plug-ins/gimpressionist

libexec_PROGRAMS = gimpressionist

gimpressionist_SOURCES = \
	brush.c			\
	brush.h			\
	color.c			\
	color.h			\
	general.c		\
	general.h		\
	gimp.c			\
	gimpressionist.c	\
	gimpressionist.h	\
	globals.c		\
	infile.h        	\
	orientation.h		\
	orientation.c		\
	orientmap.h     \
	orientmap.c		\
	paper.c			\
	paper.h			\
	placement.c		\
	placement.h		\
	plasma.c		\
	ppmtool.c		\
	ppmtool.h		\
	presets.c		\
	presets.h		\
	preview.c		\
	preview.h		\
	random.h        	\
	repaint.c		\
	size.h          	\
	size.c			\
	sizemap.c		\
	utils.c

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
	$(gimpressionist_RC)

EXTRA_DIST = README
