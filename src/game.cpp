#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"

Game::Game(int pWidth, int pHeight)
{
    int grassDimension = 48;
    tilesX = 25;
    tilesY = 20;
    quitGame = false;
    screenWidth = pWidth;
    screenHeight = pHeight;

    Window = SDL_CreateWindow("Braincraft", 
                                    100, 100, 
                                    pWidth, pHeight,
                                    SDL_WINDOW_SHOWN);
    if (Window == nullptr) {
        SDL_Log("SDL_Window error: %s", SDL_GetError());
        quitGame = true;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        SDL_Log("IMG_INIT_PNG error: %s", SDL_GetError());
        quitGame = true;
    }

    Renderer = SDL_CreateRenderer(Window, -1,
                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Renderer == nullptr) {
        SDL_Log("SDL_Renderer error: %s", SDL_GetError());
        quitGame = true;
    }

    mainEvent = new SDL_Event();
    player = new Sprite(Renderer, "resources/player.png",
                                            0, 0,
                                            16, 16);
    player->SetOrigin(screenWidth / 2, screenHeight / 2);

    for (int i = 0; i < tilesX; i++) {
        for (int j = 0; j < tilesY; j++) {
            bgTiles[i][j] = new Sprite(Renderer, "resources/grass-tile.png",
                                            0, 0,
                                            grassDimension, grassDimension);
            bgTiles[i][j]->SetOrigin(grassDimension * i, grassDimension * j);
        }
    }
}

Game::~Game()
{
    delete mainEvent;
    for (int i = 0; i < tilesX; i++) {
        for (int j = 0; j < tilesY; j++) {
            delete bgTiles[i][j];
        }
    }
    delete player;
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void Game::gameLoop()
{
    while (!quitGame) 
    {
        while (SDL_PollEvent(mainEvent))
        {
            if (mainEvent->type == SDL_QUIT) {
                quitGame = true;
            }
            switch (mainEvent->type)
            {
                case SDL_KEYDOWN:
                    switch (mainEvent->key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            quitGame = true;
                            break;
                        case SDLK_w:
                            player->SetY(player->GetY() - 5);
                            break;
                        case SDLK_s:
                            player->SetY(player->GetY() + 5);
                            break;
                        case SDLK_d:
                            player->SetX(player->GetX() + 5);
                            break;
                        case SDLK_a:
                            player->SetX(player->GetX() - 5);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        SDL_RenderClear(Renderer);

        renderBackground();
        player->Draw();

        SDL_RenderPresent(Renderer);
    }
}

void Game::renderBackground()
{
    for (int i = 0; i < tilesX; i++) {
        for (int j = 0; j < tilesY; j++) {
            bgTiles[i][j]->Draw();
        }
    }
}
