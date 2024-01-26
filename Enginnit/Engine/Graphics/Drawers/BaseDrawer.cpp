#include "BaseDrawer.h"

void Drawer::DrawRect2D(Texture tx, Rect2D* rect) { DrawRect2D(tx, rect, Spatial2D(), Color::White()); }
void Drawer::DrawRect2D(Texture tx, Rect2D* rect, Color c) { DrawRect2D(tx, rect, Spatial2D(), c); }
void Drawer::DrawRect2D(Texture tx, Rect2D* rect, Spatial2D sp) { DrawRect2D(tx, rect, sp, Color::White()); }

void Drawer::DrawRect2D(Texture tx, Rect2D* rect, Spatial2D sp, Color c) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tx.GetID());

	glLoadIdentity();

	glTransform(sp);
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

void Drawer::DrawWirePolygon(Polygon* rect) { DrawWirePolygon(rect, Spatial2D(), Color::White()); }
void Drawer::DrawWirePolygon(Polygon* rect, Color c) { DrawWirePolygon(rect, Spatial2D(), c); }
void Drawer::DrawWirePolygon(Polygon* rect, Spatial2D sp) { DrawWirePolygon(rect, sp, Color::White()); }

void Drawer::DrawWirePolygon(Polygon* rect, Spatial2D td, Color c) {
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

	glTransform(Spatial2D());
	glColor(c);

	glBegin(GL_LINES);
	glLine(a, b);
	glEnd();
}
