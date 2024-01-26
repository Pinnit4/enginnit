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

	vector<int> GetMargins();
	void SetMargins(vector<int> margins);

	void Render() override;
	void Destroy() override;

private:
	Texture texture;
	vector<int> margins;
};
#endif