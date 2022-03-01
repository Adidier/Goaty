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
    jumpValue = lua_tonumber(L, -1);
    lua_getglobal(L, "imageJump");
    imagePathJump = lua_tostring(L, -1);
    lua_getglobal(L, "imageDie");
    imagePathDie = lua_tostring(L, -1);
    lua_getglobal(L, "imageRun");
    imagePathRun = lua_tostring(L, -1);

    //jump.Load(imagePathJump,45,39,8);
    //die.Load(imagePathDie);
    run.Load(imagePathRun,135, 117, 6);

    currentState = &run;

    x = y = 0;

}

void Player::Draw()
{
    auto sys = System::GetPtr();
    run.Draw(340, 400);
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