#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define GAME_TITLE "Raylib game"

typedef struct
{
  float posX;
  float posY;
  float width;
  float height;
  float velocity;
  Color color;
} player;

typedef struct
{
  float posX;
  float posY;
  float width;
  float height;
  float velocity;
  Color color;
} enemy;

int generateRandomPos(int max)
{
  int pos;
  srand(time(0));
  pos = rand() % max + 1;
  return pos;
}

void drawPlayer(player *p)
{
  DrawRectangle(p->posX, p->posY, p->width, p->height, p->color);
}

void drawEnemy(enemy *e)
{
  DrawCircle(e->posX, e->posY, 20, e->color);
}

void printPlayerCords(player *p)
{
  printf("posX:(%f) posY:(%f)\n", p->posX, p->posY);
}

void handlePlayerControl(player *p)
{

  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_L))
  {

    if (p->posX < (SCREEN_WIDTH - p->width))
      p->posX += GetFrameTime() + p->velocity;
  }

  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_H))
  {
    if (p->posX > 0)
      p->posX += GetFrameTime() - p->velocity;
  }

  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_K))
  {
    if (p->posY > 0)
      p->posY += GetFrameTime() - p->velocity;
  }

  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_J))
  {
    if (p->posY < (SCREEN_HEIGHT - p->height))
      p->posY += GetFrameTime() + p->velocity;
  }
}

int main()
{
  player p1 = {
      .posX = generateRandomPos(SCREEN_WIDTH),
      .posY = generateRandomPos(SCREEN_HEIGHT),
      .width = 50,
      .height = 50,
      .velocity = 5,
      .color = BLUE};

  enemy e = {
      .posX = generateRandomPos(SCREEN_WIDTH),
      .posY = generateRandomPos(SCREEN_HEIGHT),
      .height = 20,
      .width = 20,
      .color = RED};

  SetTargetFPS(60);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);

  while (!WindowShouldClose())
  {

    BeginDrawing();

    printPlayerCords(&p1);

    ClearBackground(RAYWHITE);

    handlePlayerControl(&p1);

    drawPlayer(&p1);

    drawEnemy(&e);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
