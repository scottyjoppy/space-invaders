#include "LevelLoader.h"

#include <fstream>
#include <string>
#include <algorithm>

void LevelLoader::Load(std::string filename, LevelData& levelData)
{
	std::string line;
	std::ifstream file(filename);

	bool isMapValid = false;

	if (file.is_open())
	{
		while(std::getline(file, line))
		{
			if (!isMapValid)
			{
				if (line == "[Level]")
				{
					isMapValid = true;
					continue;
				}
				else
				{
					std::cout << "Text file " << filename << " is not valid" << std::endl;
					break;
				}
			}
			
			try
			{
				int count = line.find("=");
				std::string variable = line.substr(0, count);
				std::string value = line.substr(count + 1);

				if (variable == "version")
					levelData.version = std::stoi(value);
				else if (variable == "tile-sheet")
					levelData.tileSheet = value;
				else if (variable == "name")
					levelData.name = value;
				else if (variable == "level-width")
					levelData.levelWidth = std::stoi(value);
				else if (variable == "level-height")
					levelData.levelHeight = std::stoi(value);
				else if (variable == "tile-width")
					levelData.tileWidth = std::stoi(value);
				else if (variable == "tile-height")
					levelData.tileHeight = std::stoi(value);
				else if (variable == "data-length")
					levelData.dataLength = std::stoi(value);
				else if (variable == "data")
				{
					levelData.data = new int[levelData.dataLength];

					int offset = 0;

					for (size_t i = 0; i < levelData.dataLength; i++)
					{
						int count = value.find(",", offset);
						std::string levelIndex = value.substr(offset, count - offset);
						
						levelData.data[i] = std::stoi(levelIndex);

						offset = count + 1;
					}
					if (levelData.dataLength != levelData.levelWidth * levelData.levelHeight)
					{
						std::cerr 	<< "ERROR: Level data length (" 
									<< levelData.dataLength
									<< ") does not match levelWidth*levelHeight (" 
									<< levelData.levelWidth * levelData.levelHeight 
									<< ")!" 
									<< std::endl;
					}
				}
			}
			catch (const std::exception&)
			{
				std::cout << "Something went wrong: " << filename << std::endl;
			}
		}
		file.close();
	}
	else
		std::cout << "Unable to open " << filename << std::endl;
}

void LevelLoader::Save(std::string filename)
{
}

