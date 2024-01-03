#ifndef ENGINNIT_ASSETFILE
#define ENGINNIT_ASSETFILE

#include <string>
#include <vector>
#include <functional>

using namespace std;

class AssetFile {
public:
	static void ReadAssetFile(string filePath, function<void(string, string)> parseCallback);
	static void WriteAssetFile(string filePath, vector<vector<string>> data);
private:
	static vector<string> GetLineSplitted(string line, char value);
};

#endif