#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
	private:
		sf::RectangleShape rectangleShape;
		sf::Vector2f direction;
        sf::Vector2f m_size;
		float m_speed;

	public:
		Bullet();
		~Bullet();

		void Initialize(const sf::Sprite& sprite, float speed);
		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);

		inline const sf::FloatRect GetGlobalBounds() { return rectangleShape.getGlobalBounds(); }
		inline const sf::Vector2f GetPosition() { return rectangleShape.getPosition(); }
};
