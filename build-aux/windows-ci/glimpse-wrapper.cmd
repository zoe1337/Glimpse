REM This script was adapted from 
REM https://gitlab.gnome.org/GNOME/gimp/-/blob/master/build/windows/crossbuild-gitlab-ci/gimp-wrapper.cmd
glib-compile-schemas.exe ..\share\glib-2.0\schemas
gdk-pixbuf-query-loaders.exe --update-cache
glimpse-0.1.9.exe