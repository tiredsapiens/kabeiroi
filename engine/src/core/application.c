#include "application.h"
#include "../platform/platform.h"
#include "logger.h"
#include "game_types.h"
#include  "core/kmemeory.h"

typedef struct application_state {
  game *game_inst;
  b8 is_running;
  b8 is_suspended;
  platform_state platform;
  i16 width;
  i16 height;
  f64 last_time;
} application_state;

static application_state app_state;
static b8 is_intialized = FALSE;

b8 application_create(game *game_inst) {
  if (is_intialized) {
    KERROR("application_create() already initialized");
    return FALSE;
  }
  app_state.game_inst = game_inst;
  initialize_logging();
  // to remove
  KFATAL("A test message; %f", 3.14f);
  KERROR("A test message; %f", 3.14f);
  KWARN("A test message; %f", 3.14f);
  KINFO("A test message; %f", 3.14f);
  KDEBUG("A test message; %f", 3.14f);
  KTRACE("A test message; %f", 3.14f);

  app_state.is_running = TRUE;
  app_state.is_suspended = FALSE;

  platform_state state;
  b8 result =
      platform_startup(&app_state.platform, game_inst->app_config.name,
                       game_inst->app_config.start_pos_x, game_inst->app_config.start_pos_y,
                       game_inst->app_config.start_width, game_inst->app_config.start_height);
  if (!result) {
    return FALSE;
  }
  if (!app_state.game_inst->initialize(app_state.game_inst)) {
    KFATAL("GAME failed to initialize");
    return FALSE;
  }
  app_state.game_inst->on_resize(app_state.game_inst, app_state.width, app_state.height);
  is_intialized = TRUE;
  return TRUE;
}

b8 application_run() {
  KINFO(get_memory_usage_str());
  while (app_state.is_running) {
    if (!platform_pump_messages(&app_state.platform)) {
      app_state.is_running = FALSE;
    }
    if (!app_state.is_suspended) {
      if (!app_state.game_inst->update(app_state.game_inst, (f32)0)) {
        KFATAL("GAME failed to update");
        app_state.is_running = FALSE;
        break;
      }
      if (!app_state.game_inst->render(app_state.game_inst, (f32)0)) {
        KFATAL("GAME failed to render");
        app_state.is_running = FALSE;
        break;
      }
    }
  }
  app_state.is_running = FALSE;
  platform_shutdown(&app_state.platform);
  return TRUE;
}