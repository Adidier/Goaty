// Goaty.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "SDL.h"
#include "lua.hpp"
#include <iostream>
#include "System.h"
#include "Game.h"

int main(int argc, char* args[])
{
    System *system = System::GetPtr();
    Game game;
    system->Init();
    game.Init();

    while (!system->Exit())
    {
       
        system->ClearScreen();
        game.Input();
        game.Update();
        game.Draw();
        system->RenderPresent();
    }

    return 0;
 }
