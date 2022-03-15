#include "Enemy.h"
#include "lua.hpp"

void Enemy::Load()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaopen_base(L);
    luaopen_string(L);
    luaopen_math(L);
    luaL_loadfile(L, "Enemy.lua");
    lua_pcall(L, 0, 0, 0);

    lua_getglobal(L, "imgPath");
    std::string path = lua_tostring(L, -1);
    
    lua_getglobal(L, "x");
    x = lua_tonumber(L, -1);

    lua_getglobal(L, "y");
    y = lua_tonumber(L, -1);

    lua_getglobal(L, "w");
    width = lua_tonumber(L, -1);

    lua_getglobal(L, "h");
    height = lua_tonumber(L, -1);

    lua_getglobal(L, "boxX");
    box.x = lua_tonumber(L, -1);

    lua_getglobal(L, "boxY");
    box.y = lua_tonumber(L, -1);

    lua_getglobal(L, "boxW");
    box.w = lua_tonumber(L, -1);

    lua_getglobal(L, "boxH");
    box.h = lua_tonumber(L, -1);

    lua_getglobal(L, "frames");
    frames = lua_tonumber(L, -1);
    
    lua_getglobal(L, "velocity");
    velocity = lua_tonumber(L, -1);

    img.Load(path, width, height, frames);

}

void Enemy::Draw()
{
    img.Draw(x,y);
}

void Enemy::Update()
{
    x-= velocity;
}

Box Enemy::GetBox()
{
    return box;
}

void Enemy::GetPosition(float &x, float& y)
{
    x = this->x;
    y = this->y;
}