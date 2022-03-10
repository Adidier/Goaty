#pragma once
#include <string>
#include "Sprite.h"
#include "Box.h"

class Player
{
public:
	void Load();
    void Jump();
	void GameOver();
	void Respawn();
	void Draw();
	void Update();
	Box GetBox();
	void GetPosition(float& x, float& y);

private:
    int hp = 100;
	float jumpValue = 0;
    bool live = true;
	float x, y;
	int w, h;
	float time = 0;
	Box box;
	bool isJumping = false;

	std::string imagePathJump;
	std::string imagePathDie;
	std::string imagePathRun;

	Sprite jump;
	Sprite die;
	Sprite run;
	Sprite* currentState;
};

