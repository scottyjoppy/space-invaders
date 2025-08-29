#include <iostream>
#include "Enemy.h"
#include "Math.h"

Enemy::Enemy() :
	health(100), tileWidth(32), tileHeight(32), m_enemySpeed(1.0f), m_tickRate(1000)
{
}

Enemy::~Enemy()
{
}

void Enemy::ChangeHealth(int hp)
{
	health += hp;
	healthText.setString(std::to_string(health));
}

void Enemy::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Yellow);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(tileWidth, tileHeight);
}

void Enemy::Load()
{
	if (font.loadFromFile("assets/fonts/consola.ttf"))
	{
		std::cout << "Enemy Consola Font loaded successfully" << std::endl;
		healthText.setFont(font);
		healthText.setString(std::to_string(health));
	}

	if (texture.loadFromFile("assets/enemy/textures/ship1-blue.png"))
	{
		std::cout << "Enemy Images Loaded!" << std::endl;
		sprite.setTexture(texture);

		sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));

		scale = Math::CalcScale(size);

		sprite.setScale(sf::Vector2f(scale.x, scale.y));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		std::cout <<"Enemy image failed to load!" << std::endl;
	}

}

void Enemy::Update(float deltaTime)
{
	if (health > 0)
	{
		boundingRectangle.setPosition(sprite.getPosition());
		healthText.setPosition(sprite.getPosition());
	}
    
    m_enemySpeed += deltaTime;

    if (m_enemySpeed >= m_tickRate)
    {
        sprite.setPosition(sf::Vector2f(sprite.getPosition().x + 10, sprite.getPosition().y));
        m_enemySpeed = 0;
    }
}


void Enemy::Draw(sf::RenderWindow& window)
{
	if (health > 0)
	{
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthText);
	}
}
