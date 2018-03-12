#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include <sstream>
#include <iostream>

namespace DN
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {
        
    }
    
    void SplashState::Init()
    {
        this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        
        this->_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
        
    }
    
    void SplashState::HandleInput()
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
    
    void SplashState::Update(float dt)
    {
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
        
    }
    
    void SplashState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Cyan);
        
        this->_data->window.draw(this->_background);
        
        this->_data->window.display();
    }
}
