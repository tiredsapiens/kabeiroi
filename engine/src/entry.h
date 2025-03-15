#pragma once
#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"


extern b8 create_game(game* out_game);

/**
 * main entry point of the application
 */
int main(int argc, char** argv)
{
  game game_inst;
  if (!create_game(&game_inst))
  {
    KFATAL("Failed to create game");
    return -1;
  }
  if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize)
  {
    KFATAL("GAME FUNCTIONS NOT INTIALIZED");
    return -2;
  }

  if (!application_create(&game_inst))
  {
    KINFO("application failed to create");
    return -1;
  }
  if (!application_run())
  {
    KFATAL("application failed to run");
    return -1;
  }

  return 0;
}
