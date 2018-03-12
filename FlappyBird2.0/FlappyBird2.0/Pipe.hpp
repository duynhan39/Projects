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
        void SpawnInvisiblPipe();
        void MovePipes(float dt);
        void DrawPipes();
        void RandomisePipeOffset();
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprites;
        
        int _landHeight;
        int _pipeSpawnYOffset;
    };
}

