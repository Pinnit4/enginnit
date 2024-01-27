#include "Sprite.h"

#include "../GraphicsManager.h"
#include "../Drawer.h"
#include "../Textures/TextureLoader.h"

Sprite::Sprite() : Asset() {
	spatial = new Spatial2D();
	texture = Texture();
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f(0);
	path = "";
	margins = Vector4i(0);
}

Sprite::Sprite(string path) : Asset() {
	spatial = new Spatial2D();
	texture = TextureManager::GetTexture(path);
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f(0);
	path = "";
	margins = Vector4i(0);
}

Sprite::Sprite(string path, Vector2f _position) : Asset() {
	spatial = new Spatial2D(_position);
	texture = TextureManager::GetTexture(path);
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f(0);
	path = "";
	margins = Vector4i(0);
}

Sprite::Sprite(Texture tx) : Asset() {
	spatial = new Spatial2D();
	texture = tx;
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f(0);
	path = "";
	margins = Vector4i(0);
}

Sprite::Sprite(Spatial2D* _spatial) : Asset() {
	spatial = _spatial;
	texture = Texture();
	GraphicsManager::RegisterSprite(this);
	pivot = Vector2f(0);
	path = "";	
	margins = Vector4i(0);
}


Vector4i Sprite::GetMargins() { return margins; }
void Sprite::SetMargins(Vector4i _margins) { margins = _margins; }

Texture Sprite::GetTexture() { return texture; }

void Sprite::SetTexture(string path) {
	SetTexture(TextureManager::GetTexture(path), pivot);
}
void Sprite::SetTexture(string path, Vector2f _pivot) {
	SetTexture(TextureManager::GetTexture(path), _pivot);
}

void Sprite::SetTexture(Texture _texture) {
	SetTexture(_texture, pivot);
}
void Sprite::SetTexture(Texture _texture, Vector2f _pivot) {
	texture = _texture;
	pivot = _pivot;
}

void Sprite::Render() {
	Vector2f size = Vector2f(texture.GetWidth(), texture.GetHeight());
	Vector2f center = (size / 2.0);
	center -= GraphicsManager::GetCameraPosition();
	center -= (size * pivot);

	Rect2D mainRect = Rect2D(center, size);

	Drawer::DrawRect2DWithMargins(texture, &mainRect, Spatial2D(*spatial), margins);
}

void Sprite::Destroy() {
	GraphicsManager::UnregisterSprite(this);
	texture = NULL;
	pivot = Vector2f(0);
}