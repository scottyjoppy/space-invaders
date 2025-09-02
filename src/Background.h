#pragma once

#include <SFML/Graphics.hpp>

class Background
{
    public:
        sf::Color color;
        sf::CircleShape circle;

    public:
        Background();
        ~Background();

        void Initialize();
        void Load();
        void Update(int deltaTime);
		void Draw(sf::RenderWindow& window);	
};
