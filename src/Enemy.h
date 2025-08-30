#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
	private:
		sf::Texture texture;

		sf::Text healthText;
		sf::Font font;

		int tileWidth;
		int tileHeight;
		sf::Vector2f scale;


        float m_tickRate;
        float m_enemySpeed;

	public:
		sf::Sprite sprite;

		sf::RectangleShape boundingRectangle;
		sf::Vector2i size;
		int health;

	public:
		Enemy();
		~Enemy();

		void ChangeHealth(int hp);

		void Initialize(sf::Texture& texture, int enemyIndex, sf::Vector2f position, sf::Vector2f tileSize, sf::Vector2f scale, int levelWidth);
		void Load();
		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);	
};
