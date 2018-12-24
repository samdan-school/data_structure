#ifndef O_X_CONSTANT_H
#define O_X_CONSTANT_H

#include <irrKlang.h>
#include <string>

// Board Constants
#define BOARD_WIDTH 600
#define BOARD_HEIGHT 600
#define LINE_NUMBER 20
#define ANIMATION_HEIGHT_LINE (LINE_NUMBER / 2)

unsigned int texture_menu_bg;
unsigned int texture_option1_bg;
unsigned int texture_option2_bg;
unsigned int texture_win_circle;
unsigned int texture_win_cross;

int game_state = 1;

const char* SOUND_INTRO = "./audio/intro.ogg";
const char* SOUND_BATTLE = "./audio/battle.S3M";
const char* SOUND_WIN = "./audio/win.wav";

const float RED[3] = {1, 0, 0};
const float BLUE[3] = {0, 1, 0};
const float GREEN[3] = {0, 0, 1};
const float BLACK[3] = {0, 0, 0};

// render_string(BLACK, 220, 275, "GAME START!");
// render_string(BLACK, 203, 200, "EXIT THE GAME!");

const int POSITION_X_GAME_START = 200;
const int POSITION_Y_GAME_START = 260;
const int POSITION_X_GAME_EXIT = 205;
const int POSITION_Y_GAME_EXIT = 170;

const int POSITION_X_OPTION_RETURN = 247;
const int POSITION_Y_OPTION_RETURN = 285;
const int POSITION_X_OPTION_RESTART = 242;
const int POSITION_Y_OPTION_RESTART = 203;
const int POSITION_X_OPTION_EXIT = 275;
const int POSITION_Y_OPTION_EXIT = 124;

int animation_array[ANIMATION_HEIGHT_LINE][LINE_NUMBER];

// Win animation
// drop speed
const float drop_speed = 15;

irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();
// engine->play2D(SOUND_WIN, true);
// engine->drop();  // delete engine

#endif
