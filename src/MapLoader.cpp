#include "MapLoader.h"

#include <fstream>
#include <string>
#include <algorithm>

void MapLoader::Load(std::string filename, MapData& mapData)
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
				if (line == "[Map]")
				{
					isMapValid = true;
					continue;
				}
				else
				{
					std::cout << "rmap file " << filename << " is not valid" << std::endl;
					break;
				}
			}
			
			try
			{
				int count = line.find("=");
				std::string variable = line.substr(0, count);
				std::string value = line.substr(count + 1);

				if (variable == "version")
					mapData.version = std::stoi(value);
				else if (variable == "tile-sheet")
					mapData.tileSheet = value;
				else if (variable == "name")
					mapData.name = value;
				else if (variable == "map-width")
					mapData.mapWidth = std::stoi(value);
				else if (variable == "map-height")
					mapData.mapHeight = std::stoi(value);
				else if (variable == "tile-width")
					mapData.tileWidth = std::stoi(value);
				else if (variable == "tile-height")
					mapData.tileHeight = std::stoi(value);
				else if (variable == "data")
				{
					mapData.dataLength = std::count(value.begin(), value.end(), ',') + 1;
					mapData.data = new int[mapData.dataLength];

					int offset = 0;

					for (size_t i = 0; i < mapData.dataLength; i++)
					{
						int count = value.find(",", offset);
						std::string mapIndex = value.substr(offset, count - offset);
						
						mapData.data[i] = std::stoi(mapIndex);

						offset = count + 1;
					}
					if (mapData.dataLength != mapData.mapWidth * mapData.mapHeight)
					{
						std::cerr 	<< "ERROR: Map data length (" 
									<< mapData.dataLength
									<< ") does not match mapWidth*mapHeight (" 
									<< mapData.mapWidth * mapData.mapHeight 
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

void MapLoader::Save(std::string filename)
{
}
