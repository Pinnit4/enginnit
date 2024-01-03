#ifndef GAME_BASE
#define GAME_BASE

#include "../Engine/Player/CharacterController2D.h"
#include <random>
#include <iostream>

using namespace std;

class Game {
public:
	Game();
	~Game();

	void Start();
	void Tick(double deltaTime);
private:
	CharacterController2D* player;
	Sprite* trees[];
};

#endif
