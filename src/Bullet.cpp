#include "Bullet.h"
#include "Math.h"
#include <iostream>

Bullet::Bullet() :
	m_speed(0), m_size(10, 15), direction(0.f, -1.f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Sprite& sprite, float speed)
{
	m_speed	= speed;

    sf::Vector2f position = sprite.getPosition();

	rectangleShape.setSize(m_size);
	rectangleShape.setPosition(sprite.getGlobalBounds().width / 2 + sprite.getPosition().x - (m_size.x / 2), position.y);
}

void Bullet::Update(float deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * m_speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}
