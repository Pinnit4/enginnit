#ifndef ENGINNIT_UI_TEXT
#define ENGINNIT_UI_TEXT

#include "../Textures/Texture.h"
#include "UIElement.h"

using namespace std;

class UIText : public UIElement {
public:
	UIText();
	UIText(string fontPath, int fontSize);

	void SetFont(string fontPath, int fontSize);

	void SetText(string text);
	string GetText();

	void Destroy() override;
protected:
	ImFont* font;
	string text;

	ImVec2 wPos;
	ImVec2 wSize;

	void RenderInternal() override;
	void OnRectRefreshed() override;
};
#endif