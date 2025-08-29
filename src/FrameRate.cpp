#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() :
	timer(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
	if (font.loadFromFile("assets/fonts/consola.ttf"))
	{
		std::cout << "FrameRate Consola Font loaded successfully" << std::endl;
		frameRateText.setFont(font);
	}
}

void FrameRate::Update(double deltaTime)
{
	timer += deltaTime;

	if (timer >= 100.0)
	{
		frameRateText.setString
			(
				"FPS: " + 
				std::to_string((int)(1000.0 / deltaTime)) + 
				" frameTime: " + std::to_string((int)deltaTime)
			);
		timer = 0;
	}
}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);
}
