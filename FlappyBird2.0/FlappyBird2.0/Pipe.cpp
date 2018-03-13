#include "Pipe.hpp"

namespace DN
{
    Pipe::Pipe(GameDataRef data) : _data(data)
    {
        _landHeight = _data->assets.GetTexture("Land").getSize().y;
        _pipeSpawnYOffset = 0;
    }
    
    void Pipe::SpawnBottomPipe()
    {
        sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
        
        sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
        
        _pipeSprites.push_back(sprite);
    }
    void Pipe::SpawnTopPipe()
    {
        sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
        
        sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
        
        _pipeSprites.push_back(sprite);
    }
    
    void Pipe::SpawnInvisiblePipe()
    {
        sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
        
        sprite.setPosition(0,0);
        
        sprite.setColor(sf::Color( 0, 0, 0, 0 ));
        
        _pipeSprites.push_back(sprite);
        
    }
    
    void Pipe::SpawnScoringPipe()
    {
        sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
        
        sprite.setPosition( _data->window.getSize().x, 0);
        
        _scoringPipes.push_back(sprite);
        
    }
    
    void Pipe::MovePipes(float dt)
    {
        for(unsigned short int i=0; i < _pipeSprites.size(); i++)
        {
            if(_pipeSprites.at(i).getPosition().x < 0 -_pipeSprites.at(i).getGlobalBounds().width)
            {
                _pipeSprites.erase(_pipeSprites.begin()+i);
            } else
            {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                
                _pipeSprites.at(i).move(-movement, 0);
            }
        }
        
        for(unsigned short int i=0; i < _scoringPipes.size(); i++)
        {
            if(_scoringPipes.at(i).getPosition().x < 0 -_scoringPipes.at(i).getGlobalBounds().width)
            {
                _scoringPipes.erase(_scoringPipes.begin()+i);
            } else
            {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                
                _scoringPipes.at(i).move(-movement, 0);
            }
        }
    }
    
    void Pipe::DrawPipes()
    {
        for(unsigned short int i=0; i < _pipeSprites.size(); i++)
        {
            _data->window.draw(_pipeSprites.at(i));
        }
    }
    
    void Pipe::RandomisePipeOffset()
    {
        _pipeSpawnYOffset = rand() % (_landHeight + 1);
    }
    
    const std::vector<sf::Sprite> &Pipe::GetSprites() const
    {
        return _pipeSprites;
    }
    
    std::vector<sf::Sprite> &Pipe::GetScoringSprite()
    {
        return _scoringPipes;
    }
}

