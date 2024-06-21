#ifndef _GAME_H
#define _GAME_H

#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 860
#define SCREEN_HEIGHT 440

#define GAME_TITLE "My shitty game"
#define VELOCITY 10
#define SCREEN_BOUND_X (SCREEN_WIDTH - PLAYER_INIT_WIDTH)
#define MAX_ENTITIES = 10

// Ball
#define BALL_INIT_HEIGHT 100
#define BALL_INIT_WIDTH 50
#define BALL_INIT_RADIUS 50
#define BALL_INIT_COLOR RED
#define BALL_INIT_VELOCITY 1

void SetSettings()
{
    SetTargetFPS(60);
}

void InitVars()
{
}

#endif