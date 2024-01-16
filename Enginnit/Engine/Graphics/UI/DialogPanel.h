#ifndef ENGINNIT_DIALOG_PANEL
#define ENGINNIT_DIALOG_PANEL

#include "UI.h"
#include "UIImage.h"
#include "../Graphics.h"

class DialogPanel : public UIElement {
public:
	DialogPanel();
	void Render() override;
private:
	UIImage* background;
	ImFont* dialogFont;
};
#endif