#include "Points.h"
#include <iostream>

Points::Points() :
    timer(0)
{
}

Points::~Points()
{
}

void Points::Initialize()
{
}

void Points::Load()
{
	if (font.loadFromFile("assets/fonts/consola.ttf"))
	{
		std::cout << "Points Consola Font loaded successfully" << std::endl;
		pointsText.setFont(font);
        pointsText.setPosition(sf::Vector2f(0, 50));
	}
}

void Points::Update(double deltaTime, int& points)
{
	timer += deltaTime;

	if (timer >= 100.0)
	{
		pointsText.setString
			(
				"Points: " + std::to_string(points)
			);
		timer = 0;
	}
}

void Points::Draw(sf::RenderWindow& window)
{
	window.draw(pointsText);
}
