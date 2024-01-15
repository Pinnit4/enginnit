#include "ExtendedRect2DDrawer.h"

void DrawRect2DSegment(Texture tx, Vector2f ll_loc, Vector2f tr_loc, Vector2i an_min, Vector2i an_max, TransformData td, Color c);

void Drawer::DrawRect2DWithMargins(Texture tx, Rect2D* rect, vector<int> margins) {
	DrawRect2DWithMargins(tx, rect, TransformData::Default(), Color::White(), margins);
}
void Drawer::DrawRect2DWithMargins(Texture tx, Rect2D* rect, Color c, vector<int> margins) {
	DrawRect2DWithMargins(tx, rect, TransformData::Default(), c, margins);
}
void Drawer::DrawRect2DWithMargins(Texture tx, Rect2D* rect, TransformData td, vector<int> margins) {
	DrawRect2DWithMargins(tx, rect, td, Color::White(), margins);
}
void Drawer::DrawRect2DWithMargins(Texture tx, Rect2D* rect, TransformData td, Color c, vector<int> margins) {

	bool multipleDraw = false;
	for (float m : margins) {
		if (m > 0) {
			multipleDraw = true;
			break;
		}
	}

	if (!multipleDraw) {
		Drawer::DrawRect2D(tx, rect, td, c);
		return;
	}

	vector<Vector2f> points = rect->GetPoints();
	vector<Vector2i> anchors = tx.GetAllAnchors();

	Vector2f ll_loc, tr_loc;
	Vector2i an_min, an_max;

	// Lower left corner draw
	ll_loc = points[0];
	tr_loc = Vector2f(points[0].x + margins[0], points[0].y + margins[3]);

	an_min = anchors[0];
	an_max = Vector2i(anchors[0].x + margins[0], anchors[0].y + margins[3]);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);

	// Left side draw
	ll_loc = Vector2f(points[0].x, points[0].y + margins[3]);
	tr_loc = Vector2f(points[0].x + margins[0], points[1].y - margins[1]);

	an_min = Vector2i(anchors[0].x, anchors[0].y + margins[3]);
	an_max = Vector2i(anchors[0].x + margins[0], anchors[1].y - margins[1]);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);

	// Upper left corner draw
	ll_loc = Vector2f(points[1].x, points[1].y - margins[1]);
	tr_loc = Vector2f(points[1].x + margins[0], points[1].y);

	an_min = Vector2i(anchors[1].x, anchors[1].y - margins[1]);
	an_max = Vector2i(anchors[1].x + margins[0], anchors[1].y);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);

	// Upper side draw
	ll_loc = Vector2f(points[1].x + margins[0], points[1].y - margins[1]);
	tr_loc = Vector2f(points[2].x - margins[2], points[2].y);

	an_min = Vector2i(anchors[1].x + margins[0], anchors[1].y - margins[1]);
	an_max = Vector2i(anchors[2].x - margins[2], anchors[2].y);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);

	// Upper right corner draw
	ll_loc = Vector2f(points[2].x - margins[2], points[2].y - margins[1]);
	tr_loc = points[2];

	an_min = Vector2i(anchors[2].x - margins[2], anchors[2].y - margins[1]);
	an_max = Vector2i(anchors[2].x, anchors[2].y);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);

	// Right side draw
	ll_loc = Vector2f(points[2].x - margins[2], points[3].y + margins[3]);
	tr_loc = Vector2f(points[2].x, points[2].y - margins[1]);

	an_min = Vector2i(anchors[2].x - margins[2], anchors[3].y + margins[3]);
	an_max = Vector2i(anchors[2].x, anchors[2].y - margins[1]);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);

	// Lower right corner draw
	ll_loc = Vector2f(points[3].x - margins[2], points[3].y);
	tr_loc = Vector2f(points[3].x, points[3].y + margins[3]);

	an_min = Vector2i(anchors[3].x - margins[2], anchors[3].y);
	an_max = Vector2i(anchors[3].x, anchors[3].y + margins[3]);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);

	// Lower side draw
	ll_loc = Vector2f(points[0].x + margins[0], points[0].y);
	tr_loc = Vector2f(points[3].x - margins[2], points[3].y + margins[3]);

	an_min = Vector2i(anchors[0].x + margins[0], anchors[0].y);
	an_max = Vector2i(anchors[3].x - margins[2], anchors[3].y + margins[3]);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);

	// Center draw
	ll_loc = Vector2f(points[0].x + margins[0], points[0].y + margins[3]);
	tr_loc = Vector2f(points[2].x - margins[2], points[2].y - margins[1]);

	an_min = Vector2i(anchors[0].x + margins[0], anchors[0].y + margins[3]);
	an_max = Vector2i(anchors[2].x - margins[2], anchors[2].y - margins[1]);

	DrawRect2DSegment(tx, ll_loc, tr_loc, an_min, an_max, td, c);
}

void DrawRect2DSegment(Texture tx, Vector2f ll_loc, Vector2f tr_loc, Vector2i an_min, Vector2i an_max, TransformData td, Color c) {
	if (ll_loc.x == tr_loc.x || ll_loc.y == tr_loc.y) return; // Not valid parameters for a quad

	Vector2f center = Vector2f((ll_loc.x + tr_loc.x) / 2, (ll_loc.y + tr_loc.y) / 2);
	Vector2f size = Vector2f(tr_loc.x - ll_loc.x, tr_loc.y - ll_loc.y);

	Rect2D newR = Rect2D(center, size);
	Texture newTx = Texture(tx);

	newTx.SetAnchors(an_min, an_max);

	Drawer::DrawRect2D(newTx, &newR, td, c);
}