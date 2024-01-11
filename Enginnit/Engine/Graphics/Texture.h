#ifndef ENGINNIT_TEXTURE
#define ENGINNIT_TEXTURE

#include "GraphicsInternal.h"
#include "../Math/Math.h"

#include <iostream>
#include <string>


using namespace std;

class Texture {
public:
	Texture();
	Texture(int _id);
	Texture(string path);

	int GetID();
	int GetWidth();
	int GetHeight();

	Vector2i GetAnchorMin();
	Vector2i GetAnchorMax();
	
	Vector2d GetAnchorMinPercent();
	Vector2d GetAnchorMaxPercent();

	void SetAnchors(Vector2i min, Vector2i max);

	string GetName();
	void SetName(string name);

	string GetPath();

private:
	int id;
	string name;

	int width;
	int height;

	int internalWidth;
	int internalHeight;

	Vector2i anchorMin;
	Vector2i anchorMax;

	Vector2d anchorMinPercent;
	Vector2d anchorMaxPercent;

	string path;

	bool LoadImage(string path, unsigned int flags);
	bool SetImageParameters(int _id);

	void RefreshAnchorsInPercent();
};

#endif
