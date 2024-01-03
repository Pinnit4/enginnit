#include "Engine/Engine.h"
#include "Game/Game.h"

int main() {
	Engine engine;
	engine.Initialize((char*)"Super Amigos");

	Game game;
	game.Start();

	while (true) {

		engine.Update();

		game.Tick(Engine::deltaTime);

		engine.Render();
	}

	return 0;
}