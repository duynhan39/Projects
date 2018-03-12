#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace DN
{
    class Bird
    {
    public:
        Bird(GameDataRef data);
        
        void DrawBird();
        
    private:
        GameDataRef _data;
        sf::Sprite _birdSprite;
    };
}
