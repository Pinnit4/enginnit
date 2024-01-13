#ifndef ENGINNIT_DEBUG_DRAWER
#define ENGINNIT_DEBUG_DRAWER

#include "../Math/Math.h"
#include "../Graphics/Graphics.h"

#include <iostream>

namespace DebugDrawer {
	void Initialize(Vector2f position, float rotation, Vector2f scale);

	void SetColor(Color c);

	void DrawWireCube(Vector2f ll, Vector2f lr, Vector2f ul, Vector2f ur);
	void DrawWirePolygon(vector<Vector2f> points);

	void DrawLine(Vector2f a, Vector2f b);
};
#endif