#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"

class Player
{
	private:
		sf::Texture texture;

		std::vector<Bullet> bullets;

		sf::RectangleShape boundingRectangle;
		sf::Vector2i size;

		float maxFireRate;
		float fireRateTimer;
		float playerSpeed;

		int tileWidth;
		int tileHeight;
		sf::Vector2f scale;

        bool focused;

        sf::Vector2u screenSize;

	public:
		sf::Sprite sprite;
        float padding;
        bool isAlive;

        int points;

	public:
		Player();
		~Player();
		void Initialize();
		void Load(sf::RenderWindow& window);
		void Update(float deltaTime, sf::RenderWindow& window, Enemy* enemies, int dataLength);
		void Draw(sf::RenderWindow& window);	
};
