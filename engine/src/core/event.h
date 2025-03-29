#pragma once
#include "../defines.h"

typedef struct event_context {
  // 128 bytes
  union {
    i64 i64[2];
    u64 u64[2];
    f64 f64[2];

    i32 i32[4];
    u32 u32[4];
    f32 f32[4];

    i16 i16[8];
    u16 u16[8];

    i8 i8[16];
    u8 u8[16];

    char c[16];

  } data;
} event_context;

typedef b8 (*PFN_on_event)(u16 code, void *sender, void *listener_inst, event_context data);
b8 event_initialize();
void event_shutdown();

/**
 * register to listen for when events are setn with the prvided code. events will duplicate
 * listener/callback combos will not be reisgtered again and will cause this to return FALSE
 * @param code the vent code to listen for
 * @param listener a pointer to a listener instance. can be 0/null
 * @param on_event The callback function pointer to be invoked when the event code is fired.
 * @returns TRUE if the event is successfully registerd, otheriwse FALSE
 */
KAPI b8 event_register(u16 code, void *listener, PFN_on_event on_event);
/**
 * Unregister from listenin for when events are set with the privded code. If no mathcing
 * registration is found this function returns FALSE
 * @param code the event code tostop listening for.
 * @param listener a pointer to a listener instane, can be null/0
 * @on_event the callback function pointer to be unregistered
 * @returns TRUE if the vent is succesffully unregistered, otherwise fasle
 */
KAPI b8 event_unregister(u16 code, void *listener, PFN_on_event on_event);
/**
 * Fires an event to listeners of the given code. If an event handler returns TRUE
 * the event is considered handled and is not passed on to any more listeners
 * @param code the even t code to fire
 * @param sender a poiinte rto the sender can be null
 * @param data the event data
 * @returns TRUE if handled otherwise FALSE
 */
KAPI b8 event_fire(u16 code, void *listener, event_context context);

typedef enum system_event_code {
  // shuts application down on the next fram.
  EVENT_CODE_APPLICATION_QUIT = 0x01,
  // keyboard key pressed
  EVENT_CODE_KEY_PRESSED = 0x02,
  EVENT_CODE_KEY_RELEASED = 0x03,
  EVENT_CODE_BUTTON_PRESSED = 0x04,
  EVENT_CODE_BUTTON_RELEASED = 0x05,
  EVENT_CODE_MOUSE_MOVED = 0x06,
  EVENT_CODE_MOUSE_WHEEL = 0x07,
  EVENT_CODE_RESSIZED = 0x08,

  MAX_EVENT_CODE = 0xFF
} system_event_code;