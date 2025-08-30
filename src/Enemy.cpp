#include <iostream>
#include "Enemy.h"
#include "Math.h"

Enemy::Enemy() :
	health(100), m_enemySpeed(1.0f), m_tickRate(1000)
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

void Enemy::Initialize(sf::Texture& texture, int enemyIndex, sf::Vector2f position, sf::Vector2f tileSize, sf::Vector2f scale, int levelWidth)
{
//	boundingRectangle.setFillColor(sf::Color::Transparent);
//	boundingRectangle.setOutlineColor(sf::Color::Yellow);
//	boundingRectangle.setOutlineThickness(1);

    int ix = enemyIndex % levelWidth; 
    int iy = enemyIndex / levelWidth;

    sprite.setTexture(texture);
    sprite.setScale(scale);
    sprite.setTextureRect(sf::IntRect(ix * tileSize.x, iy * tileSize.y, tileSize.x, tileSize.y));
    sprite.setPosition(sf::Vector2f(position.x * scale.x, position.y * scale.y));
}

void Enemy::Load()
{
//	if (font.loadFromFile("assets/fonts/consola.ttf"))
//	{
//		std::cout << "Enemy Consola Font loaded successfully" << std::endl;
//		healthText.setFont(font);
//		healthText.setString(std::to_string(health));
//	}
//
//	if (texture.loadFromFile("assets/enemy/textures/ship1-blue.png"))
//	{
//		std::cout << "Enemy Images Loaded!" << std::endl;
//		sprite.setTexture(texture);
//
//		sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
//
//		scale = Math::CalcScale(size);
//
//		sprite.setScale(sf::Vector2f(scale.x, scale.y));
//		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
//	}
//	else
//	{
//		std::cout <<"Enemy image failed to load!" << std::endl;
//	}
//
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
