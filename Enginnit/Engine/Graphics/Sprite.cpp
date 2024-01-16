#include "Sprite.h"

#include "GraphicsManager.h"
#include "../Math/TransformData.h"
#include "Drawer.h"
#include "TextureLoader.h"

void DrawRect2DSegment(Texture tx, Vector2f ll_loc, Vector2f tr_loc, Rect2D mr, TransformData td);

Sprite::Sprite() : Spatial2D() {
	texture = Texture();
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f::Zero();
	path = "";
	margins = { 0,0,0,0 };
}

Sprite::Sprite(string path) : Spatial2D() {
	texture = TextureLoader::LoadTexture(path);
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f::Zero();
	path = "";
	margins = { 0,0,0,0 };
}

Sprite::Sprite(string path, Vector2f _position) : Spatial2D(_position) {
	texture = TextureLoader::LoadTexture(path);
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f::Zero();
	path = "";
	margins = { 0,0,0,0 };
}

Sprite::Sprite(Texture tx) : Spatial2D() {
	texture = tx;
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f::Zero();
	path = "";
	margins = { 0,0,0,0 };
}

vector<int> Sprite::GetMargins() { return margins; }
void Sprite::SetMargins(vector<int> _margins) { margins = _margins; }

Texture Sprite::GetTexture() { return texture; }

void Sprite::SetTexture(string path) {
	SetTexture(TextureLoader::LoadTexture(path), pivot);
}
void Sprite::SetTexture(string path, Vector2f _pivot) {
	SetTexture(TextureLoader::LoadTexture(path), _pivot);
}

void Sprite::SetTexture(Texture _texture) {
	SetTexture(_texture, pivot);
}
void Sprite::SetTexture(Texture _texture, Vector2f _pivot) {
	texture = _texture;
	pivot = _pivot;
}

void Sprite::Render() {
	TransformData td = TransformData::FromSpatial2D(*this);

	Vector2f size = Vector2f(texture.GetWidth(), texture.GetHeight());
	Vector2f center = (size / 2.0);
	center -= GraphicsManager::GetCameraPosition();
	center -= (size * pivot);

	Rect2D mainRect = Rect2D(center, size);

	Drawer::DrawRect2DWithMargins(texture, &mainRect, td, margins);
}

void Sprite::Destroy() {
	GraphicsManager::UnregisterSprite(this);
	texture = NULL;
	pivot = Vector2f::Zero();
}