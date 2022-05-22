#include "Flappy_bird.h"

bool check_play()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x >= (SCREEN_WIDTH / 2 - 52) && x <= (SCREEN_WIDTH / 2 + 48) && y >= (SCREEN_HEIGHT / 2 - 18) && y <= (SCREEN_HEIGHT / 2 + 30))
        return true;
    return false;
}

bool check_collision(int pos_bird_y, int pos_pipe_x[], int pos_pipe_y[], int &score, int &num_pipe, string &s_score, Mix_Chunk *mScore)
{
    if (pos_pipe_x[num_pipe] + 52 < SCREEN_WIDTH / 8)
    {

        score++;
        num_pipe = (num_pipe + 1) % 3;
        s_score = to_string(score);
        Mix_PlayChannel(-1, mScore, 0);
    }
    if ((SCREEN_WIDTH / 8 + 35) < pos_pipe_x[num_pipe])
        return false;
    else if ((SCREEN_WIDTH / 8 + 5) > (pos_pipe_x[num_pipe] + 50) && (SCREEN_WIDTH / 8 + 45) < (pos_pipe_x[num_pipe] + 200))
        return false;
    else if ((pos_bird_y + 14) > (pos_pipe_y[num_pipe] + 320) && (pos_bird_y + 35) < (pos_pipe_y[num_pipe] + 440))
        return false;
    else
        return true;
}

void set_pos_pipe(int pos_pipe_x[], int pos_pipe_y[])
{
    for (int i = 0; i < 3; i++)
    {
        pos_pipe_x[i] = 170 + 200 * i;
        pos_pipe_y[i] = rand() % (240) - 240;
    }
}