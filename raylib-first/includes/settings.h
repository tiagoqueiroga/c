#ifndef _SETTINGS_H
#define _SETTINGS_H

#include "game.h"

typedef struct Config
{
    int fps;
    bool paused;
    bool showFps;
    bool showBallCords;
    bool showPlayerCords;
} Config;

extern Config config;

Config InitConfig(void);

bool TogglePause(void);

bool GamePaused(void);

#endif