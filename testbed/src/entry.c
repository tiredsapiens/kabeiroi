// #include "../../engine/src/core/logger.h"
#include "game.h"
#include <entry.h>
//#include <core/kmemeory.h>
#include "../../engine/src/core/kmemory.h"


//definition to create the game
b8 create_game(game *out_game) {

  out_game->app_config.start_pos_x = 100;
  out_game->app_config.start_pos_y = 100;
  out_game->app_config.start_width = 1280;
  out_game->app_config.start_height = 720;
  out_game->app_config.name = "KABEIROI engine";
  out_game->update = game_update;
  out_game->render = game_render;
  out_game->initialize = game_initialize;
  out_game->on_resize = game_on_resize;
  int a = 8;
  void *b = &b;
  out_game->state = kallocate(sizeof(game_state), MEMORY_TAG_GAME);
  //kfree(b, sizeof(int), MEMORY_TAG_GAME);
  //printf("hiiiiiii %d\n", MEMORY_TAG_MAX_TAGS);

  return TRUE;
}