#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Game.hpp"
#include "DEFINITIONS.hpp"


namespace DN
{
    class Bird
    {
    public:
        Bird(GameDataRef data);
        
        void DrawBird();
        
        void Animate(float dt);
        
        void Update(float dt);
        
        void Tap();
        
        const sf::Sprite &GetSprite() const;
        
    private:
        GameDataRef _data;
        
        sf::Sprite _birdSprite;
        std::vector<sf::Texture> _animationFrames;
        
        unsigned int _animationIterator;
        
        sf::Clock _clock;
        sf::Clock _movementClock;
        
        float _birdSpeed;
        float _birdAngle;
    };
}
