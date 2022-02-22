// Goaty.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "SDL.h"
#include "lua.hpp"
#include <iostream>
#include "System.h"

int main(int argc, char* args[])
{
    System system;
    system.Init();

    while (system.Exit())
    {
        system.Input();
        system.ClearScreen();



        system.RenderPresent();
    }

    return 0;
 }
