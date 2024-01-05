#ifndef ENGINNIT_TEXTURE
#define ENGINNIT_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"

#include <iostream>
#include <string>

#include "../Math/Vector2.h"

using namespace std;

class Texture {
public:
	Texture();
	Texture(int _id);
	Texture(string path);

	int GetID();
	int GetWidth();
	int GetHeight();

	Vector2Int GetAnchorMin();
	Vector2Int GetAnchorMax();
	
	Vector2Double GetAnchorMinPercent();
	Vector2Double GetAnchorMaxPercent();

	void SetAnchors(Vector2Int min, Vector2Int max);

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

	Vector2Int anchorMin;
	Vector2Int anchorMax;

	Vector2Double anchorMinPercent;
	Vector2Double anchorMaxPercent;

	string path;

	bool LoadImage(string path, unsigned int flags);
	bool SetImageParameters(int _id);

	void RefreshAnchorsInPercent();
};

#endif
