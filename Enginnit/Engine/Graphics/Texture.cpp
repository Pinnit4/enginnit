#include "Texture.h"

#include <iostream>
using namespace std;

Texture::Texture() {
	id = -1;
	name = "default";
}

Texture::Texture(int _id) {
	if (!SetImageParameters(_id)) {
		cout << "Error loading image with ID: " << _id << endl;
	}
	name = "default";
}

Texture::Texture(string path) {
	if (!LoadImage(path, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y)) {
		cout << "Error loading image with path: " << path << endl;
	}
	name = "default";
}

int Texture::GetID() { return id; }

int Texture::GetWidth() { return width; }
int Texture::GetHeight() { return height; }

Vector2Int Texture::GetAnchorMin() { return anchorMin; }
Vector2Int Texture::GetAnchorMax() { return anchorMax; }

Vector2Double Texture::GetAnchorMinPercent() { return anchorMinPercent; }
Vector2Double Texture::GetAnchorMaxPercent() { return anchorMaxPercent; }

void Texture::SetAnchors(Vector2Int _anchorMin, Vector2Int _anchorMax) {
	anchorMin = _anchorMin;
	anchorMax = _anchorMax;
	width = anchorMax.x - anchorMin.x + 1;
	height = anchorMax.y - anchorMin.y + 1;
	RefreshAnchorsInPercent();
}

string Texture::GetName() { return name; }
void Texture::SetName(string _name) { name = _name; }

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
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &internalWidth);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &internalHeight);

		SetAnchors(Vector2Int::Zero(), Vector2Int(internalWidth-1, internalHeight-1));

		return true;
	}
	return false;
}

void Texture::RefreshAnchorsInPercent() {
	anchorMinPercent = Vector2Double(((double)anchorMin.x) / ((double)internalWidth), ((double)anchorMin.y) / ((double)internalHeight));
	anchorMaxPercent = Vector2Double(((double)anchorMax.x + 1) / ((double)internalWidth), ((double)anchorMax.y + 1) / ((double)internalHeight));
}