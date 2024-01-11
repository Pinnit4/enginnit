#include "Sprite.h"

#include "GraphicsManager.h"

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
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	// First translate, then rotate, then scale
	glRotatef(rotation, 0, 0, 1);
	glTranslatef(position.x, position.y, 0);
	glScalef(scale.x, scale.y, 1);

	// Set interpolation to nearest to ensure pixel perfection
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);

	Vector2f pivotDiff = Vector2f(-texture.GetWidth() * pivot.x, -texture.GetHeight() * pivot.y);
	pivotDiff -= GraphicsManager::GetCameraPosition();

	// Set quad vertex positions (in local pos, since we already "moved" the matrix right above us in glTranslatef)
	glTexCoord2d(texture.GetAnchorMinPercent().x, texture.GetAnchorMinPercent().y);		glVertex2f(pivotDiff.x, pivotDiff.y);
	glTexCoord2d(texture.GetAnchorMaxPercent().x, texture.GetAnchorMinPercent().y);		glVertex2f(texture.GetWidth() + pivotDiff.x, pivotDiff.y);
	glTexCoord2d(texture.GetAnchorMaxPercent().x, texture.GetAnchorMaxPercent().y);		glVertex2f(texture.GetWidth() + pivotDiff.x, texture.GetHeight() + pivotDiff.y);
	glTexCoord2d(texture.GetAnchorMinPercent().x, texture.GetAnchorMaxPercent().y);		glVertex2f(pivotDiff.x, texture.GetHeight() + pivotDiff.y);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::Destroy() {
	GraphicsManager::UnregisterSprite(this);
	texture = NULL;
	pivot = Vector2f::Zero();
}