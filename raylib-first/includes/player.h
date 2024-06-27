#ifndef _PLAYER_H
#define _PLAYER_H

#include <raylib.h>
#include <stdlib.h>
#include "game.h"

typedef struct Player
{
    Vector2 pos;
    int width;
    int height;
    Color color;
} Player;

Player *CreatePlayer(float pos_x, float pos_y);
void DestroyPlayer(Player *player);
void DrawPlayer(Player *p);
void PrintPlayerCords(Player *p);
void HandlePlayerControl(Player *p);

#endif