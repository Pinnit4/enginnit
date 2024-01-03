#ifndef CHARACTER_CONTROLLER2D_ASSET
#define CHARACTER_CONTROLLER2D_ASSET

#include "CharacterController2D.h"

using namespace std;

class CharacterController2DAsset {
public:
	static void SaveToFile(CharacterController2D * cc, string filePath);
	static void LoadFromFile(CharacterController2D* cc, string filePath);
private:

};
#endif