#include "Image.h"
#include "System.h"
#include "SDL_image.h"

void Image::Load(const std::string& filePath)
{
	SDL_Surface *img = IMG_Load(filePath.c_str());
	System* system = System::GetPtr();
	image = SDL_CreateTextureFromSurface(system->GetRenderer(), img);
	SDL_QueryTexture(image, NULL, NULL, &imageWidth, &imageHeight);
	SDL_free(img);
}

SDL_Texture* Image::GetTexture()
{
	return image;
}


