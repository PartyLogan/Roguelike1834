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
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int tileSize = 16;
    const int gameScreenWidth = 1280;
    const int gameScreenHeight = 720;
    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Roguelike");
    SetWindowMinSize(1280, 720);

    RenderTexture2D target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    Camera2D camera = { 0 };
    camera.offset = Vector2{ gameScreenWidth / 2 - tileSize/2, gameScreenHeight / 2 - tileSize/2 };
    camera.zoom = 1.0f;
    camera.rotation = 0.0f;

    // Load texture and setup renderer
    auto texture = LoadTexture("assets/monochrome-transparent_packed.png");
    std::shared_ptr<RaylibRenderer> renderer = std::make_shared<RaylibRenderer>();

    // Setup gamestate
    std::shared_ptr<GameState> gamestate = std::make_shared<GameState>(renderer, screenWidth / tileSize, screenHeight / tileSize, tileSize, texture);

    // Create map
    Vector2 playerStart = gamestate.get()->map.get()->GenerateMap();
    camera.target = playerStart;

    // Make player
    std::shared_ptr<Actor> player = std::make_shared<Actor>(playerStart.x, playerStart.y, P_PLAYER, P_BLACK, "Player", Tile::ActorTile::Player);

    gamestate.get()->SetPlayer(player);

    gamestate.get()->SetFOVSizes(gamestate.get()->width, gamestate.get()->height);
    gamestate.get()->UpdateFOVs();

    while (!WindowShouldClose())
    {
        float scale = std::round(std::min((float)GetScreenWidth() / gameScreenWidth, (float)GetScreenHeight() / gameScreenHeight));

        gamestate.get()->Update();
        camera.target = Vector2{ (float)gamestate.get()->player.get()->x * tileSize, (float)gamestate.get()->player.get()->y * tileSize };
        
        BeginTextureMode(target);
            BeginMode2D(camera);
                ClearBackground(BLACK);
                gamestate.get()->DrawMap();
                gamestate.get()->DrawActors();
            EndMode2D();
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);

            DrawTexturePro(target.texture, Rectangle{0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                Rectangle{(GetScreenWidth() - ((float)gameScreenWidth * scale)) * 0.5f, (GetScreenHeight() - ((float)gameScreenHeight * scale)) * 0.5f,
                    (float)gameScreenWidth* scale, (float)gameScreenHeight* scale}, Vector2{ 0.0f, 0.0f }, 0.0f, WHITE);
           
            DrawFPS(20, 20);

        EndDrawing();
    }
    
    CloseWindow();

}

