#include "GameState.h"
#include <iostream>
#include "../entities/Actor.h"
#include "../maps/Map.h"
#include "../actions/Action.h"
#include "../actions/BumpAction.h"
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
	renderer.get()->DrawMap(0, 0, tileSize, tileMap, map, player);
}

void GameState::DrawActors()
{
	renderer.get()->DrawActors(0, 0, tileSize, tileMap, actors, player);
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

void GameState::UpdateFOVs()
{
	for (int i = 0; i < actors.size(); i++) {
		actors[i].get()->fov.get()->UpdateFOV(actors[i].get()->x, actors[i].get()->y, map);
	}
}

void GameState::SetFOVSizes(int width, int height)
{
	for (int i = 0; i < actors.size(); i++) {
		actors[i].get()->fov.get()->Resize(width, height);
	}
}

void GameState::ProcessTurn()
{
	if (actors.size() < 1) return;
	std::shared_ptr<Actor> currentActor = actors[currentActorIndex];
	Action* action = nullptr;

	// Player input to get new command or use buffer
	if (currentActor == player) {
		if (playerActionBuffer != nullptr) {
			action = playerActionBuffer;
			playerActionBuffer = nullptr;
		}
		else {
			bool result = GetPlayerCommand();
			if (result == false) {
				return;
			}
			action = playerActionBuffer;
			playerActionBuffer = nullptr;
		}
	}
	else {
		action = currentActor.get()->GetAction();
	}

	// Try to do action
	action->SetOwner(currentActor);

	while (true) {
		ActionResult result = action->Perform();
		if (result.succeeded) {
			std::cout << "Action succeeded" << std::endl;
			completedTurn = true;
			break;
		}
		else if(result.alternative == nullptr) {
			std::cout << "Action failed" << std::endl;
			completedTurn = false;
			break;
		}
		std::cout << "Alternative action" << std::endl;
		completedTurn = false;
		delete action;
		action = result.alternative;
	}
	delete action;

	// Update FOV
	UpdateFOVs();

	if (completedTurn) {
		NextActor();
	}
}

void GameState::NextActor()
{
	std::cout << "Next actor: " << actors[currentActorIndex].get()->name << std::endl;
	completedTurn = false;
	currentActorIndex++;



	if (currentActorIndex >= actors.size()) {
		currentActorIndex = 0;
		currentTurn++;
		std::cout << "Next turn: " << currentTurn << std::endl;
	}
}

bool GameState::GetPlayerCommand()
{
	int key = GetKeyPressed();
	if (key == KEY_A) {
		SetPlayerActionBuffer(new BumpAction(map, -1, 0));
		return true;
	}
	if (key == KEY_D) {
		SetPlayerActionBuffer(new BumpAction(map, 1, 0));
		return true;
	}
	if (key == KEY_W) {
		SetPlayerActionBuffer(new BumpAction(map, 0, -1));
		return true;
	}
	if (key == KEY_S) {
		SetPlayerActionBuffer(new BumpAction(map, 0, 1));
		return true;
	}
	return false;
}

void GameState::SetPlayerActionBuffer(Action* action)
{
	if (playerActionBuffer != nullptr) {
		return;
	}
	playerActionBuffer = action;
}

void GameState::SetCurrentSeed(int seed) {
	currentSeed = seed;
	SetRandomSeed(seed);
	std::cout << "Random seed set to: " << seed << std::endl;
}