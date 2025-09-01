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

	public:
		sf::Sprite sprite;

	public:
		Player();
		~Player();
		void Initialize();
		void Load(sf::RenderWindow& window);
		void Update(float deltaTime, sf::RenderWindow& window, Enemy* enemies, sf::Vector2f& mousePosition, int dataLength);
		void Draw(sf::RenderWindow& window);	
};
