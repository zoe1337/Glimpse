## Process this file with automake to produce Makefile.in

if OS_WIN32
mwindows = -mwindows
else
libm = -lm
endif

libglimpsebase = $(top_builddir)/libglimpsebase/libglimpsebase-$(GIMP_API_VERSION).la
libglimpsecolor = $(top_builddir)/libglimpsecolor/libglimpsecolor-$(GIMP_API_VERSION).la
libglimpseconfig = $(top_builddir)/libglimpseconfig/libglimpseconfig-$(GIMP_API_VERSION).la
libglimpsemodule = $(top_builddir)/libglimpsemodule/libglimpsemodule-$(GIMP_API_VERSION).la
libglimpsewidgets = $(top_builddir)/libglimpsewidgets/libglimpsewidgets-$(GIMP_API_VERSION).la

libglimpsemath = $(top_builddir)/libglimpsemath/libglimpsemath-$(GIMP_API_VERSION).la  $(libm)

AM_CPPFLAGS = \
	$(GTK_CFLAGS)			\
	 -DTOP_SRCDIR=\"$(top_srcdir)\"	\
	-I$(top_srcdir)			\
	$(GEGL_CFLAGS)

AM_LDFLAGS = $(mwindows)


if ENABLE_GTK_DOC
noinst_PROGRAMS = $(DOC_SHOOTER)
endif

doc_shooter_SOURCES = \
	shadow.c	\
	shadow.h	\
	shooter.c	\
	units.c		\
	units.h		\
	widgets.c	\
	widgets.h

doc_shooter_LDADD = \
	$(libglimpsewidgets)	\
	$(libglimpseconfig)	\
	$(libglimpsemodule)	\
	$(libglimpsemath)		\
	$(libglimpsecolor)		\
	$(libglimpsebase)		\
	$(GTK_LIBS)		\
	$(X_LIBS) -lX11 -lXext


EXTRA_PROGRAMS = doc-shooter

EXTRA_DIST = README.shooter


clean-local:
	rm -f *.png
