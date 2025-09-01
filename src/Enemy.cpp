#include <iostream>
#include "Enemy.h"
#include "Math.h"

Enemy::Enemy() :
	health(100), m_enemySpeed(1.0f), m_tickRate(1000), m_type(0)
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

void Enemy::Initialize(sf::Texture& texture, int enemyTypeIndex, sf::Vector2f position, sf::Vector2f tileSize, sf::Vector2f scale, int sheetWidth)
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

    int ix = enemyTypeIndex % sheetWidth; 
    int iy = enemyTypeIndex / sheetWidth;

    sprite.setTexture(texture);
    sprite.setScale(scale);
    sprite.setTextureRect(sf::IntRect(ix * tileSize.x, iy * tileSize.y, tileSize.x, tileSize.y));
    sprite.setPosition(sf::Vector2f(position.x * scale.x, position.y * scale.y));

    boundingRectangle.setSize(sf::Vector2f(size.x * scale.x, size.y * scale.y));
}

void Enemy::Load()
{
	if (font.loadFromFile("assets/fonts/consola.ttf"))
	{
		healthText.setFont(font);
        healthText.setCharacterSize(10);
		healthText.setString(std::to_string(health));
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
