#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 860
#define SCREEN_HEIGHT 440
#define GAME_TITLE "Raylib game"
#define VELOCITY 10

#define PLAYER_INIT_WIDTH 50
#define PLAYER_INIT_HEIGHT 50

#define SCREEN_BOUND_X (SCREEN_WIDTH - PLAYER_INIT_WIDTH)

Vector2 generatePos()
{
  srand(time(0));

  Vector2 vec2;

  vec2.x = (rand() % (SCREEN_WIDTH - PLAYER_INIT_WIDTH));
  vec2.y = (rand() % (SCREEN_HEIGHT - PLAYER_INIT_HEIGHT));

  return vec2;
}

void drawPlayer(Rectangle *p)
{
  DrawRectangle(p->x, p->y, p->width, p->height, BLUE);
}

void printPlayerCords(Rectangle *p)
{
  printf("posX:(%f) posY:(%f)\n", p->x, p->y);
}

void handlePlayerControl(Rectangle *p)
{

  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_L))
  {

    if (p->x < SCREEN_BOUND_X)
      p->x += GetFrameTime() + VELOCITY;
  }

  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_H))
  {
    if (p->x > 0)
      p->x += GetFrameTime() - VELOCITY;
  }

  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_K))
  {
    if (p->y > 0)
      p->y += GetFrameTime() - VELOCITY;
  }

  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_J))
  {
    if (p->y < (SCREEN_HEIGHT - p->height))
      p->y += GetFrameTime() + VELOCITY;
  }
}

int main()
{

  Vector2 vec2;

  vec2.x = generatePos().x;
  vec2.y = generatePos().y;

  printf("x:%f y:%f\n", vec2.x, vec2.y);

  // return;

  Rectangle player = {
      .x = generatePos().x,
      .y = generatePos().y,
      .width = PLAYER_INIT_WIDTH,
      .height = PLAYER_INIT_HEIGHT};

  Rectangle enemy = {
      .x = generatePos().x,
      .y = generatePos().y,
      .width = 25,
      .height = 25};

  // Rectangle boxCollision = {0}; // Collision rectangle

  SetTargetFPS(60);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);

  bool collision = false;

  while (!WindowShouldClose())
  {

    // Update
    // collision = CheckCollisionRecs(drawPlayer(&p1), drawEnemy(&e));
    printPlayerCords(&player);

    handlePlayerControl(&player);

    if (collision)
    {
      // DrawRectangleRec(boxCollision, LIME);

      // DrawText("COLLISION!", GetScreenWidth() / 2 - MeasureText("COLLISION!", 20) / 2, screenUpperLimit / 2 - 10, 20, BLACK);
    }

    // Draw
    BeginDrawing();

    ClearBackground(BLACK);

    drawPlayer(&player);

    // drawPlayer(&enemy);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
