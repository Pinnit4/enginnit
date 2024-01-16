#include "DialogPanel.h"
#include "../../Debug/DebugConsole.h"
#include "../GraphicsManager.h"

DialogPanel::DialogPanel() : UIElement() {
	background = new UIImage("Assets/sprites/ui_border_opaque.png");
	background->SetMargins({ 3,3,3,3 });

	dialogFont = ImGui::GetIO().Fonts->AddFontFromFileTTF("Assets/fonts/slkscr.ttf", 32);
}

void DialogPanel::Render() {
	string name = "##dialog_panel";
	const char* name_c = name.c_str();

	if (ImGui::Begin(name_c, nullptr,
		ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove)) {

		background->AdjustToCurrentWindow();
		Vector2f screenSize = (Vector2f)GraphicsManager::GetScreenSize();

		ImGui::SetWindowSize(name_c, ImVec2(screenSize.x - 16, (screenSize.y / 3.0) - 16));
		ImGui::SetWindowPos(name_c, ImVec2(8, (screenSize.y * 2.0 / 3.0) + 8));

		background->AdjustToCurrentWindow({8,16,0,16});

		ImGui::Dummy(ImVec2(16, 16));

		ImGui::Dummy(ImVec2(32, 16));
		ImGui::SameLine();

		ImGui::PushFont(dialogFont);
		ImGui::PushTextWrapPos((screenSize.x - 64 + 8));
		ImGui::TextWrapped("a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a ");
		ImGui::PopTextWrapPos();
		ImGui::PopFont();
	}
	ImGui::End();

}