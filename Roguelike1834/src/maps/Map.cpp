#include "Map.h"
#include <memory>
#include <iostream>
#include "../Util.h"

Map::Map(int width, int height)
{
	this->width = width;
	this->height = height;
	tiles = std::vector<std::vector<std::shared_ptr<Tile>>>();
	tiles.resize(width, std::vector<std::shared_ptr<Tile>>(height));

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			tiles[x][y] = Tile::MakeForestWall();
		}
	}
}

Vector2 Map::GenerateMap()
{
	std::vector<Rectangle> rooms = std::vector<Rectangle>();
	int roomsToMake = GetRandomValue(minRooms, maxRooms);
	int roomCount = 0;
	int intersectCount = 0;
	int maxIntersects = 50;

	std::cout << "Creating rooms: " << roomsToMake << std::endl;

	while(roomCount < roomsToMake) {
		int roomWidth = GetRandomValue(roomMinSize, roomMaxSize);
		int roomHeight = GetRandomValue(roomMinSize, roomMaxSize);

		int x = GetRandomValue(1, width - roomWidth - 1);
		int y = GetRandomValue(1, height - roomHeight - 1);

		if (!InBounds(x, y) || !InBounds(x + roomWidth, y + roomHeight)) {
			continue;
		}

		Rectangle newRoom = Util::MakeRectangle(x, y, roomWidth, roomHeight);

		bool intersects = false;
		for (int r = 0; r < rooms.size(); r++) {
			if (CheckCollisionRecs(GetGrownRoom(newRoom), GetGrownRoom(rooms[r]))) {
				intersects = true;
				if (roomCount > minRooms) {
					intersectCount++;
				}
				break;
			}
		}

		if (intersects) {
			if (intersectCount > maxIntersects && roomCount > minRooms) {
				std::cout << "Room min count met. Too many intersections, breaking out of room generation " << intersectCount << std::endl;
				break;
			}
			continue;
		}

		FloorRoom(newRoom);

		if (rooms.size() == 0) {
			std::cout << "First Room, setting player spawn" << std::endl;
			playerStartX = newRoom.x + (newRoom.width / 2);
			playerStartY = newRoom.y + (newRoom.height / 2);
		}
		else {
			int rng = GetRandomValue(0, 1);
			Rectangle prevRoom = rooms[rooms.size() - 1];
			int prevRoomX = prevRoom.x + (prevRoom.width / 2);
			int prevRoomY = prevRoom.y + (prevRoom.height / 2);
			int newRoomX = newRoom.x + (newRoom.width / 2);
			int newRoomY = newRoom.y + (newRoom.height / 2);
			if (rng == 0) {
				std::cout << "Tunneling rng 0" << std::endl;
				TunnelBetweenRooms(prevRoomX, newRoomY, newRoomX, newRoomY);
				TunnelBetweenRooms(prevRoomX, prevRoomY, prevRoomX, newRoomY);
			}
			else {
				std::cout << "Tunneling rng 1" << std::endl;
				TunnelBetweenRooms(prevRoomX, prevRoomY, newRoomX, prevRoomY);
				TunnelBetweenRooms(newRoomX, prevRoomY, newRoomX, newRoomY);
			}
		}
		roomCount++;
		std::cout << "Room " << roomCount << " generated." << std::endl;
		rooms.push_back(newRoom);
	}
	std::cout << "Rooms generated: " << roomCount << std::endl;
	return Util::MakeVector2(playerStartX, playerStartY);
}

std::shared_ptr<Tile> Map::GetTile(int x, int y)
{
	if (InBounds(x, y)) {
		return tiles[x][y];
	}
	return nullptr;
}

void Map::SetTile(int x, int y, std::shared_ptr<Tile> tile)
{
	if (InBounds(x, y)) {
		tiles[x][y] = tile;
	}
}

bool Map::InBounds(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height) {
		return true;
	}
	return false;
}

void Map::FloorRoom(Rectangle room)
{
	int xMin = std::min(room.x, room.x + room.width);
	int yMin = std::min(room.y, room.y + room.height);
	int xMax = std::max(room.x, room.x + room.width);
	int yMax = std::max(room.y, room.y + room.height);

	for (int x = xMin; x < xMax; x++) {
		for (int y = yMin; y < yMax; y++) {
			tiles[x][y] = Tile::MakeForestFloor();
		}
	}
}

void Map::TunnelBetweenRooms(int startX, int startY, int endX, int endY) {
	if (endX > startX) {
		while (startX != endX) {
			startX++;
			tiles[startX][startY] = Tile::MakeForestFloor();
		}
	}
	else {
		while (startX != endX) {
			startX--;
			tiles[startX][startY] = Tile::MakeForestFloor();
		}
	}
	if (endY > startY) {
		while (startY != endY) {
			startY++;
			tiles[startX][startY] = Tile::MakeForestFloor();
		}
	}
	else {
		while (startY != endY) {
			startY--;
			tiles[startX][startY] = Tile::MakeForestFloor();
		}
	}
}

void Map::TunnelBetweenRooms(Rectangle room1, Rectangle room2)
{
	int x1 = room1.x + (room1.width / 2);
	int y1 = room1.y + (room1.height / 2);
	int x2 = room2.x + (room2.width / 2);
	int y2 = room2.y + (room2.height / 2);

	while (x1 != x2) {
		if (x1 < x2) {
			x1++;
		}
		else {
			x1--;
		}
		tiles[x1][y1] = Tile::MakeForestFloor();
	}
	while (y1 != y2) {
		if (y1 < y2) {
			y1++;
		}
		else {
			y1--;
		}
		tiles[x1][y1] = Tile::MakeForestFloor();
	}
}

Rectangle Map::GetGrownRoom(Rectangle room)
{
	int outterX1 = room.x - 1;
	int outterY1 = room.y - 1;
	int outterX2 = room.width + 1;
	int outterY2 = room.height + 1;
	return Util::MakeRectangle(outterX1, outterY1, outterX2, outterY2);
}