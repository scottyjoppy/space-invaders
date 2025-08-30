#pragma once
#include <iostream>
#include "LevelData.h"

class LevelLoader
{
	public:
		void Load(std::string filename, LevelData& levelData);
		void Save(std::string filename);
};

