#pragma once
#include "Tile.h"
#include <vector>
#include <memory>

class Map
{
public:

	int width = 80;
	int height = 50;
	std::vector<std::vector<std::shared_ptr<Tile>>> tiles;

	Map(int width, int height);

	Vector2 GetPlayerStart() {
		return Vector2{ float(playerStartX), float(playerStartY) };
	}

	Vector2 GenerateMap();
	std::shared_ptr<Tile> GetTile(int x, int y);
	void SetTile(int x, int y, std::shared_ptr<Tile> tile);
	bool InBounds(int x, int y);
private:
	int playerStartX = 0;
	int playerStartY = 0;
	int roomMinSize = 6;
	int roomMaxSize = 15;
	int maxRooms = 30;
	int minRooms = 6;

	void FloorRoom(Rectangle room);
	void TunnelBetweenRooms(Rectangle room1, Rectangle room2);
	void TunnelBetweenRooms(int startX, int startY, int endX, int endY);
	Rectangle GetGrownRoom(Rectangle room);

};

