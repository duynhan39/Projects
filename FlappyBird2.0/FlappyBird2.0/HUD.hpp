#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace DN
{
    class HUD {
    public:
        HUD( GameDataRef data);
        
        void Draw();
        void UpdataScore(int score);
        
    private:
        GameDataRef _data;
        sf::Text _scoreText;
    };
}
