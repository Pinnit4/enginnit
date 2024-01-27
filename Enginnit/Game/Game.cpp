#include "Game.h"
#include "../Engine/Graphics/UI/DialogPanel.h"

Game::Game() {
	currentScene = NULL;
}

Game::~Game() {

}

void Game::Start() {
	currentScene = new Scene("res/scenes/scene0.scn");
	currentScene->Start();

	DialogPanel* panel = new DialogPanel();
}

void Game::Tick(double deltaTime) {
	//currentScene->Tick(deltaTime);
}