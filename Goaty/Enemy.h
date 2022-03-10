#pragma once
#include "Sprite.h"
#include <string>
#include "Box.h"

class Enemy
{
private:
	Sprite img;
	float x, y;
	int width, height;
	Box box;
	float velocity;
	int frames;

public:
	void Load();
	void Draw();
	void Update();
	Box GetBox();
	void GetPosition(float& x, float& y);
};


