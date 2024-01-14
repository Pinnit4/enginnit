#include "Sprite.h"

#include "GraphicsManager.h"
#include "Drawer.h"
#include "../Math/TransformData.h"

Sprite::Sprite() : Spatial2D() {
	texture = Texture();
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f::Zero();
}

Sprite::Sprite(string path) : Spatial2D() {
	texture = Texture(path);
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f::Zero();
}

Sprite::Sprite(string path, Vector2f _position) : Spatial2D(_position) {
	texture = Texture(path);
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f::Zero();
}

Sprite::Sprite(Texture tx) : Spatial2D() {
	texture = tx;
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f::Zero();
}

Texture Sprite::GetTexture() { return texture; }

void Sprite::SetTexture(string path) {
	SetTexture(Texture(path), pivot);
}
void Sprite::SetTexture(string path, Vector2f _pivot) {
	SetTexture(Texture(path), _pivot);
}

void Sprite::SetTexture(Texture _texture) {
	SetTexture(_texture, pivot);
}
void Sprite::SetTexture(Texture _texture, Vector2f _pivot) {
	texture = _texture;
	pivot = _pivot;
}

void Sprite::Render() {
	Rect2D auxRect = Rect2D();
	Vector2f size = Vector2f(texture.GetWidth(), texture.GetHeight());
	auxRect.SetSize(size);

	Vector2f center = (size / 2.0);
	center -= GraphicsManager::GetCameraPosition();
	center -= (size * pivot);
	auxRect.SetCenter(center);

	Drawer::DrawRect2D(texture, &auxRect, TransformData::FromSpatial2D(*this));
}

void Sprite::Destroy() {
	GraphicsManager::UnregisterSprite(this);
	texture = NULL;
	pivot = Vector2f::Zero();
}