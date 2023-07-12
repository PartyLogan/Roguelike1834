#pragma once
#include <memory>
#include "../maps/Map.h"
#include "../entities/Actor.h"

class Renderer
{
public:
	virtual void DrawTile();
	virtual void DrawMap(int x, int y, int tileSize, Texture tileMap, std::shared_ptr<Map> map, std::shared_ptr<Actor> player);
	virtual void DrawActors(int x, int y, int tileSize, Texture tileMap, std::vector<std::shared_ptr<Actor>> actors, std::shared_ptr<Actor> player);
	virtual void DrawSprite(int x, int y, Texture tileMap, Rectangle source, Vector2 pos, int tileSize, Color fg, Color bg);
	virtual void DrawEntity();
};

