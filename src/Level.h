#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "LevelLoader.h"
#include "LevelData.h"
#include "Enemy.h"

class Level
{
	private:
        Enemy* enemies;

		sf::Texture tileSheetTexture;

		LevelData ld;
        LevelLoader levelLoader;

	public:
		Level();
		~Level();

		void Initialize();
		void Load();
		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);
};

