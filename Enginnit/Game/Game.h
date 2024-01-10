#ifndef GAME_BASE
#define GAME_BASE

#include <random>
#include <iostream>
#include "../Engine/Scenes/Scene.h"

using namespace std;

class Game {
public:
	Game();
	~Game();

	void Start();
	void Tick(double deltaTime);
private:
	Scene* currentScene;
};

#endif
