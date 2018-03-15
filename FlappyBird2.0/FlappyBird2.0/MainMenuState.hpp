#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace DN
{
    class MainMenuState: public State
    {
    public:
        MainMenuState(GameDataRef data);
        
        void Init();
        
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        
    private:
        GameDataRef _data;
        
        sf::Clock _clock;
        
        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _playButton;
        
    };
}

