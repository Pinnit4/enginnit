#include "Game.h"

Game::Game() {
	currentScene = NULL;
}

Game::~Game() {

}

void Game::Start() {
	currentScene = new Scene("Assets/scene0.scn");
	currentScene->Start();
}

void Game::Tick(double deltaTime) {
	currentScene->Tick(deltaTime);
}