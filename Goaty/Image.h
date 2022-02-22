#pragma once
#include "SDL.h"
#include <string>

class Image
{
public:
    
	void Load(const std::string& filePath);
	int GetWidth() { return imageWidth; }
	int GetHeight() { return imageHeight; }
	SDL_Texture* GetTexture();

private:
	int imageWidth;
	int imageHeight;
	SDL_Texture* image;
};

