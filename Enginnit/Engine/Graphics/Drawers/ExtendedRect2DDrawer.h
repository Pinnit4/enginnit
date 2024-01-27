#ifndef ENGINNIT_GRAPHICS_EXTENDEDRECTDRAWER
#define ENGINNIT_GRAPHICS_EXTENDEDRECTDRAWER

#include "BaseDrawer.h"
#include <vector>

namespace Drawer {
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, Vector4i margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, Color c, Vector4i margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, Spatial2D sp, Vector4i margins);
	void DrawRect2DWithMargins(Texture tx, Rect2D* rect, Spatial2D sp, Color c, Vector4i margins);
}

#endif