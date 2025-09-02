#include <SFML/Graphics.hpp>
#include <iostream>

#include "Background.h"
#include "FrameRate.h"
#include "Points.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"

enum class GameState
{
    Menu,
    Playing,
    GameOver,
    GameWin
};

static int lastMilestone = 0;
static unsigned int levelNum = 1;

int main()
{
	//-----INITIALIZE-----
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Invaders", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	//-----INITIALIZE-----

    sf::Font font;
    font.loadFromFile("assets/fonts/consola.ttf");

	GameState gameState = GameState::Menu;
    Background background;
	FrameRate frameRate;
	Points points;
	Player player;
	Enemy enemy;
    Level level(sf::Vector2i(50, 50));

    background.Initialize();
	frameRate.Initialize();
    points.Initialize();
	player.Initialize();
    level.Initialize();

	//-----INITIALIZE-----
	
	//-----LOAD-----
	
    background.Load();
	frameRate.Load();
    points.Load();
	player.Load(window);
    level.Load(window, levelNum);

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

            if (gameState == GameState::Menu)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {
                    gameState = GameState::Playing;
                }
            }
            else if (gameState == GameState::GameOver || gameState == GameState::GameWin)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                    gameState = GameState::Menu;
            }

            if (!player.isAlive)
                gameState = GameState::GameOver;

		}	

        window.clear();

        if (player.points >= 3300)
            gameState = GameState::GameWin;

        if (gameState == GameState::Menu)
        {
            sf::Text title;
            title.setFont(font);
            title.setString("Menu");

            float halfWidth = title.getGlobalBounds().width / 2;
            title.setPosition(sf::Vector2f(window.getSize().x / 2 - halfWidth, window.getSize().y / 2 - 50));

            window.draw(title);

            title.setString("Press ENTER to play");

            halfWidth = title.getGlobalBounds().width / 2;
            title.setPosition(sf::Vector2f(window.getSize().x / 2 - halfWidth, window.getSize().y / 2 + 50));

            window.draw(title);

        }
        else if (gameState == GameState::Playing)
        {
            if (player.points / 330 > lastMilestone)
            {
                lastMilestone = player.points / 330;
                levelNum++;
                level.Initialize();
                level.Load(window, levelNum);
            }
            background.Update(deltaTime);
            frameRate.Update(deltaTime);
            points.Update(deltaTime, player.points);
            player.Update(deltaTime, window, level.enemies, level.m_dataLength);
            level.Update(deltaTime);

            background.Draw(window);
            frameRate.Draw(window);
            player.Draw(window);
            points.Draw(window);
            level.Draw(window);
        }
        else if (gameState == GameState::GameOver)
        {
            sf::Text title;
            title.setFont(font);
            title.setString("GAME OVER");

            float halfWidth = title.getGlobalBounds().width / 2;
            title.setPosition(sf::Vector2f(window.getSize().x / 2 - halfWidth, window.getSize().y / 2 - 50));

            window.draw(title);

            title.setString("Press ENTER to return to Menu");

            halfWidth = title.getGlobalBounds().width / 2;
            title.setPosition(sf::Vector2f(window.getSize().x / 2 - halfWidth, window.getSize().y / 2 + 50));

            player.points = 0;
            levelNum = 1;

            window.draw(title);
        }
        else if (gameState == GameState::GameWin)
        {
            sf::Text title;
            title.setFont(font);
            title.setString("YOU WON!");

            float halfWidth = title.getGlobalBounds().width / 2;
            title.setPosition(sf::Vector2f(window.getSize().x / 2 - halfWidth, window.getSize().y / 2 - 50));

            window.draw(title);

            title.setString("Press ENTER to return to Menu");

            halfWidth = title.getGlobalBounds().width / 2;
            title.setPosition(sf::Vector2f(window.getSize().x / 2 - halfWidth, window.getSize().y / 2 + 50));

            player.points = 0;
            levelNum = 1;

            window.draw(title);
        }

		
		//-----UPDATE-----
		
		//-----DRAW-----

		window.display();

		//-----DRAW-----

	}

	return 0;
}
