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

void UIImage::Destroy() {
	UIElement::Destroy();
	texture = NULL;
}