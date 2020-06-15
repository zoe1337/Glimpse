/*
 *   gtk-doc can't build libglimpse-scan.c without PLUG_IN_INFO being defined
 *   so we include this file as a workaround
 */

#include <glib.h>
#include <libglimpse/gimp.h>

GimpPlugInInfo PLUG_IN_INFO =
{
  NULL,
  NULL,
  NULL,
  NULL,
};
