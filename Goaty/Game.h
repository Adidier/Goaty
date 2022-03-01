#pragma once
#include "Player.h"
#include "Background.h"
#include "System.h"

class Game
{
private:
	Player player;
    Background background;
    System* sys;

   
public:
    void Init();
    void Draw();
    void Update();
};

