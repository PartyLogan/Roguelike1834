// Roguelike1834.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"
#include "game/GameState.h"
#include "game/RaylibRenderer.h"
#include "entities/Actor.h"
#include "maps/Tile.h"
#include "Palette.h"

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int tileSize = 16;
    
    InitWindow(screenWidth, screenHeight, "Roguelike");

    // Load texture and setup renderer
    auto texture = LoadTexture("assets/monochrome-transparent_packed.png");
    std::shared_ptr<RaylibRenderer> renderer = std::make_shared<RaylibRenderer>();

    // Setup gamestate
    std::shared_ptr<GameState> gamestate = std::make_shared<GameState>(renderer, screenWidth / tileSize, screenHeight / tileSize, tileSize, texture);

    // Create map
    Vector2 playerStart = gamestate.get()->map.get()->GenerateMap();

    // Make player
    std::shared_ptr<Actor> player = std::make_shared<Actor>(playerStart.x, playerStart.y, P_PLAYER, P_BLACK, "Player", Tile::ActorTile::Player);

    gamestate.get()->SetPlayer(player);

    gamestate.get()->SetFOVSizes(gamestate.get()->width, gamestate.get()->height);
    gamestate.get()->UpdateFOVs();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        gamestate.get()->Update();
        gamestate.get()->DrawMap();
        gamestate.get()->DrawActors();

        DrawFPS(20, 20);
        EndDrawing();
    }
    
    CloseWindow();

}

