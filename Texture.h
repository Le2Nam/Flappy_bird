#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Cfuntion.h"

// Texture wrapper class
class LTexture
{
public:
    // Initializes variables
    LTexture();

    // Deallocates memory
    ~LTexture();

    // Loads image at specified path
    void loadFromFile(string path, SDL_Renderer *gRenderer);

    // Creates image from font string
    bool loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font *gFont, SDL_Renderer *gRenderer);

    // Deallocates texture
    void free();

    // Renders texture at given point
    void render(int x, int y, SDL_Renderer *gRenderer, SDL_Rect *clip = NULL, double angle = 0.0);

private:
    // The actual hardware texture
    SDL_Texture *mTexture;

    // Image dimensions
    int mWidth;
    int mHeight;
};

#endif