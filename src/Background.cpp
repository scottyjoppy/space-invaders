#include "Background.h"

Background::Background()
{
}

Background::~Background()
{
}

void Background::Initialize()
{
    color = sf::Color(0, 0, 50);
}

void Background::Load()
{
}

void Background::Update(int deltaTime)
{
}

void Background::Draw(sf::RenderWindow& window)
{
    window.clear(color);
}

