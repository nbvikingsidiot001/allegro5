/*         ______   ___    ___
 *        /\  _  \ /\_ \  /\_ \
 *        \ \ \L\ \\//\ \ \//\ \      __     __   _ __   ___
 *         \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
 *          \ \ \/\ \ \_\ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \
 *           \ \_\ \_\/\____\/\____\ \____\ \____ \ \_\\ \____/
 *            \/_/\/_/\/____/\/____/\/____/\/___L\ \/_/ \/___/
 *                                           /\____/
 *                                           \_/__/
 *
 *      Simple drawing primitives.
 *
 *      See LICENSE.txt for copyright information.
 */


#include "allegro5/allegro.h"
#include "allegro5/internal/aintern_display.h"
#include "allegro5/internal/aintern_bitmap.h"


/* Function: al_clear_to_color
 */
void al_clear_to_color(ALLEGRO_COLOR color)
{
   ALLEGRO_BITMAP *target = al_get_target_bitmap();
   ASSERT(target);

   if (target->flags & ALLEGRO_MEMORY_BITMAP) {
      _al_clear_memory(&color);
   }
   else {
      ALLEGRO_DISPLAY *display = target->display;
      ASSERT(display);
      ASSERT(display->vt);
      display->vt->clear(display, &color);
   }
}


/* Function: al_clear_depth_buffer
 */
void al_clear_depth_buffer(float z)
{
   ALLEGRO_BITMAP *target = al_get_target_bitmap();
   ASSERT(target);

   if (target->flags & ALLEGRO_MEMORY_BITMAP) {
      /* has no depth buffer */
   }
   else {
      ALLEGRO_DISPLAY *display = target->display;
      ASSERT(display);
      display->vt->clear_depth_buffer(display, z);
   }
}


/* Function: al_draw_pixel
 */
void al_draw_pixel(float x, float y, ALLEGRO_COLOR color)
{
   ALLEGRO_BITMAP *target = al_get_target_bitmap();

   ASSERT(target);

   if (target->flags & ALLEGRO_MEMORY_BITMAP) {
      _al_draw_pixel_memory(target, x, y, &color);
   }
   else {
      ALLEGRO_DISPLAY *display = target->display;
      ASSERT(display);
      ASSERT(display->vt);
      display->vt->draw_pixel(display, x, y, &color);
   }
}


/* vim: set sts=3 sw=3 et: */
