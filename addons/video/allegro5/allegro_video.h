#ifndef __al_included_allegro_video_h
#define __al_included_allegro_video_h

#ifdef __cplusplus
   extern "C" {
#endif

#include "allegro5/allegro5.h"
#include "allegro5/allegro_audio.h"

#if (defined ALLEGRO_MINGW32) || (defined ALLEGRO_MSVC) || (defined ALLEGRO_BCC32)
   #ifndef ALLEGRO_STATICLINK
      #ifdef ALLEGRO_VIDEO_SRC
         #define _ALLEGRO_VIDEO_DLL __declspec(dllexport)
      #else
         #define _ALLEGRO_VIDEO_DLL __declspec(dllimport)
      #endif
   #else
      #define _ALLEGRO_VIDEO_DLL
   #endif
#endif

#if defined ALLEGRO_MSVC
   #define ALLEGRO_VIDEO_FUNC(type, name, args)      _ALLEGRO_VIDEO_DLL type __cdecl name args
#elif defined ALLEGRO_MINGW32
   #define ALLEGRO_VIDEO_FUNC(type, name, args)      extern type name args
#elif defined ALLEGRO_BCC32
   #define ALLEGRO_VIDEO_FUNC(type, name, args)      extern _ALLEGRO_VIDEO_DLL type name args
#else
   #define ALLEGRO_VIDEO_FUNC      AL_FUNC
#endif

/* Enum: ALLEGRO_VIDEO_EVENT_TYPE
 */
enum ALLEGRO_VIDEO_EVENT_TYPE
{
   ALLEGRO_EVENT_VIDEO_FRAME_ALLOC  = 550,
   ALLEGRO_EVENT_VIDEO_FRAME_SHOW   = 551
};

typedef struct ALLEGRO_VIDEO ALLEGRO_VIDEO;

ALLEGRO_VIDEO_FUNC(ALLEGRO_VIDEO *, al_open_video, (char const *filename));
ALLEGRO_VIDEO_FUNC(void, al_close_video, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(void, al_start_video, (ALLEGRO_VIDEO *video, ALLEGRO_MIXER *mixer));
ALLEGRO_VIDEO_FUNC(void, al_start_video_with_voice, (ALLEGRO_VIDEO *video, ALLEGRO_VOICE *voice));
ALLEGRO_VIDEO_FUNC(ALLEGRO_EVENT_SOURCE *, al_get_video_event_source, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(void, al_pause_video, (ALLEGRO_VIDEO *video, bool paused));
ALLEGRO_VIDEO_FUNC(bool, al_is_video_paused, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(double, al_get_video_aspect_ratio, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(double, al_get_video_audio_rate, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(double, al_get_video_fps, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(int, al_get_video_width, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(int, al_get_video_height, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(ALLEGRO_BITMAP *, al_get_video_frame, (ALLEGRO_VIDEO *video));
ALLEGRO_VIDEO_FUNC(double, al_get_video_position, (ALLEGRO_VIDEO *video, int which));
ALLEGRO_VIDEO_FUNC(void, al_seek_video, (ALLEGRO_VIDEO *video, double pos_in_seconds));

#ifdef __cplusplus
   }
#endif

#endif
