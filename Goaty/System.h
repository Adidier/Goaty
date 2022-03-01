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
    char Input();
    std::string GetConfigPlayer();
    std::string GetBackgroundFile();
    void RenderImage(Image* img, int x, int y);
    void RenderImage(Image* img, int x, int y, int frameX, int frameY, int frameW, int frameH);
    SDL_Renderer* GetRenderer();
    static System* GetPtr();
private:
    int screenHeight;
    int screenWidth;
    int isFullScreen;
    std::string configPlayer;
    std::string background;

    char keyJump;
    bool exit = false;
    SDL_Window* window;
    SDL_Renderer* renderer;
    static System* ptr;
    System();
};

