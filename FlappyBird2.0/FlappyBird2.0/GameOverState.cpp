#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>

namespace DN
{
    GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
    {
        
    }
    
    void GameOverState::Init()
    {
        std::ifstream readFile(HIGHSCORE_FILEPATH);
        if(readFile)
        {
            while(!readFile.eof())
            {
                readFile >> _highScore;
            }
        }
        
        readFile.close();
        
        std::ofstream writeFile(HIGHSCORE_FILEPATH);
        if(writeFile)
        {
            _highScore = std::max(_score, _highScore);
            writeFile << _highScore;
        }
        
        this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Game Over Title", GAME_TITLE_FILEPATH);
        this->_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
        
        this->_data->assets.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);
        
        this->_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        this->_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
        this->_gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Body"));
        this->_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        
        _gameOverContainer.setPosition((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2 - _gameOverContainer.getGlobalBounds().height / 2));
        
        _gameOverTitle.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), (_gameOverContainer.getPosition().y-_gameOverTitle.getGlobalBounds().height * 1.2));
        
        _retryButton.setPosition((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), (_gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + _retryButton.getGlobalBounds().height * 0.2));
        
        _scoreText.setFont(_data->assets.GetFont("Flappy Font"));
        _scoreText.setString(std::to_string(_score));
        _scoreText.setCharacterSize( 56 );
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
        _scoreText.setPosition(_data->window.getSize().x * 0.725, _data->window.getSize().y / 2.165);
        
        _highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
        _highScoreText.setString(std::to_string(_highScore));
        _highScoreText.setCharacterSize( 56 );
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
        _highScoreText.setPosition(_data->window.getSize().x * 0.725, _data->window.getSize().y / 1.78);
        
        std::string medalName;
        if(_score >= PLATINUM_MEDAL_SCORE)
        {
            medalName = "Platinum Medal";
        }
        else if(_score >= GOLD_MEDAL_SCORE)
        {
            medalName = "Gold Medal";
        }
        else if(_score >= SILVER_MEDAL_SCORE)
        {
            medalName = "Silver Medal";
        }
        else
        {
            medalName = "Bronze Medal";
        }
        _medal.setTexture(_data->assets.GetTexture(medalName));
        
        _medal.setPosition( 175, 465);
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
        this->_data->window.draw(this->_scoreText);
        this->_data->window.draw(this->_highScoreText);
        this->_data->window.draw(this->_medal);
        
        
        this->_data->window.display();
    }
}

