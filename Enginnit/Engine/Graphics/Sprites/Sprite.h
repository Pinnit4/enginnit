#ifndef ENGINNIT_SPRITE
#define ENGINNIT_SPRITE

#include "../Textures/Texture.h"
#include "../../Assets/Asset.h"

using namespace std;

class Sprite : public Asset {
public:
	Sprite();
	Sprite(string path);
	Sprite(string path, Vector2f position);
	Sprite(Texture texture);
	Sprite(Spatial2D* spatial);

	Vector2f pivot;
	string path;
	Spatial2D* spatial;

	Texture GetTexture();	
	
	void SetTexture(string path);
	void SetTexture(string path, Vector2f pivot);

	void SetTexture(Texture tx);
	void SetTexture(Texture tx, Vector2f pivot);

	Vector4i GetMargins();
	void SetMargins(Vector4i margins);

	void Render();

	void Destroy();
private:
	Texture texture;
	Vector4i margins;
};
#endif