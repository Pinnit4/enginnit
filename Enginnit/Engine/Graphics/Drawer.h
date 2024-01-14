#ifndef ENGINNIT_GRAPHICS_DRAWER
#define ENGINNIT_GRAPHICS_DRAWER

#include "../Math/Math.h"
#include "../Math/TransformData.h"

#include "GraphicsInternal.h"
#include "GraphicsManager.h"

#include "Texture.h"

namespace Drawer {
	void DrawRect2D(Texture tx, Rect2D* rect);
	void DrawRect2D(Texture tx, Rect2D* rect, Color c);
	void DrawRect2D(Texture tx, Rect2D* rect, TransformData td);
	void DrawRect2D(Texture tx, Rect2D* rect, TransformData td, Color c);
}

#endif