#include "Texture.h"

#include <iostream>
using namespace std;

Texture::Texture() {
	id = -1;
}

Texture::Texture(int _id) {
	if (!SetImageParameters(_id)) {
		cout << "Error loading image with ID: " << _id << endl;
	}
}

Texture::Texture(string path) {
	if (!LoadImage(path, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y)) {
		cout << "Error loading image with path: " << path << endl;
	}
}

int Texture::GetID() { return id; }
int Texture::GetWidth() { return width; }
int Texture::GetHeight() { return height; }
string Texture::GetPath() { return path; }

bool Texture::LoadImage(string _path, unsigned int flags) {
	path = _path;
	int _id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, flags);
	return SetImageParameters(_id);
}

bool Texture::SetImageParameters(int _id) {
	id = _id;

	if (id > 0) {
		int mipLevel = 0;
		glBindTexture(GL_TEXTURE_2D, id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &height);
		return true;
	}
	return false;
}