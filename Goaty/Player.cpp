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
    lua_getglobal(L, "boxX");
    box.x = lua_tonumber(L, -1);
    lua_getglobal(L, "boxY");
    box.y = lua_tonumber(L, -1);
    lua_getglobal(L, "boxW");
    box.w = lua_tonumber(L, -1);
    lua_getglobal(L, "boxH");
    box.h = lua_tonumber(L, -1);
    lua_getglobal(L, "x");
    x = lua_tonumber(L, -1);
    lua_getglobal(L, "y");
    y = lua_tonumber(L, -1);
    lua_getglobal(L, "w");
    w = lua_tonumber(L, -1);
    lua_getglobal(L, "h");
    h = lua_tonumber(L, -1);

    run.Load(imagePathRun,135, 117, 6);

    currentState = &run;

    x = 340;
    y = 400;

}

void Player::Update() //Examen arreglar el salto
//exponer el salto a una funcion de LUA
{
    if (isJumping && time < jumpValue)
    {
        time += 1.5;
        y = y - 1.5;
        if (time >= jumpValue)
        {
            time = 0;
            isJumping = false;
        }
    }
    else if (!isJumping && y < 400)
    {
        y = y + 1;
    }
}

void Player::Draw()
{
    auto sys = System::GetPtr();
    run.Draw(x, y);
}

void Player::Jump()
{
   
    isJumping = true;
}

void Player::GameOver()
{

}

void Player::Respawn()
{

}

Box Player::GetBox()
{
    return box;
}

void Player::GetPosition(float& x, float& y)
{
    x = this->x;
    y = this->y;
}