#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace DN
{
    class Pipe
    {
    public:
        Pipe(GameDataRef data);
        
        void SpawnBottomPipe();
        void SpawnTopPipe();
        void SpawnInvisiblePipe();
        void SpawnScoringPipe();
        void MovePipes(float dt);
        void DrawPipes();
        void RandomisePipeOffset();
        
        const std::vector<sf::Sprite> &GetSprites() const;
        std::vector<sf::Sprite> &GetScoringSprite();
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> _pipeSprites;
        std::vector<sf::Sprite> _scoringPipes;
        
        int _landHeight;
        int _pipeSpawnYOffset;
    };
}

