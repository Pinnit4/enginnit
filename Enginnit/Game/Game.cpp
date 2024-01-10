#include "Game.h"
#include "../Engine/Graphics/Maps/TiledMap.h"

Game::Game() {

}

Game::~Game() {

}

void Game::Start() {
	
	TiledMap* map = new TiledMap("Assets/tiledmap.tlm");
	map->DrawMap(Vector2f(512.0f / 3, (768.0f / 2.0f) / 3));

	player = new CharacterController2D("Assets/player.cc2d");

	player->position = (map->GetWorldPosition(7,2) + Vector2f(4,4));
	player->scale = Vector2f::One();
	player->useGravity = false;
	player->pivot = Vector2f(0.5f, 0.5f);
	player->depthLayer = 5;
}

void Game::Tick(double deltaTime) {
	player->Tick(deltaTime);
}
