#ifndef TILESETEDITOR_BASE
#define TILESETEDITOR_BASE

using namespace std;

class TilesetEditor {
public:
	TilesetEditor();
	~TilesetEditor();

	void Start();
	void Tick(double deltaTime);
};

#endif
