#pragma once
#include <string>

struct MapData
{
	int version;

	std::string tileSheet = "";
	std::string name = "";

	int mapWidth = 0;
	int mapHeight = 0;

	int tileWidth = 0;
	int tileHeight = 0;

	int dataLength = 0;
	int* data = nullptr;
};

