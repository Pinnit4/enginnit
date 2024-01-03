#include "Sprite.h"
#include "Graphics.h"

Sprite::Sprite() : Spatial2D() {
	texture = Texture();
	Graphics::RegisterSprite(this);
	pivot = Vector2::Zero();
}

Sprite::Sprite(string path) : Spatial2D() {
	texture = Texture(path);
	Graphics::RegisterSprite(this);
	pivot = Vector2::Zero();
}

Sprite::Sprite(string path, Vector2 _position) : Spatial2D(_position) {
	texture = Texture(path);
	Graphics::RegisterSprite(this);
	pivot = Vector2::Zero();
}

Texture Sprite::GetTexture() { return texture; }

void Sprite::SetTexture(string path) { SetTexture(Texture(path), Vector2::Zero()); }
void Sprite::SetTexture(string path, Vector2 _pivot) { SetTexture(Texture(path), _pivot); }

void Sprite::SetTexture(Texture tx) { SetTexture(tx, Vector2::Zero()); }
void Sprite::SetTexture(Texture tx, Vector2 _pivot) { texture = tx;pivot = _pivot; }

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	// First translate, then rotate, then scale
	glTranslatef(position.x, position.y, 0);
	glRotatef(rotation, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);

	Vector2 pivotDiff = Vector2(-texture.GetWidth() * pivot.x, -texture.GetHeight() * pivot.y);

	// Set quad vertex positions (in local pos, since we already "moved" the matrix right above us in glTranslatef)
	glTexCoord2f(0, 0);		glVertex2f(pivotDiff.x, pivotDiff.y);
	glTexCoord2f(1, 0);		glVertex2f(texture.GetWidth() + pivotDiff.x, pivotDiff.y);
	glTexCoord2f(1, 1);		glVertex2f(texture.GetWidth() + pivotDiff.x, texture.GetHeight() + pivotDiff.y);
	glTexCoord2f(0, 1);		glVertex2f(pivotDiff.x, texture.GetHeight() + pivotDiff.y);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}