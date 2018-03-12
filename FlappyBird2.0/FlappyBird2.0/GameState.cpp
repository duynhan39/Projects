#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <sstream>
#include <iostream>

namespace DN
{
    GameState::GameState(GameDataRef data) : _data(data)
    {
        
    }
    
    void GameState::Init()
    {
        this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        
        this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
        this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
        
        this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
        
        this->_background.setTexture(this->_data->assets.GetTexture("Game Background"));
        
        pipe = new Pipe(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        
        _gameState = GameStates::eReady;
    }
    
    void GameState::HandleInput()
    {
        sf::Event event;
        
        while(this->_data->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->_data->window.close();
            }
            
            if(_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window)
               && _gameState != GameStates::eGameOver)
            {
                _gameState = GameStates::ePlaying;
                bird->Tap();
            }
        }
    }
    
    void GameState::Update(float dt)
    {
        if(_gameState != GameStates::eGameOver)
        {
            land->MoveLand(dt);
            bird->Animate(dt);
        }
        
        if(_gameState == GameStates::ePlaying)
        {
            pipe->MovePipes(dt);
            if(clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
            {
                pipe->RandomisePipeOffset();
                
                pipe->SpawnInvisiblPipe();
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                
                clock.restart();
            }
            bird->Update(dt);
            
            std::vector<sf::Sprite> landSprites = land->GetSprites();
            
            for(int i=0; i<landSprites.size(); i++)
            {
                if(collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, landSprites.at(i), 1.0f))
                {
                    _gameState = GameStates::eGameOver;
                }
            }
            
            std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
            
            for(int i=0; i<pipeSprites.size(); i++)
            {
                if(collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, pipeSprites.at(i), 1.0f))
                {
                    _gameState = GameStates::eGameOver;
                }
            }
        }
    }
    
    void GameState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Cyan);
        
        this->_data->window.draw(this->_background);
        
        this->pipe->DrawPipes();
        this->land->DrawLand();
        this->bird->DrawBird();
        
        this->_data->window.display();
    }
}


