#ifndef ENGINNIT_ASSET_FACTORY
#define ENGINNIT_ASSET_FACTORY

#include "../Asset.h"
#include <string>

using namespace std;

namespace AssetFactory {
	Asset* CreateAsset(string type, string filePath);
};

#endif