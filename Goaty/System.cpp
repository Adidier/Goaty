#include "System.h"
#include "LUA.hpp"

System* System::ptr = nullptr;

System::System()
{
}

SDL_Renderer* System::GetRenderer()
{
    return renderer;
}

System* System::GetPtr()
{
    if (ptr == nullptr)
    {
        ptr = new System();
    }
    return ptr;
}

void System::Init()
{
    GetConfig();
    SDL_Init(SDL_INIT_VIDEO);
    if (isFullScreen) 
    {
        window = SDL_CreateWindow("Goaty", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GetWidth(), GetHeight(), SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    }
    else
    {
        window = SDL_CreateWindow("Goaty", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GetWidth(), GetHeight(), SDL_WINDOW_SHOWN);
    }
    if (window != nullptr)
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
}

void System::GetConfig()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaopen_base(L);
    luaopen_string(L);
    luaopen_math(L);
    luaL_loadfile(L, "config.lua");
    lua_pcall(L, 0, 0, 0);
    lua_getglobal(L, "height");
    screenHeight = lua_tonumber(L, -1);
    lua_getglobal(L, "width");
    screenWidth = lua_tonumber(L, -1);
    lua_getglobal(L, "isFullScreen");
    isFullScreen = lua_toboolean(L, -1);
    lua_getglobal(L, "configPlayer");
    size_t len;
    configPlayer = lua_tolstring(L, -1, &len);
    
    lua_getglobal(L, "background");
    background = lua_tolstring(L, -1, &len);


    lua_getglobal(L, "keyJump");
    std::string jump = lua_tolstring(L, -1, &len);
    if (jump == "KEY_SPACE")
    {
        keyJump = ' ';
    }
}

std::string System::GetBackgroundFile()
{
    return background;
}

std::string System::GetConfigPlayer()
{
    return configPlayer;
}
void System::Draw()
{
    
}

void System::ClearScreen()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x0, 0xFF);
    SDL_RenderClear(renderer);
}

void System::RenderPresent()
{
    SDL_RenderPresent(renderer);
}

bool System::Exit()
{
    return exit;
}

char System::Input()
{
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
        {

            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                exit = true;
            }

            return e.key.keysym.sym;
        }
    }
}

void System::RenderImage(Image* img, int x, int y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = img->GetWidth();
    dst.h = img->GetHeight();

    SDL_RenderCopy(renderer, img->GetTexture(), NULL, &dst);
}


void System::RenderImage(Image* img, int x, int y, int frameX, int frameY, int frameW, int frameH)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = frameW;
    dst.h = frameH;

    SDL_Rect src;
    src.x = frameX;
    src.y = frameY;
    src.w = frameW;
    src.h = frameH;

    SDL_RenderCopy(renderer, img->GetTexture(), &src, &dst);
}
