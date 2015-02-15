#ifndef _SPRITE_H
#define _SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {
    public:
        ~Sprite();
        void Draw();
        void SetOrigin(int x, int y);
        void SetY(int y);
        void SetX(int x);
        int GetX();
        int GetY();
        Sprite(SDL_Renderer *ren, std::string imagePath, int x, int y, int w, int h);

    private:
        SDL_Rect sRect;
        SDL_Rect sCrop;
        SDL_Renderer *sRenderer;
        SDL_Texture *pSprite;
};

#endif
