#ifndef MAPEDITOR_BASE
#define MAPEDITOR_BASE

using namespace std;

class MapEditor {
public:
	MapEditor();
	~MapEditor();

	void Start();
	void Tick(double deltaTime);
};

#endif
