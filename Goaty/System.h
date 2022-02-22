#pragma once
#include "SDL.h"
class System
{
    public:
        void Init();
        void GetConfig();
        void Draw();
        int GetHeight() { return screenHeight; }
        int GetWidth() { return screenWidth; }
        void ClearScreen();
        void RenderPresent();
        bool Exit();
        void Input();
private:
    int screenHeight;
    int screenWidth;
    int isFullScreen;
    bool exit;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

