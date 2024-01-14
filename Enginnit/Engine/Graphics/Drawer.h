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

	void DrawWirePolygon(Polygon* p);
	void DrawWirePolygon(Polygon* p, Color c);
	void DrawWirePolygon(Polygon* p, TransformData td);
	void DrawWirePolygon(Polygon* p, TransformData td, Color c);

	void DrawLine(Vector2f a, Vector2f b);
	void DrawLine(Vector2f a, Vector2f b, Color c);
}

#endif