#include "Flappy_bird.h"

int main(int argc, char *args[])
{
    srand(time(NULL));

    // Start up SDL and create window
    if (!init())
    {
        cout << "Failed to initialize!\n";
    }
    else
    {
        loadMedia();

        set_pos_pipe(pos_pipe_x, pos_pipe_y);

        while (!quit)
        {
            if (Mix_PlayingMusic() == 0)
            {
                Mix_PlayMusic(mBackground, -1);
            }

            max_score = max(max_score, score);
            s_max_score = to_string(max_score);

            // Clear screen
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(gRenderer);

            // Render background texture to screen
            gBackground.render(0, 0, gRenderer);

            degrees = (speed / 2) * 30;
            if (degrees >= 25)
            {
                degrees = 25;
            }

            speed += acc;
            if (!die && pos_bird_y >= -10)
                pos_bird_y += speed;

            // More difficult
            if (score >= (n * 10))
            {
                jump += 0.2;
                n++;
            }

            pipe_down0.render(pos_pipe_x[0], pos_pipe_y[0], gRenderer);
            pipe_down1.render(pos_pipe_x[1], pos_pipe_y[1], gRenderer);
            pipe_down2.render(pos_pipe_x[2], pos_pipe_y[2], gRenderer);
            pipe_up0.render(pos_pipe_x[0], pos_pipe_y[0] + 440, gRenderer);
            pipe_up1.render(pos_pipe_x[1], pos_pipe_y[1] + 440, gRenderer);
            pipe_up2.render(pos_pipe_x[2], pos_pipe_y[2] + 440, gRenderer);

            if (gScore.loadFromRenderedText(s_score, textColor, Font1, gRenderer))
                gScore.render(SCREEN_WIDTH / 2 - 12, 50, gRenderer);

            for (int i = 0; i < 3; i++)
            {
                pos_pipe_x[i] -= speed_pipe;
                if (pos_pipe_x[i] < -170)
                {
                    pos_pipe_x[i] = 430;
                    pos_pipe_y[i] = rand() % (240) - 240;
                }
            }

            bird[frame / 5].render(SCREEN_WIDTH / 8, pos_bird_y, gRenderer, NULL, degrees);
            frame += acc_frame;

            if (check_collision(pos_bird_y, pos_pipe_x, pos_pipe_y, score, num_pipe, s_score, mScore) || pos_bird_y > 515)
            {
                // stop pipe, bird, show "game_over", "play_again", "max_score", music "die"
                speed_pipe = 0, acc = 0, acc_frame = 0, jump = 0, die = true;
                if (Mix_PausedMusic() != 1)
                    Mix_PauseMusic();
                Mix_PlayChannel(-1, mDie, 0);
                mDie = NULL;
                game_over.render(SCREEN_WIDTH / 2 - 102, SCREEN_HEIGHT / 4, gRenderer);
                play.render(SCREEN_WIDTH / 2 - 58, SCREEN_HEIGHT / 2 - 20, gRenderer);
                if (gMax_Score.loadFromRenderedText(s_max_score, textColor, Font2, gRenderer))
                    gMax_Score.render(SCREEN_WIDTH - 18, 0, gRenderer);
                if (ms.loadFromRenderedText("Max Score: ", textColor, Font2, gRenderer))
                    ms.render(SCREEN_WIDTH - 98, 0, gRenderer);
            }

            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                if (e.type == SDL_KEYDOWN)
                {
                    if (e.key.keysym.sym == SDLK_SPACE || e.key.keysym.sym == SDLK_UP)
                    {
                        Mix_PlayChannel(-1, mFly, 0);
                        speed = -jump;
                    }
                }
                if (e.type == SDL_MOUSEBUTTONUP)
                {
                    if (check_play())
                    {
                        set_pos_pipe(pos_pipe_x, pos_pipe_y);
                        die = false, score = 0, speed = 0, speed_pipe = 1, acc = 0.05, acc_frame = 1, jump = 2.5;
                        pos_bird_y = (SCREEN_HEIGHT) / 3, num_pipe = 0, s_score = to_string(score);
                        Mix_PlayMusic(mBackground, -1);
                        mDie = Mix_LoadWAV("music/die.wav");
                    }
                }
            }

            // Update screen
            SDL_RenderPresent(gRenderer);

            // Cycle animation
            if (frame / 5 >= 3)
            {
                frame = 0;
            }
        }
    }

    close();

    return 0;
}

bool init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        cout << "SDL could not initialize! SDL Error: %s\n"
             << SDL_GetError();
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            cout << "Warning: Linear texture filtering not enabled!";
        }

        // Create window
        gWindow = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            cout << "Window could not be created! SDL Error: %s\n"
                 << SDL_GetError();
            success = false;
        }
        else
        {
            // Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                cout << "Renderer could not be created! SDL Error: %s\n"
                     << SDL_GetError();
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    cout << "SDL_image could not initialize! SDL_image Error: %s\n"
                         << IMG_GetError();
                    success = false;
                }

                // Initialize SDL_ttf
                if (TTF_Init() == -1)
                {
                    cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n"
                         << TTF_GetError();
                    success = false;
                }

                // Initialize SDL_mixer
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    cout << "SDL_mixer could not initialize! SDL_mixer Error: %s\n"
                         << Mix_GetError();
                    success = false;
                }
            }
        }
    }

    return success;
}

void loadMedia()
{
    gBackground.loadFromFile("image/img_bg.png", gRenderer);
    pipe_down0.loadFromFile("image/pipe_down.png", gRenderer);
    pipe_down1.loadFromFile("image/pipe_down.png", gRenderer);
    pipe_down2.loadFromFile("image/pipe_down.png", gRenderer);
    pipe_up0.loadFromFile("image/pipe_up.png", gRenderer);
    pipe_up1.loadFromFile("image/pipe_up.png", gRenderer);
    pipe_up2.loadFromFile("image/pipe_up.png", gRenderer);
    bird[0].loadFromFile("image/img_bird0.png", gRenderer);
    bird[1].loadFromFile("image/img_bird1.png", gRenderer);
    bird[2].loadFromFile("image/img_bird2.png", gRenderer);
    game_over.loadFromFile("image/img_gameOver.png", gRenderer);
    play.loadFromFile("image/btn_start.png", gRenderer);

    mBackground = Mix_LoadMUS("music/background.wav");
    mFly = Mix_LoadWAV("music/fly.wav");
    mDie = Mix_LoadWAV("music/die.wav");
    mScore = Mix_LoadWAV("music/score.wav");

    // Open the font
    Font1 = TTF_OpenFont("font/Veramobd.ttf", 28);
    Font2 = TTF_OpenFont("font/Veramobd.ttf", 14);
}

void close()
{
    gScore.free();
    gMax_Score.free();
    ms.free();

    // Free global font
    TTF_CloseFont(Font1);
    Font1 = NULL;
    TTF_CloseFont(Font2);
    Font2 = NULL;

    game_over.free();
    play.free();

    bird[0].free();
    bird[1].free();
    bird[2].free();
    gBackground.free();
    pipe_down0.free();
    pipe_down1.free();
    pipe_down2.free();
    pipe_up0.free();
    pipe_up1.free();
    pipe_up2.free();

    Mix_FreeChunk(mFly);
    Mix_FreeChunk(mDie);
    Mix_FreeChunk(mScore);
    mFly = NULL;
    mDie = NULL;
    mScore = NULL;

    Mix_FreeMusic(mBackground);
    mBackground = NULL;

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    // Quit SDL subsystems
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
