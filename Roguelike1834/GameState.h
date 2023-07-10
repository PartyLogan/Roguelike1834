#pragma once
#include "raylib.h"
#include <memory>
#include <vector>
#include "Actor.h"
#include "Map.h"
#include "Renderer.h"

class GameState
{
public:
	// Renderer for the game
	std::shared_ptr<Renderer> renderer;
	// Game width in tiles
	int width = 80;
	int height = 50;
	// Tile size for the game
	int tileSize = 16;
	// Tilemap for the game
	Texture tileMap;
	// Actors
	std::vector<std::shared_ptr<Actor>> actors;
	int currentActorIndex = 0;
	// Player
	Actor player;
	// Map
	std::shared_ptr<Map> map;
	// Seed
	int currentSeed = 0;

	GameState(std::shared_ptr<Renderer> renderer, int width, int height, int tileSize, Texture tileMap);
	
	void SetCurrentSeed(int seed);
	void DrawMap();
};

