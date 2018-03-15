#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define PI 3.14159265359f

#define SPLASH_STATE_SHOW_TIME 7.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/background.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/background.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/background.png"

#define GAME_TITLE_FILEPATH "Resources/res/title.png"

#define PLAY_BUTTON_FILEPLAY "Resources/res/PlayButton.png"

#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"

#define LAND_FILEPATH "Resources/res/Land.png"

#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"

#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.5f

#define BIRD_ANIMATION_DURATION 0.4f

#define GRAVITY 900.0f
#define FLYING_SPEED 350.0f

#define FLYING_DURATION 0.25f

enum GameStates
{
    eReady,
    ePlaying,
    eGameOver
};

#define FLASH_SPEED 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
