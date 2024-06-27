#ifndef _GAME_H
#define _GAME_H

#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "player.h"
#include "ball.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define SCREEN_WIDTH_CENTER (SCREEN_WIDTH / 2)
#define SCREEN_HEIGHT_CENTER (SCREEN_HEIGHT / 2)

#define FPS 60
#define GAME_PAUSED_TEXT "Game Paused"
#define GAME_PAUSED_FONT_SIZE 20

// Player
#define PLAYER_INIT_WIDTH 100
#define PLAYER_INIT_HEIGHT 20
#define PLAYER_INIT_POS_X SCREEN_WIDTH_CENTER - PLAYER_INIT_WIDTH / 2
#define PLAYER_INIT_POS_Y 400

// Ball
#define BALL_INIT_HEIGHT 100
#define BALL_INIT_WIDTH 50
#define BALL_INIT_RADIUS 50
#define BALL_INIT_COLOR RED
#define BALL_INIT_POS_X 5.0f;
#define BALL_INIT_POS_Y 4.0f;

#define GAME_TITLE "My shitty game"
#define VELOCITY 10
#define SCREEN_BOUND_X (SCREEN_WIDTH - PLAYER_INIT_WIDTH)
#define MAX_ENTITIES = 10

#endif