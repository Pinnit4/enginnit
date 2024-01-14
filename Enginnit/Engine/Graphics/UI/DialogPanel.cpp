#include "DialogPanel.h"
#include "../../Debug/DebugConsole.h"
#include "../GraphicsManager.h"

DialogPanel::DialogPanel() : UIElement() {
	background = new UIImage("Assets/sprites/tile_housecave.png");
}


void DialogPanel::Render() {
	string name = "##dialog_panel";
	const char* name_c = name.c_str();

	if (ImGui::Begin(name_c, nullptr,
		ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground)) {

		Vector2f screenSize = (Vector2f)GraphicsManager::GetScreenSize();

		ImGui::SetWindowSize(name_c, ImVec2(screenSize.x, screenSize.y / 3.0));
		ImGui::SetWindowPos(name_c, ImVec2(0, screenSize.y * 2.0 / 3.0));

		Vector2f windowSize = Vector2f(ImGui::GetWindowWidth(), ImGui::GetWindowHeight());

		Vector2f pos = Vector2f(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y);

		pos += (windowSize / 2.0);
		pos -= (screenSize / 2.0);

		pos.y *= -1;

		pos /= GraphicsManager::GetProjectionScale();
		windowSize /= GraphicsManager::GetProjectionScale();

		background->GetRect()->SetCenter(pos);
		background->GetRect()->SetSize(windowSize);
	}
	ImGui::End();

}