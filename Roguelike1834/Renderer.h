#pragma once
#include <memory>
#include "Map.h"
class Renderer
{
public:
	virtual void DrawTile();
	virtual void DrawMap(int x, int y, int tileSize, Texture tileMap, std::shared_ptr<Map> map);
	virtual void DrawEntity();
};

