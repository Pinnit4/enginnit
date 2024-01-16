#include "UIImage.h"

#include "UIManager.h"
#include "../Drawer.h"
#include "../TextureLoader.h"

UIImage::UIImage() : UIElement() {
	texture = Texture();
	rect = new Rect2D();
}

UIImage::UIImage(string path) : UIElement() {
	texture = TextureLoader::LoadTexture(path);
	rect = new Rect2D();
}
UIImage::UIImage(Texture tx) : UIElement() {
	texture = tx;
	rect = new Rect2D();
}

Texture UIImage::GetTexture() { return texture; }
Rect2D* UIImage::GetRect() { return rect; }

void UIImage::SetTexture(string path) {
	SetTexture(TextureLoader::LoadTexture(path));
}
void UIImage::SetTexture(Texture _texture) {
	texture = _texture;
}

vector<int> UIImage::GetMargins() { return margins; }
void UIImage::SetMargins(vector<int> _margins) { margins = _margins; }

void UIImage::Render() {
	Drawer::DrawRect2DWithMargins(texture, rect, margins);
}

void UIImage::Destroy() {
	UIElement::Destroy();
	texture = NULL;
}