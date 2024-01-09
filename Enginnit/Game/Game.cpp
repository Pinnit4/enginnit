#include "Game.h"
#include "../Engine/Graphics/Tiles/TiledMap.h"

Game::Game() {

}

Game::~Game() {

}

void Game::Start() {
	
	TiledMap* map = new TiledMap("Assets/tiledmap.tlm");
	map->DrawSpriteGrid(Vector2f(512.0f / 3, (768.0f / 2.0f) / 3));

	player = new CharacterController2D("Assets/player.cc2d");

	player->position = (map->GetWorldPosition(7,2) + Vector2f(4,4));
	player->scale = Vector2f::One();
	player->useGravity = false;
	player->pivot = Vector2f(0.5f, 0.5f);
	player->depthLayer = 5;

	CharacterController2D* p2 = new CharacterController2D("Assets/player.cc2d");
	p2->position = map->GetWorldPosition(7, 4) + Vector2f(4, 4);
	p2->scale = Vector2f::One();
	p2->useGravity = false;
	p2->pivot = Vector2f(0.5f, 0.5f);
	p2->depthLayer = 5;
	p2->movementSpeed = 0;
	p2->GetRect()->SetSize(Vector2f(10, 10));
}

void Game::Tick(double deltaTime) {
	player->Tick(deltaTime);
}
