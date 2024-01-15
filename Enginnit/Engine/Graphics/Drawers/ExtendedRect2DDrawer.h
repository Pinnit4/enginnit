#ifndef ENGINNIT_GRAPHICS_EXTENDEDRECTDRAWER
#define ENGINNIT_GRAPHICS_EXTENDEDRECTDRAWER

#include "BaseDrawer.h"
#include <vector>

namespace Drawer {
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, vector<int> margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, Color c, vector<int> margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, TransformData td, vector<int> margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, TransformData td, Color c, vector<int> margins);
}

#endif