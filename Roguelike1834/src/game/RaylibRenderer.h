#pragma once
#include "Renderer.h"
class RaylibRenderer :
    public Renderer
{
public:
    RaylibRenderer();
    void DrawTile();
    void DrawMap(int x, int y, int tileSize, Texture tileMap, std::shared_ptr<Map> map);
    void DrawEntity();
};

