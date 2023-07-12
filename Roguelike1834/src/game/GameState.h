#pragma once
#include "raylib.h"
#include <memory>
#include <vector>
#include "Renderer.h"
#include "../entities/Actor.h"

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
	std::shared_ptr<Actor> player;
	Action* playerActionBuffer = nullptr;
	// Map
	std::shared_ptr<Map> map;
	// Seed
	int currentSeed = 0;
	// Turn Management
	int currentTurn = 0;
	bool completedTurn = false;

	GameState(std::shared_ptr<Renderer> renderer, int width, int height, int tileSize, Texture tileMap);
	
	void SetCurrentSeed(int seed);
	void DrawMap();
	void DrawActors();
	void Update();
	void AddActor(std::shared_ptr<Actor> actor);
	void SetPlayer(std::shared_ptr<Actor> actor);
private:
	void ProcessTurn();
	void NextActor();
	bool GetPlayerCommand();
	void SetPlayerActionBuffer(Action* action);
};

