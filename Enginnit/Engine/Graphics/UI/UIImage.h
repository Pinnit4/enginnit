#ifndef ENGINNIT_UI_IMAGE
#define ENGINNIT_UI_IMAGE

#include "../Textures/Texture.h"
#include "UIElement.h"

using namespace std;

class UIImage : public UIElement {
public:
	UIImage();
	UIImage(string path);
	UIImage(Texture texture);

	Texture GetTexture();

	void SetTexture(string path);
	void SetTexture(Texture tx);

	Vector4i GetMargins();
	void SetMargins(Vector4i margins);

	void Destroy() override;

protected:
	Texture texture;
	Vector4i margins;

	void RenderInternal() override;
};
#endif