// Roguelike1834.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"
#include "game/GameState.h"
#include "game/RaylibRenderer.h"
#include "entities/Actor.h"
#include "maps/Tile.h"

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int tileSize = 16;
    
    InitWindow(screenWidth, screenHeight, "Roguelike");
    //SetTargetFPS(60);

    // Load texture and setup renderer
    auto texture = LoadTexture("assets/monochrome-transparent_packed.png");
    std::shared_ptr<RaylibRenderer> renderer = std::make_shared<RaylibRenderer>();

    // Setup gamestate
    std::shared_ptr<GameState> gamestate = std::make_shared<GameState>(renderer, screenWidth / tileSize, screenHeight / tileSize, tileSize, texture);

    // Create map
    gamestate.get()->map.get()->GenerateMap();

    // Make player
    std::shared_ptr<Actor> player = std::make_shared<Actor>(0, 0, YELLOW, ORANGE, "Player", Tile::ActorTile::Player);
    gamestate.get()->SetPlayer(player);


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        gamestate.get()->Update();
        gamestate.get()->DrawMap();

        DrawFPS(20, 20);
        EndDrawing();
    }
    
    CloseWindow();

}

