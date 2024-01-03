#ifndef ENGINNIT_TEXTURE
#define ENGINNIT_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"

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

	string GetPath();

private:
	int id;
	int width;
	int height;

	string path;

	bool LoadImage(string path, unsigned int flags);
	bool SetImageParameters(int _id);
};

#endif
