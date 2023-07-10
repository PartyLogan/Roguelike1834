#include "GameState.h"
#include <iostream>

GameState::GameState(std::shared_ptr<Renderer> renderer, int width, int height, int tileSize, Texture tileMap)
{
	this->renderer = renderer;
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;
	this->tileMap = tileMap;
	actors = std::vector<std::shared_ptr<Actor>>();
	map = std::make_shared<Map>(width, height);
	currentSeed = std::time(NULL);
	SetCurrentSeed(currentSeed);
}

void GameState::DrawMap()
{
	renderer.get()->DrawMap(0, 0, tileSize, tileMap, map);
}

void GameState::SetCurrentSeed(int seed) {
	currentSeed = seed;
	SetRandomSeed(seed);
	std::cout << "Random seed set to: " << seed << std::endl;
}