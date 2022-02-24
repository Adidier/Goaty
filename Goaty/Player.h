#pragma once
#include <string>
#include "Sprite.h"

class Player
{
public:
	void Load();
    void Jump();
	void GameOver();
	void Respawn();
	void Draw();

private:
    int hp = 100;
	int jumpValue = 0;
    bool live = true;
	int x, y;

	std::string imagePathJump;
	std::string imagePathDie;
	std::string imagePathRun;

	Sprite jump;
	Sprite die;
	Sprite run;
	Sprite* currentState;
};

