#include "Bird.hpp"

namespace DN
{
    Bird::Bird(GameDataRef data): _data(data)
    {
        _animationIterator = 0;
        
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));
        
        _birdSprite.setTexture(_animationFrames.at(_animationIterator));
        
        _birdSprite.setPosition(_data->window.getSize().x/4 - _birdSprite.getGlobalBounds().width/2, _data->window.getSize().y/2 - _birdSprite.getGlobalBounds().height/2);
        
        sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width/2, _birdSprite.getGlobalBounds().height/2);
        
        _birdSprite.setOrigin(origin);

    }
    
    void Bird::DrawBird()
    {
        _data->window.draw(_birdSprite);
    }
    
    void Bird::Animate(float dt)
    {
        if(_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
        {
            _animationIterator = (_animationIterator+1)%_animationFrames.size();
            
            _birdSprite.setTexture(_animationFrames.at(_animationIterator));
            
            _clock.restart();
        }
    }
    
    void Bird::Update(float dt)
    {
        _birdSpeed = FLYING_SPEED - _movementClock.getElapsedTime().asSeconds() * GRAVITY;
        _birdAngle = atan(_birdSpeed/FLYING_SPEED) * 180 / PI;
        _birdSprite.move(0, -_birdSpeed*dt);
        _birdSprite.setRotation(-_birdAngle);
    }
    
    void Bird::Tap()
    {
        _movementClock.restart();
    }
    
    const sf::Sprite &Bird::GetSprite() const
    {
        return _birdSprite;
    }
}
