#pragma once
#include <string>

struct LevelData
{
	int version;

	std::string tileSheet = "";
	std::string name = "";

	int levelWidth = 0;
	int levelHeight = 0;

	int tileWidth = 0;
	int tileHeight = 0;

	int dataLength = 0;
	int* data = nullptr;
};


