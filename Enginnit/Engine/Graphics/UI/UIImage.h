#ifndef ENGINNIT_UI_IMAGE
#define ENGINNIT_UI_IMAGE

#include "../Texture.h"
#include "UIElement.h"

using namespace std;

class UIImage : public UIElement {
public:
	UIImage();
	UIImage(string path);
	UIImage(Texture texture);

	Texture GetTexture();
	Rect2D* GetRect();

	vector<int> GetMargins();
	void SetMargins(vector<int> margins);

	void SetTexture(string path);
	void SetTexture(Texture tx);

	void Render() override;
	void Destroy() override;
private:
	Texture texture;
	Rect2D* rect;

	vector<int> margins;
};
#endif