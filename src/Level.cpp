#include <iostream>
#include "Level.h"
#include "Math.h"

Level::Level(sf::Vector2i offset) :
    enemies(nullptr), m_dataLength(0), screenSize(0, 0), offsetX(offset.x), offsetY(offset.y)
{
}

Level::~Level()
{
    delete[] enemies;
}

void Level::Initialize()
{
}

void Level::Load(sf::RenderWindow& window, unsigned int levelNum)
{
    levelLoader.Load("assets/levels/level1.txt", ld);

    enemies = new Enemy[ld.dataLength];

    m_dataLength = ld.dataLength;

    if (tileSheetTexture.loadFromFile(ld.tileSheet))
    {
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
                     sf::Vector2f(x * ld.tileWidth + offsetX, y * ld.tileHeight + offsetY),
                     sf::Vector2f(ld.tileWidth, ld.tileHeight),
                     scale,
                     ld.sheetWidth,
                     110 - levelNum * 10
                    );
                enemies[i].Load();
            }
        }
    }

    std::cout << "Level file loaded with " << ld.dataLength << " enemies" << std::endl;
}

void Level::Update(float deltaTime)
{
    for (size_t i = 0; i < ld.dataLength; i++)
        enemies[i].Update(deltaTime);
}

void Level::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < ld.dataLength; i++)
        enemies[i].Draw(window);
}

