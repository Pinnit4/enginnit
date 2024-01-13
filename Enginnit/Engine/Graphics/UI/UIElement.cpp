#include "UIElement.h"

#include "UIManager.h"
#include "../GraphicsInternal.h"

void BeginRender();
void EndRender();

UIElement::UIElement() {
	sortingOrder = 0;
	UIManager::RegisterUIElement(this);
}

void UIElement::Render() {

}

void UIElement::Destroy() {
	UIManager::UnregisterUIElement(this);
}