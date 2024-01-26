#ifndef ENGINNIT_GRAPHICS_EXTENDEDRECTDRAWER
#define ENGINNIT_GRAPHICS_EXTENDEDRECTDRAWER

#include "BaseDrawer.h"
#include <vector>

namespace Drawer {
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, vector<int> margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, Color c, vector<int> margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, Spatial2D sp, vector<int> margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, Spatial2D sp, Color c, vector<int> margins);
}

#endif