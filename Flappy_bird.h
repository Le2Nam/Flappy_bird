#ifndef FLAPPYBIRD_H_
#define FLAPPYBIRD_H_

#include "Texture.h"

// Starts up SDL and creates window
bool init();

// Frees media and shuts down SDL
void close();

// Loads media
void loadMedia();

// Check collision between bird and pipe
bool check_collision(int pos_bird_y, int pos_pipe_x[], int pos_pipe_y[], int &score, int &num_pipe, string &s_score, Mix_Chunk *mScore);

// Play again
bool check_play();

// Set random pipes 's position
void set_pos_pipe(int pos_pipe_x[], int pos_pipe_y[]);

// The window we'll be rendering to
static SDL_Window *gWindow = NULL;

// The window renderer
static SDL_Renderer *gRenderer = NULL;

// Screen dimension constants
static const int SCREEN_WIDTH = 288;
static const int SCREEN_HEIGHT = 512;

// Declare variable
static int num_pipe = 0, score = 0, max_score = 0, n = 1;
static string s_score = to_string(score), s_max_score = to_string(max_score);
static bool quit = false, die = false;
static SDL_Event e;
static int frame = 0, acc_frame = 1, pos_pipe_x[3], pos_pipe_y[3];
static double speed = 0, speed_pipe = 1, acc = 0.05, degrees = 0, jump = 2.5;
static double pos_bird_y = (SCREEN_HEIGHT) / 3;
static LTexture gBackground, pipe_down0, pipe_down1, pipe_down2, pipe_up0, pipe_up1, pipe_up2, game_over, play;
static LTexture bird[3];
static LTexture gScore, gMax_Score, ms;
static TTF_Font *Font1, *Font2;
static SDL_Color textColor = {255, 255, 255};
static Mix_Music *mBackground = NULL;
static Mix_Chunk *mFly = NULL;
static Mix_Chunk *mScore = NULL;
static Mix_Chunk *mDie = NULL;

#endif
