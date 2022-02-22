#pragma once
#include <string>

class Player
{
public:
	void Load();
    void Jump();
	void GameOver();
	void Respawn();

private:
    int hp = 100;
	int jump = 0;
    bool live = true;

	std::string imageJump;
	std::string PlayerDie;
	std::string PlayerRun;
};

