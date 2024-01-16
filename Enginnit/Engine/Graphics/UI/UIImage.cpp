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

void UIImage::AdjustToCurrentWindow() { AdjustToCurrentWindow({ 0,0,0,0 }); }
void UIImage::AdjustToCurrentWindow(vector<float> padding) {
	Vector2f screenSize = (Vector2f)GraphicsManager::GetScreenSize();

	// Get window data
	Vector2f windowSize = Vector2f(ImGui::GetWindowWidth() - padding[1] - padding[3], ImGui::GetWindowHeight() - padding[0] - padding[2]);
	Vector2f windowPos = Vector2f(ImGui::GetWindowPos().x + padding[1], ImGui::GetWindowPos().y - (padding[0] / 2));


	// Set windowPos at center
	windowPos += (windowSize / 2.0);

	// Remove screenSize
	windowPos -= (screenSize / 2.0);

	windowPos.y *= -1;

	//windowPos.x += padding[1];
	//windowPos.y += padding[0];

	// Adjust to projection scale
	windowPos /= GraphicsManager::GetProjectionScale();
	windowSize /= GraphicsManager::GetProjectionScale();

	rect->SetCenter(windowPos);
	rect->SetSize(windowSize);
}