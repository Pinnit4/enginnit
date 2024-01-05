#ifndef ENGINNIT_ASSETFILE
#define ENGINNIT_ASSETFILE

#include <string>
#include <vector>
#include <functional>

using namespace std;

class AssetFile {
public:
	static void ReadAssetFile(string filePath, function<void(string, vector<string>)> parseCallback);
	static void WriteAssetFile(string filePath, vector<vector<string>> data);
	static vector<string> GetLineSplitted(string line, char value);
private:
};

#endif