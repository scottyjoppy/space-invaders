#include <iostream>

#include "Player.h"
#include "Math.h"

Player::Player() :
	playerSpeed(1.0f), maxFireRate(150), fireRateTimer(0), tileWidth(80), tileHeight(80), focused(false), points(0)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(tileWidth, tileHeight);
}

void Player::Load(sf::RenderWindow& window)
{
	if (texture.loadFromFile("assets/player/textures/spaceship.png"))
	{
		std::cout << "Ship sprite loaded!" << std::endl;
        scale = Math::CalcScale(size);

		sprite.setTexture(texture);

		sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
		sprite.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y - size.y * scale.y));

		sprite.setScale(sf::Vector2f(scale.x, scale.y));
		boundingRectangle.setSize(sf::Vector2f(size.x * scale.x, size.y * scale.y));
	}
	else
	{
		std::cout <<"Ship sprite failed to load!" << std::endl;
	}
}

void Player::Update(float deltaTime, sf::RenderWindow& window, Enemy* enemies, sf::Vector2f& mousePosition, int dataLength)
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f position = sprite.getPosition();
    fireRateTimer += deltaTime;

    if (window.hasFocus())
        focused = true;
    else
        focused = false;

    if (focused)
    {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
            position.x -= playerSpeed * deltaTime; 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            position.x += playerSpeed * deltaTime;

        float halfWidth = (size.x * scale.y) / 2.0f;
        if (position.x < halfWidth)
            position.x = halfWidth;
        if (position.x > windowSize.x - (halfWidth * 3))
            position.x = windowSize.x - (halfWidth * 3);


        sprite.setPosition(position);


        if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::L)) && fireRateTimer >= maxFireRate && focused)
        {
            bullets.push_back(Bullet());
            int i = bullets.size() - 1;

            bullets[i].Initialize(sprite, 0.5f);

            fireRateTimer = 0;
        }
    }

    for (auto i = bullets.begin(); i != bullets.end(); )
    {
        i->Update(deltaTime);

        bool remove = false;

        for (size_t a = 0; a < dataLength; a++)
        {
            if (enemies[a].health > 0)
            {
                if (Math::DidRectCollide(i->GetGlobalBounds(), enemies[a].sprite.getGlobalBounds()))
                {
                    enemies[a].ChangeHealth(-10);
                    remove = true;

                    points += 10;
                    break;
                }
            }

        }

        sf::Vector2f pos = i->GetPosition();
        if (pos.x < 0 || pos.x > windowSize.x || pos.y < 0 || pos.y > windowSize.y)
            remove = true;

        if (remove)
            i = bullets.erase(i);
        else
            ++i;

    }

    boundingRectangle.setPosition(sprite.getPosition());
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{	
		bullets[i].Draw(window);
	}
}
