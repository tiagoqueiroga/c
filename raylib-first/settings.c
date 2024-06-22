#include <raylib.h>
#include "includes/game.h"
#include "includes/settings.h"

Config config = {
    .fps = 60,
    .paused = false,
    .showFps = true,
    .showBallCords = true,
    .showPlayerCords = true,
};

Config InitConfig()
{
    Config config = {
        .fps = FPS,
        .paused = false};

    SetTargetFPS(config.fps);

    return config;
}

bool GamePaused()
{
    return config.paused;
}

bool TogglePause()
{
    bool paused = !config.paused;
    config.paused = paused;

    return config.paused;
}

void DisplayPausedText()
{
    float posX = SCREEN_WIDTH_CENTER - (MeasureText(GAME_PAUSED_TEXT, GAME_PAUSED_FONT_SIZE)) / 2;
    float poxY = SCREEN_HEIGHT_CENTER - (GAME_PAUSED_FONT_SIZE) / 2;

    DrawText(GAME_PAUSED_TEXT, posX, poxY, GAME_PAUSED_FONT_SIZE, YELLOW);
}
