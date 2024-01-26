#include "UIImage.h"

#include "UIManager.h"
#include "../Drawer.h"
#include "../Textures/TextureLoader.h"

UIImage::UIImage() : UIElement() {
	texture = Texture();
}

UIImage::UIImage(string path) : UIElement() {
	texture = TextureManager::GetTexture(path);
}
UIImage::UIImage(Texture tx) : UIElement() {
	texture = tx;
}

Texture UIImage::GetTexture() { return texture; }

void UIImage::SetTexture(string path) {
	SetTexture(TextureManager::GetTexture(path));
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