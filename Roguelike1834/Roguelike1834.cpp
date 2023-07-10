// Roguelike1834.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"
#include "Tile.h"
#include "GameState.h"
#include "RaylibRenderer.h"

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

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        gamestate.get()->DrawMap();

        DrawFPS(20, 20);
        EndDrawing();
    }
    
    CloseWindow();

}

