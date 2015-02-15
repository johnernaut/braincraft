#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"

class Game
{
    public:
        Game(int sWidth, int sHeight);
        ~Game();
        void gameLoop();

    private:
        int screenWidth, screenHeight, tilesX, tilesY;
        bool quitGame;
        Sprite *bgTiles[25][20];
        Sprite *player;

        void renderBackground();

        SDL_Event *mainEvent;
        SDL_Window *Window;
        SDL_Renderer *Renderer;
};

#endif
