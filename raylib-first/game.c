#include "includes/game.h"
#include "player.c"
#include "ball.c"

int main()
{

  SetSettings();
  InitVars();

  // Player
  Player *player = CreatePlayer(PLAYER_X_POSITION, PLAYER_Y_POSITION);

  // Ball
  Ball *ball = CreateBall(100, 100, 10);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);

  while (!WindowShouldClose())
  {
    // Update
    UpdateBall(ball);

    PrintPlayerCords(player);
    PrintBallCords(ball);
    HandlePlayerControl(player);

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);
    DrawPlayer(player);
    DrawBall(ball);
    EndDrawing();
  }

  DestroyPlayer(player);
  DestroyBall(ball);

  CloseWindow();

  return 0;
}
