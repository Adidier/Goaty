#pragma once
#include "SDL.h"
class System
{
    public:
        void Init();
        void GetConfig();
        void Draw();
        void Input();
        int GetHeight() { return screenHeight; }
        int GetWidth() { return screenWidth; }
private:
    int screenHeight;
    int screenWidth;
    int isFullScreen;
    SDL_Window* window;
};

