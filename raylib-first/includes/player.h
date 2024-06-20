#ifndef _PLAYER_H
#define _PLAYER_H

#include <raylib.h>
#include <stdlib.h>
#include "game.h"

#define PLAYER_INIT_WIDTH 100
#define PLAYER_INIT_HEIGHT 20
#define PLAYER_X_POSITION SCREEN_WIDTH / 2
#define PLAYER_Y_POSITION 400

typedef struct Player
{
    Vector2 pos;
    float width;
    float height;
    Color color;
} Player;

Player *CreatePlayer(float pos_x, float pos_y);
void DestroyPlayer(Player *player);
void DrawPlayer(Player *p);
void PrintPlayerCords(Player *p);
void HandlePlayerControl(Player *p);

#endif