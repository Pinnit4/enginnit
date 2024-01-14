#include "UIImage.h"

#include "UIManager.h"
#include "../Drawer.h"

UIImage::UIImage() : UIElement() {
	texture = Texture();
	rect = new Rect2D();
}

UIImage::UIImage(string path) : UIElement() {
	texture = Texture(path);
	rect = new Rect2D();
}
UIImage::UIImage(Texture tx) : UIElement() {
	texture = tx;
	rect = new Rect2D();
}

Texture UIImage::GetTexture() { return texture; }
Rect2D* UIImage::GetRect() { return rect; }

void UIImage::SetTexture(string path) {
	SetTexture(Texture(path));
}
void UIImage::SetTexture(Texture _texture) {
	texture = _texture;
}

void UIImage::Render() {
	Drawer::DrawRect2D(texture, rect);
}

//void UIImage::Render() {
//	glEnable(GL_TEXTURE_2D);
//
//	glBindTexture(GL_TEXTURE_2D, texture.GetID());
//	glLoadIdentity();
//
//	// First translate, then rotate, then scale
//	glRotatef(0, 0, 0, 1);
//	glTranslatef(0, 0, 0);
//	glScalef(1, 1, 1);
//
//	// Set interpolation to nearest to ensure pixel perfection
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//	// Rendering
//	glColor4f(1, 1, 1, 1);
//	glBegin(GL_QUADS);
//
//	// Set quad vertex positions (in local pos, since we already "moved" the matrix right above us in glTranslatef)
//	Vector2d anchorMin = texture.GetAnchorMinPercent();
//	Vector2d anchorMax = texture.GetAnchorMaxPercent();
//
//	vector<Vector2f> points = rect->GetPoints();
//
//	glTexCoord2d(anchorMax.x, anchorMax.y);		glVertex2f(points[0].x, points[0].y);
//	glTexCoord2d(anchorMin.x, anchorMax.y);		glVertex2f(points[1].x, points[1].y);
//	glTexCoord2d(anchorMin.x, anchorMin.y);		glVertex2f(points[2].x, points[2].y);
//	glTexCoord2d(anchorMax.x, anchorMin.y);		glVertex2f(points[3].x, points[3].y);
//
//	glEnd();
//
//	glDisable(GL_TEXTURE_2D);
//}

void UIImage::Destroy() {
	UIElement::Destroy();
	texture = NULL;
}