#include "DebugDrawer.h"

void DebugDrawer::Initialize(Vector2f position, float rotation, Vector2f scale) {
	glLoadIdentity();

	glRotatef(rotation, 0, 0, 1);
	glTranslatef(position.x, position.y, 0);
	glScalef(scale.x, scale.y, 1);
}

void DebugDrawer::SetColor(Color c) { glColor4f(c.r, c.g, c.b, c.a); }

void DebugDrawer::DrawWireCube(Vector2f ll, Vector2f lr, Vector2f ul, Vector2f ur) {
	glBegin(GL_LINES);

	glVertex2f(ll.x, ll.y);
	glVertex2f(lr.x, lr.y);

	glVertex2f(lr.x, lr.y);
	glVertex2f(ur.x, ur.y);

	glVertex2f(ur.x, ur.y);
	glVertex2f(ul.x, ul.y);

	glVertex2f(ul.x, ul.y);
	glVertex2f(ll.x, ll.y);

	glEnd();
}

void DebugDrawer::DrawWirePolygon(vector<Vector2f> points) {
	glBegin(GL_LINES);

	for (unsigned int i = 0; i < points.size(); i++)
	{
		Vector2f a = points[i];
		Vector2f b = ((i == (points.size() - 1)) ? points[0] : points[i + 1]);

		glVertex2f(a.x, a.y);
		glVertex2f(b.x, b.y);		
	}

	glEnd();
}

void DebugDrawer::DrawLine(Vector2f a, Vector2f b) {
	glBegin(GL_LINES);

	glVertex2f(a.x, a.y);
	glVertex2f(b.x, b.y);

	glEnd();
}