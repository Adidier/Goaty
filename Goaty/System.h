#pragma once
#include "SDL.h"
#include "Image.h"
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
    void RenderImage(Image* img, int x, int y);
    SDL_Renderer* GetRenderer();
    static System* GetPtr();
private:
    int screenHeight;
    int screenWidth;
    int isFullScreen;
    bool exit = false;
    SDL_Window* window;
    SDL_Renderer* renderer;
    static System* ptr;
    System();
};

