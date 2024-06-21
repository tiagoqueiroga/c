#ifndef _BALL_H
#define _BALL_H

#include <raylib.h>
#include <stdlib.h>
#include "game.h"

typedef struct Ball
{
    Vector2 pos;
    float width;
    float radius;
    float velocity;
    Color color;
} Ball;

Ball *CreateBall(float pos_x, float pos_y, float radius);
void DestroyBall(Ball *Ball);
void DrawBall(Ball *p);
void PrintBallCords(Ball *p);
void UpdateBall(Ball *p);

#endif