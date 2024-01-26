#ifndef ENGINNIT_GRAPHICS_DRAWERINTERNAL
#define ENGINNIT_GRAPHICS_DRAWERINTERNAL

#include "../GraphicsInternal.h"
#include "../GraphicsManager.h"

namespace Drawer {
	void glColor(Color c);

	void glVertex(Vector2f vec);
	void glVertex(Vector2d vec);

	void glTexCoord(Vector2f vec);
	void glTexCoord(Vector2d vec);

	void glLine(Vector2f a, Vector2f b);
	void glLine(Vector2d a, Vector2d b);

	void glLinesClosed(vector<Vector2f> points);
	void glLinesOpen(vector<Vector2f> points);

	void glTransform(TransformData td);
	void glTextureFilter(GLint filter);
}

#endif