#pragma once
#include<string>
#include"Image.h"

class Sprite
{
private:
	Image img;
	int w;
	int h;
	int frames;
	int counter = 0;
public:
	void Load(std::string path, int w, int h, int frames);
	void Draw(int x, int y);
};
