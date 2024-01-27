#include "UIText.h"

UIText::UIText() : UIElement() {
	font = ImGui::GetIO().Fonts->Fonts[0];
	text = "";
}

UIText::UIText(string path, int fontSize) : UIElement() {
	font = ImGui::GetIO().Fonts->AddFontFromFileTTF(path.c_str(), fontSize);
	text = "";
}

void UIText::SetFont(string path, int fontSize) {
	font = ImGui::GetIO().Fonts->AddFontFromFileTTF(path.c_str(), fontSize);
}

void UIText::SetText(string _text) {
	text = _text;
}

string UIText::GetText() {
	return text;
}

void UIText::Render() {
	if (ImGui::Begin("##text", nullptr, ImGuiWindowFlags_NoNav
		| ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs 
		| ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings)) {

		Vector2f pos = imGuiRect->GetPoints()[0];
		Vector2f size = imGuiRect->GetSize();

		ImVec2 wPos = ImVec2(pos.x, pos.y);
		ImVec2 wSize = ImVec2(size.x, size.y);

		ImGui::SetWindowPos(wPos);
		ImGui::SetWindowSize(wSize);

		if (font != NULL) ImGui::PushFont(font);
		ImGui::Text((char*)text.c_str());
		if (font != NULL) ImGui::PopFont();
	}
	ImGui::End();
}

void UIText::Destroy() {
	UIElement::Destroy();
	font = NULL;
}