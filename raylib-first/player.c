#include "includes/player.h"

Player *CreatePlayer(float pos_x, float pos_y)
{
    Player *p = malloc(sizeof(Player));

    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Vector2 pos = {.x = pos_x, .y = pos_y};

    p->pos = pos;
    p->width = PLAYER_INIT_WIDTH;
    p->height = PLAYER_INIT_HEIGHT;
    p->color = WHITE;

    return p;
}

void DestroyPlayer(Player *player)
{
    free(player);
}

void DrawPlayer(Player *p)
{
    DrawRectangle(p->pos.x, p->pos.y, p->width, p->height, p->color);
}

void PrintPlayerCords(Player *p)
{
    printf("posX:(%f) posY:(%f)\n", p->pos.x, p->pos.y);
}

void HandlePlayerControl(Player *p)
{
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_L))
    {

        if (p->pos.x < SCREEN_BOUND_X)
            p->pos.x += GetFrameTime() + VELOCITY;
    }

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_H))
    {
        if (p->pos.x > 0)
            p->pos.x += GetFrameTime() - VELOCITY;
    }
}
