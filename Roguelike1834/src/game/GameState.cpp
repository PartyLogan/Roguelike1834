#include "GameState.h"
#include <iostream>
#include "../entities/Actor.h"
#include "../maps/Map.h"
#include "../actions/Action.h"
#include "../actions/ActionResult.h"

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

void GameState::Update()
{
	ProcessTurn();
}

void GameState::AddActor(std::shared_ptr<Actor> actor)
{
	actors.push_back(actor);
}

void GameState::SetPlayer(std::shared_ptr<Actor> actor)
{
	player = actor;
	AddActor(actor);
}

void GameState::ProcessTurn()
{
	std::cout << "New turn: " << currentTurn << std::endl;
	if (actors.size() < 1) return;
	std::shared_ptr<Actor> currentActor = actors[currentActorIndex];
	Action* action = currentActor.get()->GetAction();
	action->SetOwner(currentActor);

	while (true) {
		ActionResult result = action->Perform();
		if (result.succeeded) {
			std::cout << "Action succeeded" << std::endl;
			break;
		}
		else if(result.alternative == nullptr) {
			std::cout << "Action failed" << std::endl;
			break;
		}
		std::cout << "Alternative action" << std::endl;
		delete action;
		action = result.alternative;
		break;
	}
	delete action;
	NewTurn();
}

void GameState::NewTurn()
{
	std::cout << "Next actor: " << actors[currentActorIndex].get()->name << std::endl;
	currentActorIndex++;
	if (currentActorIndex >= actors.size()) {
		currentActorIndex = 0;
		currentTurn++;
	}
}

void GameState::SetCurrentSeed(int seed) {
	currentSeed = seed;
	SetRandomSeed(seed);
	std::cout << "Random seed set to: " << seed << std::endl;
}