#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <sstream>
#include <iostream>

namespace DN
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
        
    }
    
    void MainMenuState::Init()
    {
        this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
        this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPLAY);
        
        this->_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
        this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));
        this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        
        this->_title.setPosition((SCREEN_WIDTH)/2 - _title.getGlobalBounds().width/2, _title.getGlobalBounds().height);
        
        this->_playButton.setPosition((SCREEN_WIDTH)/2 - _playButton.getGlobalBounds().width/2, (SCREEN_HEIGHT)/2 - _playButton.getGlobalBounds().height/2);
        
        
    }
    
    
    void MainMenuState::HandleInput()
    {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->_data->window.close();
            }
            if(_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
            {
                this->_data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }
    
    void MainMenuState::Update(float dt)
    {

    }
    
    void MainMenuState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Cyan);
        
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_title);
        this->_data->window.draw(this->_playButton);
        
        this->_data->window.display();
    }
}
