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
        if(!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
        {
            std::cout << "Error Loading Hit Sound Effect" << std::endl;
        }
        if(!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH))
        {
            std::cout << "Error Loading Point Sound Effect" << std::endl;
        }
        if(!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH))
        {
            std::cout << "Error Loading Wing Sound Effect" << std::endl;
        }
        
        this->_hitSound.setBuffer(_hitSoundBuffer);
        this->_pointSound.setBuffer(_pointSoundBuffer);
        this->_wingSound.setBuffer(_wingSoundBuffer);
        
        this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        
        this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
        this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
        this->_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
        
        this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
        
        this->_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);
        
        this->_background.setTexture(this->_data->assets.GetTexture("Game Background"));
        
        pipe = new Pipe(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        flash = new Flash(_data);
        hud = new HUD(_data);
        
        _score = 0;
        
        hud->UpdataScore(_score);
        
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
                
                _wingSound.play();
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
                
                pipe->SpawnInvisiblePipe();
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                pipe->SpawnScoringPipe();
                
                clock.restart();
            }
            bird->Update(dt);
            
            std::vector<sf::Sprite> landSprites = land->GetSprites();
            
            for(int i=0; i<landSprites.size(); i++)
            {
                if(collision.CheckSpriteCollision(bird->GetSprite(), 0.8f, landSprites.at(i), 1.0f))
                {
                    _gameState = GameStates::eGameOver;
                    
                    clock.restart();
                    
                    _hitSound.play();
                }
            }
            
            std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
            
            for(int i=0; i<pipeSprites.size(); i++)
            {
                if(collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, pipeSprites.at(i), 1.0f))
                {
                    _gameState = GameStates::eGameOver;
                    
                    clock.restart();
                    
                    _hitSound.play();
                }
            }
            
            if(_gameState == GameStates::ePlaying)
            {
                std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprite();
                
                for(int i=0; i<scoringSprites.size(); i++)
                {
                    
                    if(collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, scoringSprites.at(i), 1.0f))
                    {
                        _score++;
                        
                        scoringSprites.erase(scoringSprites.begin() + i);
                        
                        _pointSound.play();
                    }
                }
            }
        }
        if(_gameState == GameStates::eGameOver)
        {
            flash->Show(dt);
            
            if(clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
            {
                _data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
            }
        }
        
        hud->UpdataScore(_score);
    }
    
    void GameState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Cyan);
        
        this->_data->window.draw(this->_background);
        
        this->pipe->DrawPipes();
        this->land->DrawLand();
        this->bird->DrawBird();
        this->hud->Draw();
        
        this->flash->Draw();
        
        this->_data->window.display();
    }
}


