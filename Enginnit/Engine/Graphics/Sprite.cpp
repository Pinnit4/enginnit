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

Sprite::Sprite(Texture tx) : Spatial2D() {
	texture = tx;
	Graphics::RegisterSprite(this);
	pivot = Vector2::Zero();
}

Texture Sprite::GetTexture() { return texture; }

void Sprite::SetTexture(string path) {
	SetTexture(Texture(path), pivot);
}
void Sprite::SetTexture(string path, Vector2 _pivot) {
	SetTexture(Texture(path), _pivot);
}

void Sprite::SetTexture(Texture _texture) {
	SetTexture(_texture, pivot);
}
void Sprite::SetTexture(Texture _texture, Vector2 _pivot) {
	texture = _texture;
	pivot = _pivot;
}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	// First translate, then rotate, then scale
	glTranslatef(position.x, position.y, 0);
	glRotatef(rotation, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	// Set interpolation to nearest to ensure pixel perfection
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);

	Vector2 pivotDiff = Vector2(-texture.GetWidth() * pivot.x, -texture.GetHeight() * pivot.y);
	pivotDiff -= Graphics::GetCameraPosition();

	// Set quad vertex positions (in local pos, since we already "moved" the matrix right above us in glTranslatef)

	//glTexCoord2f(texture.GetAnchorMinPercent().x, texture.GetAnchorMinPercent().y);		glVertex2f(pivotDiff.x, pivotDiff.y);
	//glTexCoord2f(texture.GetAnchorMaxPercent().x, texture.GetAnchorMinPercent().y);		glVertex2f(texture.GetWidth() + pivotDiff.x, pivotDiff.y);
	//glTexCoord2f(texture.GetAnchorMaxPercent().x, texture.GetAnchorMaxPercent().y);		glVertex2f(texture.GetWidth() + pivotDiff.x, texture.GetHeight() + pivotDiff.y);
	//glTexCoord2f(texture.GetAnchorMinPercent().x, texture.GetAnchorMaxPercent().y);		glVertex2f(pivotDiff.x, texture.GetHeight() + pivotDiff.y);

	glTexCoord2d(texture.GetAnchorMinPercent().x, texture.GetAnchorMinPercent().y);		glVertex2f(pivotDiff.x, pivotDiff.y);
	glTexCoord2d(texture.GetAnchorMaxPercent().x, texture.GetAnchorMinPercent().y);		glVertex2f(texture.GetWidth() + pivotDiff.x, pivotDiff.y);
	glTexCoord2d(texture.GetAnchorMaxPercent().x, texture.GetAnchorMaxPercent().y);		glVertex2f(texture.GetWidth() + pivotDiff.x, texture.GetHeight() + pivotDiff.y);
	glTexCoord2d(texture.GetAnchorMinPercent().x, texture.GetAnchorMaxPercent().y);		glVertex2f(pivotDiff.x, texture.GetHeight() + pivotDiff.y);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::Destroy() {
	Graphics::UnregisterSprite(this);
	texture = NULL;
	pivot = Vector2::Zero();
}