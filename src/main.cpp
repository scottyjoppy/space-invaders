#include <SFML/Graphics.hpp>
#include <iostream>

#include "FrameRate.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	//-----INITIALIZE-----
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Invaders", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	//-----INITIALIZE-----
	
	FrameRate frameRate;
	Player player;
	Enemy enemy;

	frameRate.Initialize();
	player.Initialize();
	enemy.Initialize();

	//-----INITIALIZE-----
	
	//-----LOAD-----
	
	frameRate.Load();
	player.Load(window);
	enemy.Load();	

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
		enemy.Update(deltaTime);
		player.Update(deltaTime, window, enemy, mousePosition);
		
		//-----UPDATE-----
		
		//-----DRAW-----
		window.clear(sf::Color::Black);

		player.Draw(window);
		enemy.Draw(window);
		frameRate.Draw(window);

		window.display();
		//-----DRAW-----

	}

	return 0;
}
