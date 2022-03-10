#pragma once
#include "Player.h"
#include "Background.h"
#include "System.h"
#include "Enemy.h"

class Game
{
private:
	Player player;
    Background background;
    System* sys;

    Enemy enemy;
public:
    void Init();
    void Draw();
    void Update();
    void Input();
    bool IsColliding(Box obj1, Box obj2);
};

