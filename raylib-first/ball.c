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
    b->velocity.x = BALL_INIT_POS_X;
    b->velocity.y = BALL_INIT_POS_Y;

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

void RespawnBall(Ball *b)
{
    b->pos.x = BALL_INIT_WIDTH;
    b->pos.y = BALL_INIT_HEIGHT;
}

bool CheckBallCollision(Ball *b, Player *p)
{
    // Check collision with p boundaries
    if (b->pos.x + b->radius > p->pos.x && b->pos.x - b->radius < p->pos.x + p->width &&
        b->pos.y + b->radius > p->pos.y && b->pos.y - b->radius < p->pos.y + p->height)
    {
        return true; // Collision detected
    }
    return false; // No collision
}

void UpdateBall(Ball *b, Player *p)
{
    b->pos.y += b->velocity.y;
    b->pos.x += b->velocity.x;

    if (CheckBallCollision(b, p))
    {
        // b->velocity.x *= -1.0f;
        b->velocity.y *= -1.0f;
    }

    // Bouncing walls
    if ((b->pos.x >= (GetScreenWidth() - b->radius)) || (b->pos.x <= b->radius))
        b->velocity.x *= -1.0f;

    if ((b->pos.y >= (GetScreenHeight() - b->radius)) || (b->pos.y <= b->radius))
        b->velocity.y *= -1.0f;

    // if (b->pos.y > SCREEN_HEIGHT)
    //     b->pos.y = BALL_INIT_HEIGHT;

    // b->pos.y += b->velocity;
}
