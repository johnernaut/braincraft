#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    Game *game = new Game(1024, 768);
    game->gameLoop();

    return 0;
}
