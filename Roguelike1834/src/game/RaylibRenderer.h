#pragma once
#include "Renderer.h"
class RaylibRenderer :
    public Renderer
{
public:
    RaylibRenderer();
    void DrawTile();
    void DrawMap(int x, int y, int tileSize, Texture tileMap, std::shared_ptr<Map> map, std::shared_ptr<Actor> player);
    void DrawActors(int x, int y, int tileSize, Texture tileMap, std::vector<std::shared_ptr<Actor>> actors, std::shared_ptr<Actor> player);
    void DrawEntity();
};

