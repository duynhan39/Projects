#include "Bird.hpp"

namespace DN
{
    Bird::Bird(GameDataRef data): _data(data)
    {
        _birdSprite.setTexture(_data->assets.GetTexture("Bird Frame 1"));
    }
    
    void Bird::DrawBird()
    {
        _data->window.draw(_birdSprite);
    }
}
