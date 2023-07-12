#pragma once
#include <memory>
#include "../maps/Map.h"
#include "../entities/Actor.h"

class Renderer
{
public:
	virtual void DrawTile();
	virtual void DrawMap(int x, int y, int tileSize, Texture tileMap, std::shared_ptr<Map> map);
	virtual void DrawActors(int x, int y, int tileSize, Texture tileMap, std::vector<std::shared_ptr<Actor>> actors);
	virtual void DrawEntity();
};

