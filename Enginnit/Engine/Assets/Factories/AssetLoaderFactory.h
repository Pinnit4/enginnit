#ifndef ENGINNIT_ASSET_LOADER_FACTORY
#define ENGINNIT_ASSET_LOADER_FACTORY

#include "../AssetLoader.h"
#include <string>

using namespace std;

namespace AssetLoaderFactory {
	AssetLoader* GetAssetLoader(string type);
};

#endif