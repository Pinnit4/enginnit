#ifdef TILESETEDITOR

#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL

#include "Engine/Engine.h"
#include "TilesetEditor/TilesetEditor.h"

int main() {
	Engine engine;
	engine.Initialize((char*)"Tileset Editor");

	TilesetEditor editor;
	editor.Start();

	while (!engine.ShouldShutdown()) {
		engine.Update();

		editor.Tick(Engine::deltaTime);

		engine.Render();
	}

	engine.Shutdown();

	return 0;
}

#endif