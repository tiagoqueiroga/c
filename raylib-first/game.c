#include <raylib.h>



int main() {

  float posX = 0;
  float posY = 0;

  float velocity = 100;

  SetTargetFPS(60);

  InitWindow(800, 450, "Title");

  while (!WindowShouldClose())
  {

      if(IsKeyPressed(KEY_RIGHT))
      {
        posX += GetFrameTime() + velocity;
      }

      if(IsKeyPressed(KEY_LEFT))
      {
        posX += GetFrameTime() - velocity;
      }

      if(IsKeyPressed(KEY_UP))
      {
        posY += GetFrameTime() - velocity;
      }      

      if(IsKeyPressed(KEY_DOWN))
      {
        posY += GetFrameTime() + velocity;
      }      


      BeginDrawing();
      
      ClearBackground(RAYWHITE);

        DrawRectangle(posX,posY,100,100,BLUE);
      
      EndDrawing();
  }

  CloseWindow();

  return 0;
}
