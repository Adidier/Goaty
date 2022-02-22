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
    std::string GetConfigPlayer();
    void RenderImage(Image* img, int x, int y);
    SDL_Renderer* GetRenderer();
    static System* GetPtr();
private:
    int screenHeight;
    int screenWidth;
    int isFullScreen;
    std::string configPlayer;
    bool exit = false;
    SDL_Window* window;
    SDL_Renderer* renderer;
    static System* ptr;
    System();
};

