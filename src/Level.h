#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "LevelLoader.h"
#include "LevelData.h"
#include "Enemy.h"

class Level
{
    public:
        Enemy* enemies;
        int m_dataLength;

	private:
		sf::Texture tileSheetTexture;
        int offsetX;
        int offsetY;

        sf::Vector2u screenSize;

		LevelData ld;
        LevelLoader levelLoader;

	public:
		Level(sf::Vector2i offset);
		~Level();

		void Initialize();
		void Load(sf::RenderWindow& window, unsigned int levelNum);
		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);
};

