#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace DN
{
    class Land
    {
    public:
        Land(GameDataRef data);
        
        void MoveLand(float dt);
        void DrawLand();
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> _landSprites;
    };
}
