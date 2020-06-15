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
screenshot_RC = screenshot-win32-res.o
endif

AM_LDFLAGS = $(mwindows)

AM_CPPFLAGS = \
	-I$(top_srcdir)		\
	$(GTK_CFLAGS)		\
	$(GEGL_CFLAGS)		\
	$(XFIXES_CFLAGS)	\
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
	$(SCREENSHOT_LIBS)	\
	$(RT_LIBS)		\
	$(INTLLIBS)		\
	$(screenshot_RC)

libexecdir = $(gimpplugindir)/plug-ins/screenshot

libexec_PROGRAMS = screenshot

EXTRA_PROGRAMS = screenshot

screenshot_SOURCES = \
	screenshot.c				\
	screenshot.h				\
	screenshot-freedesktop.c		\
	screenshot-freedesktop.h		\
	screenshot-gnome-shell.c		\
	screenshot-gnome-shell.h		\
	screenshot-icon.h			\
	screenshot-kwin.c			\
	screenshot-kwin.h			\
	screenshot-osx.c			\
	screenshot-osx.h			\
	screenshot-x11.c			\
	screenshot-x11.h			\
	screenshot-win32.rc			\
	screenshot-win32.c			\
	screenshot-win32.h			\
	screenshot-win32-dwm-api.h		\
	screenshot-win32-magnification-api.h	\
	screenshot-win32-resource.h

EXTRA_DIST = \
	screenshot-win32-select.cur	\
	screenshot-win32-small.ico	\
	screenshot-win32.ico

if OS_WIN32
screenshot-win32-res.o: screenshot-win32.rc screenshot-win32-select.cur screenshot-win32-small.ico screenshot-win32.ico
	$(WINDRES) $(srcdir)/screenshot-win32.rc screenshot-win32-res.o
endif
