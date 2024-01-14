#include "Drawer.h"

void glColor(Color c) { glColor4f(c.r, c.g, c.b, c.a); }

void glVertex2f(Vector2f vec) { glVertex2f(vec.x, vec.y); }
void glVertex2d(Vector2d vec) { glVertex2d(vec.x, vec.y); }

void glTexCoord2d(Vector2f vec) { glTexCoord2d(vec.x, vec.y); }

void glLine2f(Vector2f a, Vector2f b) { glVertex2f(a); glVertex2f(b); }
void glLine2d(Vector2d a, Vector2d b) { glVertex2d(a); glVertex2d(b); }

void glLinesClosed(vector<Vector2f> points) {
	for (unsigned int i = 0; i < points.size(); i++)
	{
		Vector2f a = points[i];
		Vector2f b = ((i == (points.size() - 1)) ? points[0] : points[i + 1]);

		glLine2f(a, b);
	}
}

void glLinesOpen(vector<Vector2f> points) {
	for (unsigned int i = 0; i < points.size() - 1; i++)
	{
		Vector2f a = points[i];
		Vector2f b = points[i + 1];

		glLine2f(a, b);
	}
}


void glTransform(TransformData td) {
	// First translate, then rotate, then scale
	glRotatef(td.rotation, 0, 0, 1);
	glTranslatef(td.position.x, td.position.y, 0);
	glScalef(td.scale.x, td.scale.y, 1);
}

void glTextureFilter(GLint filter) {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
}

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

	// Set quad vertex positions (in local pos, since we already "moved" the matrix right above us in glTranslatef)
	Vector2d anchorMin = tx.GetAnchorMinPercent();
	Vector2d anchorMax = tx.GetAnchorMaxPercent();

	vector<Vector2f> points = rect->GetPoints();

	glTexCoord2d(anchorMin.x, anchorMin.y);		glVertex2f(points[0]);
	glTexCoord2d(anchorMin.x, anchorMax.y);		glVertex2f(points[1]);
	glTexCoord2d(anchorMax.x, anchorMax.y);		glVertex2f(points[2]);
	glTexCoord2d(anchorMax.x, anchorMin.y);		glVertex2f(points[3]);

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

	glLine2f(a, b);

	glEnd();
}
