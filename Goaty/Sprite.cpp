#include "Sprite.h"
#include "System.h"

void Sprite::Load(std::string path, int w, int h, int frames)
{
	img.Load(path);
	this->w = w;
	this->h = h;
	this->frames = frames;
}

void Sprite::Draw(int x,int y)
{
	auto sys = System::GetPtr();
	if (counter < frames)
	{
		int frameX, frameY, frameW, frameH;
		frameX = w * counter;
		frameY = 0;
		frameW = w;
		frameH = h;
		sys->RenderImage(&img, x, y, frameX, frameY, frameW, frameH);
		++counter;
	}
	else
	{
		counter = 0;
	}
}