#include <iostream>
#include "Enemy.h"
#include "Math.h"

Enemy::Enemy() :
    health(10), m_enemySpeed(1.0f), m_tickRate(0), m_type(0), xDirection(true), distanceMoved(0), moveDown(false)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize(sf::Texture& texture, int enemyTypeIndex, sf::Vector2f position, sf::Vector2f tileSize, sf::Vector2f scale, int sheetWidth, float tickRate)
{
    m_tickRate = tickRate;
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
        healthText.setPosition(sprite.getPosition());

    if (distanceMoved == 550 && !moveDown)
    {
        xDirection = !xDirection;
        distanceMoved = 0;
        moveDown = true;
    }

    m_enemySpeed += deltaTime;

    if (m_enemySpeed >= m_tickRate)
    {
        distanceMoved += 10;
        m_enemySpeed = 0;

        if (xDirection && !moveDown)
            sprite.setPosition(sf::Vector2f(sprite.getPosition().x + 10, sprite.getPosition().y));
        else if (!xDirection && !moveDown)
            sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 10, sprite.getPosition().y));

        if (moveDown)
        {
            sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 100));
            moveDown = false;
        }
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

void Enemy::ChangeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health));
}

