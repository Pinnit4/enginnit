#include "DialogPanel.h"
#include "../../Debug/DebugConsole.h"
#include "../GraphicsManager.h"

DialogPanel::DialogPanel() : UIElement() {
	background = new UIImage("Assets/sprites/ui_border_opaque.png");
	background->SetMargins({ 3,3,3,3 });
	background->SetParent(this);

	dialogFont = ImGui::GetIO().Fonts->AddFontFromFileTTF("Assets/fonts/slkscr.ttf", 16);

	anchorMax = Vector2f(1, 0.3);

	lowerLeftCorner = Vector2f(4, 4);
	upperRightCorner = Vector2f(-4, -4);

	RefreshRect();
}

void DialogPanel::Render() {
	
}