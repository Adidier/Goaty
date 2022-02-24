#pragma once
#include "Player.h"
#include "Image.h"
#include "System.h"

class Game
{
private:
	Player player;
    Image background;
    System* sys;

   
public:
    void Init();
    void Draw();
    void Update();
};

