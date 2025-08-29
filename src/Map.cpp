#include <iostream>
#include "Map.h"
#include "Math.h"

Map::Map() :
	totalTilesX(0), totalTilesY(0), totalTiles(0), mapSprites(nullptr)
{
}

Map::~Map()
{
	//delete[] mapSprites;
	//delete[] tiles;
}

void Map::Initialize()
{
}

void Map::Load()
{
	mapLoader.Load("assets/world/maps/level1.rmap", md);

	size = sf::Vector2i(md.tileWidth, md.tileHeight);

	mapSprites = new sf::Sprite[md.dataLength];

	if (tileSheetTexture.loadFromFile(md.tileSheet))
	{
		totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;

		totalTiles = totalTilesX * totalTilesY;

		tiles.resize(totalTiles);

		for (size_t y = 0; y < totalTilesY; y++)
		{
			for (size_t x = 0; x < totalTilesX; x++)
			{
				int i = x + y * totalTilesX;

				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * md.tileWidth, y * md.tileHeight);
			}
		}

		std::cout << "Road tileSheet Loaded!" << std::endl;
	}
	else
	{
		std::cout << "Road tileSheet failed to load!" << std::endl;
	}

	for (size_t y = 0; y < md.mapHeight; y++)
	{
		for (size_t x = 0; x < md.mapWidth; x++)
		{
			int i = x + y * md.mapWidth;

			int index = md.data[i];

			mapSprites[i].setTexture(tileSheetTexture);
			mapSprites[i].setTextureRect(sf::IntRect
					(
					 tiles[index].position.x,
					 tiles[index].position.y,
					 md.tileWidth,
					 md.tileHeight
					));

			scale = Math::CalcScale(size);

			mapSprites[i].setScale(sf::Vector2f(scale.x, scale.y));
			mapSprites[i].setPosition(sf::Vector2f(x * md.tileWidth * mapSprites[i].getScale().x, y * md.tileHeight * mapSprites[i].getScale().y));
		}
	}

}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < md.dataLength; i++)
	{
		window.draw(mapSprites[i]);
	}
}
