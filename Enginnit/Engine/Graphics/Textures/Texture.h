#ifndef ENGINNIT_TEXTURE
#define ENGINNIT_TEXTURE

#include "../GraphicsInternal.h"

#include <iostream>
#include <string>


using namespace std;

class Texture {
public:
	Texture();
	Texture(int _id);
	Texture(string path);
	Texture(const Texture& source);

	int GetID();
	int GetWidth();
	int GetHeight();

	Vector2i GetAnchorMin();
	Vector2i GetAnchorMax();
	vector<Vector2i> GetAllAnchors();
	
	Vector2d GetAnchorMinPercent();
	Vector2d GetAnchorMaxPercent();
	vector<Vector2d> GetAllAnchorsPercent();

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

	vector<Vector2i> anchors;
	vector<Vector2d> anchorsPercent;

	string path;

	bool LoadImage(string path, unsigned int flags);
	bool SetImageParameters(int _id);
};

#endif
