/* libglimpse - The Glimpse Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpwidgets.h
 * Copyright (C) 2000 Michael Natterer <mitch@gimp.org>
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

#ifndef __GIMP_WIDGETS_H__
#define __GIMP_WIDGETS_H__

#define __GIMP_WIDGETS_H_INSIDE__

#include <libglimpsewidgets/gimpwidgetstypes.h>

#include <libglimpsewidgets/gimpbrowser.h>
#include <libglimpsewidgets/gimpbusybox.h>
#include <libglimpsewidgets/gimpbutton.h>
#include <libglimpsewidgets/gimpcairo-utils.h>
#include <libglimpsewidgets/gimpcellrenderercolor.h>
#include <libglimpsewidgets/gimpcellrenderertoggle.h>
#include <libglimpsewidgets/gimpchainbutton.h>
#include <libglimpsewidgets/gimpcolorarea.h>
#include <libglimpsewidgets/gimpcolorbutton.h>
#include <libglimpsewidgets/gimpcolordisplay.h>
#include <libglimpsewidgets/gimpcolordisplaystack.h>
#include <libglimpsewidgets/gimpcolorhexentry.h>
#include <libglimpsewidgets/gimpcolornotebook.h>
#include <libglimpsewidgets/gimpcolorprofilechooserdialog.h>
#include <libglimpsewidgets/gimpcolorprofilecombobox.h>
#include <libglimpsewidgets/gimpcolorprofilestore.h>
#include <libglimpsewidgets/gimpcolorprofileview.h>
#include <libglimpsewidgets/gimpcolorscale.h>
#include <libglimpsewidgets/gimpcolorscales.h>
#include <libglimpsewidgets/gimpcolorselector.h>
#include <libglimpsewidgets/gimpcolorselect.h>
#include <libglimpsewidgets/gimpcolorselection.h>
#include <libglimpsewidgets/gimpdialog.h>
#include <libglimpsewidgets/gimpenumcombobox.h>
#include <libglimpsewidgets/gimpenumlabel.h>
#include <libglimpsewidgets/gimpenumstore.h>
#include <libglimpsewidgets/gimpenumwidgets.h>
#include <libglimpsewidgets/gimpfileentry.h>
#include <libglimpsewidgets/gimpframe.h>
#include <libglimpsewidgets/gimphelpui.h>
#include <libglimpsewidgets/gimphintbox.h>
#include <libglimpsewidgets/gimpicons.h>
#include <libglimpsewidgets/gimpintcombobox.h>
#include <libglimpsewidgets/gimpintstore.h>
#include <libglimpsewidgets/gimpmemsizeentry.h>
#include <libglimpsewidgets/gimpnumberpairentry.h>
#include <libglimpsewidgets/gimpoffsetarea.h>
#include <libglimpsewidgets/gimppageselector.h>
#include <libglimpsewidgets/gimppatheditor.h>
#include <libglimpsewidgets/gimppickbutton.h>
#include <libglimpsewidgets/gimppixmap.h>
#include <libglimpsewidgets/gimppreview.h>
#include <libglimpsewidgets/gimppreviewarea.h>
#include <libglimpsewidgets/gimppropwidgets.h>
#include <libglimpsewidgets/gimpquerybox.h>
#include <libglimpsewidgets/gimpruler.h>
#include <libglimpsewidgets/gimpscaleentry.h>
#include <libglimpsewidgets/gimpscrolledpreview.h>
#include <libglimpsewidgets/gimpsizeentry.h>
#include <libglimpsewidgets/gimpspinbutton.h>
#include <libglimpsewidgets/gimpstringcombobox.h>
#include <libglimpsewidgets/gimpunitcombobox.h>
#include <libglimpsewidgets/gimpunitmenu.h>
#include <libglimpsewidgets/gimpunitstore.h>
#include <libglimpsewidgets/gimpwidgets-error.h>
#include <libglimpsewidgets/gimpwidgetsutils.h>
#include <libglimpsewidgets/gimpzoommodel.h>

#include <libglimpsewidgets/gimp3migration.h>
#include <libglimpsewidgets/gimpoldwidgets.h>

#undef __GIMP_WIDGETS_H_INSIDE__

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


/*
 *  Widget Constructors
 */

GtkWidget * gimp_int_radio_group_new (gboolean          in_frame,
                                      const gchar      *frame_title,
                                      GCallback         radio_button_callback,
                                      gpointer          radio_button_callback_data,
                                      gint              initial, /* item_data */

                                      /* specify radio buttons as va_list:
                                       *  const gchar  *label,
                                       *  gint          item_data,
                                       *  GtkWidget   **widget_ptr,
                                       */

                                      ...) G_GNUC_NULL_TERMINATED;

void        gimp_int_radio_group_set_active (GtkRadioButton *radio_button,
                                             gint            item_data);


GtkWidget * gimp_radio_group_new   (gboolean            in_frame,
                                    const gchar        *frame_title,

                                    /* specify radio buttons as va_list:
                                     *  const gchar    *label,
                                     *  GCallback       callback,
                                     *  gpointer        callback_data,
                                     *  gpointer        item_data,
                                     *  GtkWidget     **widget_ptr,
                                     *  gboolean        active,
                                     */

                                    ...) G_GNUC_NULL_TERMINATED;
GtkWidget * gimp_radio_group_new2  (gboolean            in_frame,
                                    const gchar        *frame_title,
                                    GCallback           radio_button_callback,
                                    gpointer            radio_button_callback_data,
                                    gpointer            initial, /* item_data */

                                    /* specify radio buttons as va_list:
                                     *  const gchar    *label,
                                     *  gpointer        item_data,
                                     *  GtkWidget     **widget_ptr,
                                     */

                                    ...) G_GNUC_NULL_TERMINATED;

void   gimp_radio_group_set_active (GtkRadioButton     *radio_button,
                                    gpointer            item_data);


GIMP_DEPRECATED_FOR(gtk_spin_button_new)
GtkWidget * gimp_spin_button_new   (/* return value: */
                                    GtkObject         **adjustment,

                                    gdouble             value,
                                    gdouble             lower,
                                    gdouble             upper,
                                    gdouble             step_increment,
                                    gdouble             page_increment,
                                    gdouble             page_size,
                                    gdouble             climb_rate,
                                    guint               digits);

/**
 * GIMP_RANDOM_SEED_SPINBUTTON:
 * @hbox: The #GtkHBox returned by gimp_random_seed_new().
 *
 * Returns: the random_seed's #GtkSpinButton.
 **/
#define GIMP_RANDOM_SEED_SPINBUTTON(hbox) \
        (g_object_get_data (G_OBJECT (hbox), "spinbutton"))

/**
 * GIMP_RANDOM_SEED_SPINBUTTON_ADJ:
 * @hbox: The #GtkHBox returned by gimp_random_seed_new().
 *
 * Returns: the #GtkAdjustment of the random_seed's #GtkSpinButton.
 **/
#define GIMP_RANDOM_SEED_SPINBUTTON_ADJ(hbox)       \
        gtk_spin_button_get_adjustment \
        (GTK_SPIN_BUTTON (g_object_get_data (G_OBJECT (hbox), "spinbutton")))

/**
 * GIMP_RANDOM_SEED_TOGGLE:
 * @hbox: The #GtkHBox returned by gimp_random_seed_new().
 *
 * Returns: the random_seed's #GtkToggleButton.
 **/
#define GIMP_RANDOM_SEED_TOGGLE(hbox) \
        (g_object_get_data (G_OBJECT(hbox), "toggle"))

GtkWidget * gimp_random_seed_new   (guint32            *seed,
                                    gboolean           *random_seed);

/**
 * GIMP_COORDINATES_CHAINBUTTON:
 * @sizeentry: The #GimpSizeEntry returned by gimp_coordinates_new().
 *
 * Returns: the #GimpChainButton which is attached to the
 *          #GimpSizeEntry.
 **/
#define GIMP_COORDINATES_CHAINBUTTON(sizeentry) \
        (g_object_get_data (G_OBJECT (sizeentry), "chainbutton"))

GtkWidget * gimp_coordinates_new   (GimpUnit            unit,
                                    const gchar        *unit_format,
                                    gboolean            menu_show_pixels,
                                    gboolean            menu_show_percent,
                                    gint                spinbutton_width,
                                    GimpSizeEntryUpdatePolicy  update_policy,

                                    gboolean            chainbutton_active,
                                    gboolean            chain_constrains_ratio,

                                    const gchar        *xlabel,
                                    gdouble             x,
                                    gdouble             xres,
                                    gdouble             lower_boundary_x,
                                    gdouble             upper_boundary_x,
                                    gdouble             xsize_0,   /* % */
                                    gdouble             xsize_100, /* % */

                                    const gchar        *ylabel,
                                    gdouble             y,
                                    gdouble             yres,
                                    gdouble             lower_boundary_y,
                                    gdouble             upper_boundary_y,
                                    gdouble             ysize_0,   /* % */
                                    gdouble             ysize_100  /* % */);


/*
 *  Standard Callbacks
 */

void gimp_toggle_button_update           (GtkWidget       *widget,
                                          gpointer         data);

void gimp_radio_button_update            (GtkWidget       *widget,
                                          gpointer         data);

void gimp_int_adjustment_update          (GtkAdjustment   *adjustment,
                                          gpointer         data);

void gimp_uint_adjustment_update         (GtkAdjustment   *adjustment,
                                          gpointer         data);

void gimp_float_adjustment_update        (GtkAdjustment   *adjustment,
                                          gpointer         data);

void gimp_double_adjustment_update       (GtkAdjustment   *adjustment,
                                          gpointer         data);


G_END_DECLS

#endif /* __GIMP_WIDGETS_H__ */
