#ifdef GAME

#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL

#include "Engine/Engine.h"
#include "Game/Game.h"

int main() {
	Engine engine;
	engine.Initialize((char*)"Example Game");

	Game game;
	game.Start();

	while (!engine.ShouldShutdown()) {
		engine.Update();

		game.Tick(Engine::deltaTime);

		engine.Render();

		engine.LateUpdate();
	}

	engine.Shutdown();

	return 0;
}

#endif