#include "DrawerInternal.h"

void Drawer::glColor(Color c) { glColor4f(c.r, c.g, c.b, c.a); }

void Drawer::glVertex(Vector2f vec) { glVertex2f(vec.x, vec.y); }
void Drawer::glVertex(Vector2d vec) { glVertex2d(vec.x, vec.y); }

void Drawer::glTexCoord(Vector2f vec) { glTexCoord2f(vec.x, vec.y); }
void Drawer::glTexCoord(Vector2d vec) { glTexCoord2d(vec.x, vec.y); }

void Drawer::glLine(Vector2f a, Vector2f b) { glVertex(a); glVertex(b); }
void Drawer::glLine(Vector2d a, Vector2d b) { glVertex(a); glVertex(b); }

void Drawer::glLinesClosed(vector<Vector2f> points) {
	for (unsigned int i = 0; i < points.size(); i++)
	{
		Vector2f a = points[i];
		Vector2f b = ((i == (points.size() - 1)) ? points[0] : points[i + 1]);

		glLine(a, b);
	}
}

void Drawer::glLinesOpen(vector<Vector2f> points) {
	for (unsigned int i = 0; i < points.size() - 1; i++)
	{
		Vector2f a = points[i];
		Vector2f b = points[i + 1];

		glLine(a, b);
	}
}

void Drawer::glTransform(Spatial2D sp) {
	// First translate, then rotate, then scale
	glRotatef(sp.rotation, 0, 0, 1);
	glTranslatef(sp.position.x, sp.position.y, 0);
	glScalef(sp.scale.x, sp.scale.y, 1);
}

void Drawer::glTextureFilter(GLint filter) {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
}