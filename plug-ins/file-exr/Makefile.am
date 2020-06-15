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

# if HAVE_WINDRES
# include $(top_srcdir)/build-aux/windows/gimprc-plug-ins.rule
# file_exr_RC = file-exr.rc.o
# endif

AM_LDFLAGS = $(mwindows)

libexecdir = $(gimpplugindir)/plug-ins/file-exr

AM_CPPFLAGS = \
	-I$(top_srcdir)	  \
	$(GTK_CFLAGS)	  \
	$(GEGL_CFLAGS)    \
	$(OPENEXR_CFLAGS) \
	$(LCMS_CFLAGS) \
	-I$(includedir)

libexec_PROGRAMS = file-exr

file_exr_SOURCES = \
	exr-attribute-blob.h	\
	file-exr.c		\
	openexr-wrapper.cc	\
	openexr-wrapper.h

file_exr_LDADD = \
	$(OPENEXR_LIBS)		\
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
	$(LCMS_LIBS)		\
	$(file_exr_RC)
