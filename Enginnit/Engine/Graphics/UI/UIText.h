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

	void Render() override;
	void Destroy() override;
private:
	ImFont* font;
	string text;
};
#endif