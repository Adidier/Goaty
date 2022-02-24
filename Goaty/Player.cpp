#include "Player.h"
#include "SDL.h"
#include "System.h"
#include "LUA.hpp"

void Player::Load()
{
    auto sys = System::GetPtr();
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaopen_base(L);
    luaopen_string(L);
    luaopen_math(L);
    luaL_loadfile(L, sys->GetConfigPlayer().c_str());
    lua_pcall(L, 0, 0, 0);

    lua_getglobal(L, "hp");
    hp = lua_tonumber(L, -1);

    lua_getglobal(L, "jump");
    jump = lua_tonumber(L, -1);
    lua_getglobal(L, "imageJump");
    imageJump = lua_tostring(L, -1);
    lua_getglobal(L, "imageDie");
    imageDie = lua_tostring(L, -1);
    lua_getglobal(L, "imageRun");
    imageRun = lua_tostring(L, -1);
}

void Player::Jump()
{

}

void Player::GameOver()
{

}

void Player::Respawn()
{

}