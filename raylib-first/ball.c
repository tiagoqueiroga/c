#include "includes/ball.h"

Ball *CreateBall(float pos_x, float pos_y, float radius)
{
    Ball *b = malloc(sizeof(Ball));

    if (b == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Vector2 pos = {.x = SCREEN_WIDTH / 2, .y = pos_y};

    b->pos = pos;
    b->color = BALL_INIT_COLOR;
    b->radius = radius;
    b->velocity = BALL_INIT_VELOCITY;

    return b;
}
void DestroyBall(Ball *b)
{
    free(b);
}
void DrawBall(Ball *b)
{
    DrawCircle(b->pos.x, b->pos.y, b->radius, b->color);
}
void PrintBallCords(Ball *b)
{
    printf("Ball posX:(%f) posY:(%f)\n", b->pos.x, b->pos.y);
}

void UpdateBall(Ball *b)
{
    if (b->pos.y > SCREEN_HEIGHT)
        b->pos.y = BALL_INIT_HEIGHT;

    b->pos.y += b->velocity;
}
