#include "Texture.h"

#include <iostream>
#include "../../Debug/DebugConsole.h"

using namespace std;

Texture::Texture() {
	id = -1;
	name = "default";
	width = 0; height = 0;
	internalWidth = 0; internalHeight = 0;
}

Texture::Texture(int _id) {
	if (!SetImageParameters(_id)) {
		DebugConsole::LogError("Error loading image with ID: " + _id);
	}
	name = "default";
}

Texture::Texture(string path) {
	if (!LoadImage(path, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y)) {
		DebugConsole::LogError("Error loading image with path : " + path);
	}
	name = "default";
}

Texture::Texture(const Texture& source) {
	id = source.id;

	name = source.name;
	path = source.path;

	internalWidth = source.internalWidth;
	internalHeight = source.internalHeight;

	width = source.width;
	height = source.height;

	anchors = source.anchors;
	anchorsPercent = source.anchorsPercent;
}

int Texture::GetID() { return id; }

int Texture::GetWidth() { return width; }
int Texture::GetHeight() { return height; }

Vector2i Texture::GetAnchorMin() { return anchors[0]; }
Vector2i Texture::GetAnchorMax() { return anchors[2]; }
vector<Vector2i> Texture::GetAllAnchors() { return anchors; }

Vector2d Texture::GetAnchorMinPercent() { return anchorsPercent[0]; }
Vector2d Texture::GetAnchorMaxPercent() { return anchorsPercent[2]; }
vector<Vector2d> Texture::GetAllAnchorsPercent() { return  anchorsPercent; }

void Texture::SetAnchors(Vector2i anchorMin, Vector2i anchorMax) {
	anchors = { anchorMin, Vector2i(anchorMin.x, anchorMax.y), anchorMax, Vector2i(anchorMax.x, anchorMin.y) };

	Vector2d minPercent = Vector2d(((double)anchorMin.x) / ((double)internalWidth), ((double)anchorMin.y) / ((double)internalHeight));
	Vector2d maxPercent = Vector2d(((double)anchorMax.x + 1) / ((double)internalWidth), ((double)anchorMax.y + 1) / ((double)internalHeight));

	anchorsPercent = { minPercent, Vector2d(minPercent.x, maxPercent.y), maxPercent, Vector2d(maxPercent.x, minPercent.y) };

	width = anchorMax.x - anchorMin.x + 1;
	height = anchorMax.y - anchorMin.y + 1;
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

		SetAnchors(Vector2i(0), Vector2i(internalWidth - 1, internalHeight - 1));

		return true;
	}
	return false;
}