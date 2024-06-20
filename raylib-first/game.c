#include "includes/game.h"
#include "player.c"

int main()
{

  SetSettings();
  InitVars();

  Player *player = CreatePlayer(PLAYER_X_POSITION, PLAYER_Y_POSITION);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);

  while (!WindowShouldClose())
  {
    // Update
    PrintPlayerCords(player);
    HandlePlayerControl(player);

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);
    DrawPlayer(player);
    EndDrawing();
  }

  DestroyPlayer(player);
  CloseWindow();

  return 0;
}
