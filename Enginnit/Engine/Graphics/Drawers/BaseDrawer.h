#ifndef ENGINNIT_GRAPHICS_BASEDRAWER
#define ENGINNIT_GRAPHICS_BASEDRAWER

#include "DrawerInternal.h"
#include "../Textures/Texture.h"

namespace Drawer {
	void DrawRect2D(Texture tx, Rect2D* rect);
	void DrawRect2D(Texture tx, Rect2D* rect, Color c);
	void DrawRect2D(Texture tx, Rect2D* rect, Spatial2D sp);
	void DrawRect2D(Texture tx, Rect2D* rect, Spatial2D sp, Color c);

	void DrawWirePolygon(Polygon* p);
	void DrawWirePolygon(Polygon* p, Color c);
	void DrawWirePolygon(Polygon* p, Spatial2D sp);
	void DrawWirePolygon(Polygon* p, Spatial2D sp, Color c);

	void DrawLine(Vector2f a, Vector2f b);
	void DrawLine(Vector2f a, Vector2f b, Color c);
}

#endif