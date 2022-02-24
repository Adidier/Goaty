#pragma once
#include <string>
#include "Image.h"

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

	Image jump;
	Image die;
	Image run;
	Image* currentState;
};

