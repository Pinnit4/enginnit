#ifndef ENGINNIT_SPRITE_ANIMATION
#define ENGINNIT_SPRITE_ANIMATION

#include "GLFW/glfw3.h"

#include <iostream>
#include <string>
#include <vector>

#include "../Math/Spatial2D.h"
#include "../Graphics/Tiles/Tileset.h"

using namespace std;

struct SpriteAnimation {
	Tileset* tileset;
	vector<char> frameIds;
	vector<Texture> frames;
	double fps;
	string path;

	SpriteAnimation() {
		tileset = new Tileset();
		frames.clear();
		fps = 0;
	}
	SpriteAnimation(Tileset* _tileset, vector<Texture> _frames, double _fps) {
		tileset = _tileset;
		frames = _frames;
		fps = _fps;
	}
};
#endif