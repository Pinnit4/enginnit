#include "BaseDrawer.h"

void Drawer::DrawRect2D(Texture tx, Rect2D* rect) { DrawRect2D(tx, rect, TransformData::Default(), Color::White()); }
void Drawer::DrawRect2D(Texture tx, Rect2D* rect, Color c) { DrawRect2D(tx, rect, TransformData::Default(), c); }
void Drawer::DrawRect2D(Texture tx, Rect2D* rect, TransformData td) { DrawRect2D(tx, rect, td, Color::White()); }

void Drawer::DrawRect2D(Texture tx, Rect2D* rect, TransformData td, Color c) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tx.GetID());

	glLoadIdentity();

	glTransform(td);
	glColor(c);

	glTextureFilter(GL_NEAREST);

	glBegin(GL_QUADS);

	vector<Vector2f> points = rect->GetPoints();
	vector<Vector2d> anchors = tx.GetAllAnchorsPercent();

	for (unsigned int i = 0; i < points.size() && i < anchors.size(); i++) {
		glTexCoord(anchors[i]);		glVertex(points[i]);
	}

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Drawer::DrawWirePolygon(Polygon* rect) { DrawWirePolygon(rect, TransformData::Default(), Color::White()); }
void Drawer::DrawWirePolygon(Polygon* rect, Color c) { DrawWirePolygon(rect, TransformData::Default(), c); }
void Drawer::DrawWirePolygon(Polygon* rect, TransformData td) { DrawWirePolygon(rect, td, Color::White()); }

void Drawer::DrawWirePolygon(Polygon* rect, TransformData td, Color c) {
	glLoadIdentity();

	glTransform(td);
	glColor(c);

	glBegin(GL_LINES);
	glLinesClosed(rect->GetPoints());
	glEnd();
}

void Drawer::DrawLine(Vector2f a, Vector2f b) { DrawLine(a, b, Color::White()); }

void Drawer::DrawLine(Vector2f a, Vector2f b, Color c) {
	glLoadIdentity();

	glTransform(TransformData::Default());
	glColor(c);

	glBegin(GL_LINES);
	glLine(a, b);
	glEnd();
}
