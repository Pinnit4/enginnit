#include "Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::Start() {
	player = new CharacterController2D("Assets/player.asset");

	player->position = Vector2(512.0f, (768.0f / 2.0f));
	player->scale = Vector2::One();
	player->useGravity = false;
	player->pivot = Vector2(0.5f, 0.0f);

	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> disX(-512, 512);
	uniform_int_distribution<> disY(-(768 / 2), (768 / 2));

	Sprite* trees[20];
	for (int i = 0; i < 20; i++) {
		trees[i] = new Sprite("Assets/Sprites/tree.png", Vector2(512.0f + disX(gen), (768.0f /2.0f) + disY(gen)));
	}
}

void Game::Tick(double deltaTime) {
	player->Tick(deltaTime);
}