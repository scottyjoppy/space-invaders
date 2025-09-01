#include <SFML/Graphics.hpp>
#include <iostream>

#include "FrameRate.h"
#include "Points.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"

int main()
{
	//-----INITIALIZE-----
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Invaders", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	//-----INITIALIZE-----
	
	FrameRate frameRate;
	Points points;
	Player player;
	Enemy enemy;
    Level level;

	frameRate.Initialize();
    points.Initialize();
	player.Initialize();
    level.Initialize();

	//-----INITIALIZE-----
	
	//-----LOAD-----
	
	frameRate.Load();
    points.Load();
	player.Load(window);
    level.Load();

	//-----LOAD-----

	//-----GAME LOOP-----
	
	sf::Clock clock;

	while (window.isOpen())
	{	
		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
		
		//-----UPDATE-----
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}	

		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

		frameRate.Update(deltaTime);
        points.Update(deltaTime, player.points);
		player.Update(deltaTime, window, level.enemies, mousePosition, level.m_dataLength);
        level.Update(deltaTime);
		
		//-----UPDATE-----
		
		//-----DRAW-----
		window.clear(sf::Color::Black);

		player.Draw(window);
		frameRate.Draw(window);
        points.Draw(window);
        level.Draw(window);

		window.display();
		//-----DRAW-----

	}

	return 0;
}
