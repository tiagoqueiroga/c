#include "includes/game.h"
#include "settings.c"
#include "player.c"
#include "ball.c"

int main()
{

  // Config
  Config config = InitConfig();

  // Player
  Player *player = CreatePlayer(PLAYER_INIT_POS_X, PLAYER_INIT_POS_Y);

  // Ball
  Ball *ball = CreateBall(100, 100, 10);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);

  while (!WindowShouldClose())
  {

    if (IsKeyPressed(KEY_P))
    {
      TogglePause();
    }

    // Update
    if (!GamePaused())
    {
      HandlePlayerControl(player);
      UpdateBall(ball, player);
    }

    PrintPlayerCords(player);
    PrintBallCords(ball);

    // Draw
    BeginDrawing();

    ClearBackground(BLACK);
    DrawFPS(10, 10);

    if (GamePaused())
    {
      DisplayPausedText();
    }

    DrawPlayer(player);
    DrawBall(ball);

    EndDrawing();
  }

  DestroyPlayer(player);
  DestroyBall(ball);

  CloseWindow();

  return 0;
}
