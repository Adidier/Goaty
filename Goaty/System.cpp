#include "System.h"
#include "LUA.hpp"

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
}

void System::Draw()
{
    
}

void System::Input()
{
    
}