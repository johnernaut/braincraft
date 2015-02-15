#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"

Sprite::Sprite(SDL_Renderer *ren, std::string imagePath, int x, int y, int w, int h)
{
    sRenderer = ren;
    SDL_Surface *img = IMG_Load(imagePath.c_str());

    pSprite = SDL_CreateTextureFromSurface(sRenderer, img);
    SDL_FreeSurface(img);
    if (pSprite == nullptr) {
        SDL_Log("Failed to create sprite error: %s", SDL_GetError());
    }

    // Set cropping properties
    sCrop.x = x;
    sCrop.y = y;
    sCrop.w = w;
    sCrop.h = h;

    // Set image size properties
    SDL_QueryTexture(pSprite, NULL, NULL, &sRect.w, &sRect.h);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(pSprite);
}

void Sprite::Draw()
{
    SDL_RenderCopy(sRenderer, pSprite, &sCrop, &sRect);
}

int Sprite::GetX()
{
    return sRect.x;
}

int Sprite::GetY()
{
    return sRect.y;
}

void Sprite::SetX(int x)
{
    sRect.x = x;
}

void Sprite::SetY(int y)
{
    sRect.y = y;
}

void Sprite::SetOrigin(int x, int y)
{
    sRect.x = x;
    sRect.y = y;
}
