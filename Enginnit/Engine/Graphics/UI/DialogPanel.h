#ifndef ENGINNIT_DIALOG_PANEL
#define ENGINNIT_DIALOG_PANEL

#include "UI.h"
#include "UIImage.h"
#include "../Graphics.h"
#include "UIText.h"

class DialogPanel : public UIElement {
public:
	DialogPanel();
protected:
	UIImage* background;
	UIText* text;

	void RenderInternal() override;
};
#endif