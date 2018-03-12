#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include <sstream>
#include <iostream>

namespace DN
{
    GameOverState::GameOverState(GameDataRef data) : _data(data)
    {
        
    }
    
    void GameOverState::Init()
    {
        this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        
        this->_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
    }
    
    void GameOverState::HandleInput()
    {
        sf::Event event;
        
        while(this->_data->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->_data->window.close();
            }
        }
    }
    
    void GameOverState::Update(float dt)
    {
        
        
    }
    
    void GameOverState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Cyan);
        
        this->_data->window.draw(this->_background);
        
        this->_data->window.display();
    }
}

