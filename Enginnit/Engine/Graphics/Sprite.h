#ifndef ENGINNIT_SPRITE
#define ENGINNIT_SPRITE

#include "Texture.h"

using namespace std;

class Sprite : virtual public Spatial2D {
public:
	Sprite();
	Sprite(string path);
	Sprite(string path, Vector2f position);
	Sprite(Texture texture);

	Vector2f pivot;

	Texture GetTexture();	

	void SetTexture(string path);
	void SetTexture(string path, Vector2f pivot);

	void SetTexture(Texture tx);
	void SetTexture(Texture tx, Vector2f pivot);

	void Render();

	void Destroy();
private:
	Texture texture;
};
#endif