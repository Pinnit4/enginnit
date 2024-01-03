#ifndef ENGINNIT_SPRITE
#define ENGINNIT_SPRITE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"
#include "Texture.h"

#include <iostream>
#include <string>
#include "../Math/Vector2.h"
#include "../Math/Spatial2D.h"

using namespace std;

class Sprite : virtual public Spatial2D {
public:
	Sprite();
	Sprite(string path);
	Sprite(string path, Vector2 position);

	Vector2 pivot;

	Texture GetTexture();	

	void SetTexture(string path);
	void SetTexture(string path, Vector2 pivot);

	void SetTexture(Texture tx);
	void SetTexture(Texture tx, Vector2 pivot);

	void Render();
private:
	Texture texture;
};
#endif