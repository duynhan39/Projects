#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
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
        this->_data->assets.LoadTexture("Game Over Title", GAME_TITLE_FILEPATH);
        this->_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
        
        this->_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        this->_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
        this->_gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Body"));
        this->_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        
        _gameOverContainer.setPosition((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2 - _gameOverContainer.getGlobalBounds().height / 2));
        
        _gameOverTitle.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), (_gameOverContainer.getPosition().y-_gameOverTitle.getGlobalBounds().height * 1.2));
        
        _retryButton.setPosition((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), (_gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + _retryButton.getGlobalBounds().height * 0.2));
        
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
            
            if(_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
            {
                _data->machine.AddState(StateRef(new GameState(_data)), true);
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
        this->_data->window.draw(this->_gameOverTitle);
        this->_data->window.draw(this->_gameOverContainer);
        this->_data->window.draw(this->_retryButton);
        
        this->_data->window.display();
    }
}

