#include <iostream>
#include "Level.h"
#include "Math.h"

Level::Level() :
    enemies(nullptr)
{
}

Level::~Level()
{
}

void Level::Initialize()
{
}

void Level::Load()
{
    levelLoader.Load("assets/levels/level1.txt", ld);

    tileSheetTexture.loadFromFile(ld.tileSheet);

    enemies = new Enemy[ld.dataLength];

    sf::Vector2f scale = Math::CalcScale(sf::Vector2i(ld.tileWidth, ld.tileHeight));

    for (size_t y = 0; y < ld.levelHeight;y++)
    {
        for (size_t x = 0; x < ld.levelWidth; x++)
        {
            int i = x + y * ld.levelWidth;
            int enemyTypeIndex = ld.data[i];

            enemies[i].Initialize
            (
             tileSheetTexture,
             enemyTypeIndex,
             sf::Vector2f(x * ld.tileWidth, y * ld.tileHeight),
             sf::Vector2f(ld.tileWidth, ld.tileHeight),
             scale,
             ld.levelWidth
            );
        }
    }

    std::cout << "Level file loaded with " << ld.dataLength << " enemies" << std::endl;
}

void Level::Update(float deltaTime)
{
}

void Level::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < ld.dataLength; i++)
    {
        window.draw(enemies[i].sprite);
    }
}

