#include "AssetFile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

void AssetFile::ReadAssetFile(string filePath, function<void (string, string)> parseCallback) {
	fstream f;
	f.open(filePath, ios::in);
	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			vector<string> splitLine = GetLineSplitted(line, ':');
			if (splitLine.size() < 2) {
				cout << "line size was less than 2: " << splitLine.size() << endl;
				continue;
			}
			string id = splitLine[0];
			string value = splitLine[1];
			parseCallback(id, value);
		}

		f.close();
	}
}

void AssetFile::WriteAssetFile(string filePath, vector<vector<string>> data) {
	fstream f;
	f.open(filePath, ios::out);
	if (f.is_open()) {
		for (unsigned int i = 0; i < data.size(); i++) {
			vector<string> lineVec = data[i];
			string lineString = "";

			for (unsigned int j = 0; j < lineVec.size(); j++) {
				lineString += lineVec[j];
				if (j < lineVec.size() - 1)
					lineString += ":";
			}

			if (i < data.size() - 1)
				lineString += "\n";

			f << lineString;
		}
		f.close();
	}
}

vector<string> AssetFile::GetLineSplitted(string line, char value) {
	stringstream test(line);
	string segment;
	vector<string> seglist;

	while (getline(test, segment, value))
	{
		seglist.push_back(segment);
	}

	return seglist;
}