#pragma once
#include <SFML/Graphics.hpp>

class Points
{
	private:
		sf::Text pointsText;
		sf::Font font;
        
        float timer;
	
	public:
		Points();
		~Points();

		void Initialize();
		void Load();
		void Update(double deltaTime, int& points);
		void Draw(sf::RenderWindow& window);
};
