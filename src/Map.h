#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "MapLoader.h"
#include "MapData.h"
#include "Tile.h"

class Map
{
	private:
		sf::Texture tileSheetTexture;
	
		std::vector<Tile> tiles;

		MapLoader mapLoader;
		MapData md;

		sf::Vector2i size;

		sf::Vector2f scale;

		int totalTiles;

		int totalTilesX;
		int totalTilesY;

		sf::Sprite* mapSprites;

	public:
		Map();
		~Map();

		void Initialize();
		void Load();
		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);
};
