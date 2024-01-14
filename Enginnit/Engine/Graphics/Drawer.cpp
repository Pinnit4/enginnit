#include "Drawer.h"

void glVertex2f(Vector2f vec) { glVertex2f(vec.x, vec.y); }
void glTexCoord2d(Vector2f vec) { glTexCoord2d(vec.x, vec.y); }


void Drawer::DrawRect2D(Texture tx, Rect2D* rect) {
	DrawRect2D(tx, rect, TransformData(Vector2f::Zero()), Color::White());
}

void Drawer::DrawRect2D(Texture tx, Rect2D* rect, Color c) {
	DrawRect2D(tx, rect, TransformData(Vector2f::Zero()), c);
}

void Drawer::DrawRect2D(Texture tx, Rect2D* rect, TransformData td) {
	DrawRect2D(tx, rect, td, Color::White());
}

void Drawer::DrawRect2D(Texture tx, Rect2D* rect, TransformData td, Color c) {
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, tx.GetID());

	//glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	// First translate, then rotate, then scale
	glRotatef(td.rotation, 0, 0, 1);

	glTranslatef(td.position.x, td.position.y, 0);
	glScalef(td.scale.x, td.scale.y, 1);

	// Set interpolation to nearest to ensure pixel perfection
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Rendering
	glColor4f(c.r, c.g, c.b, c.a);
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

