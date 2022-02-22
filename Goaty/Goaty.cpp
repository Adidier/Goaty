// Goaty.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "SDL.h"
#include "lua.hpp"
#include <iostream>
#include "System.h"
#include "Image.h"

int main(int argc, char* args[])
{
    System *system = System::GetPtr();
    system->Init();
    Image img;
    img.Load("imagen.bmp");

    while (!system->Exit())
    {
        system->Input();
        system->ClearScreen();
        system->RenderImage(&img, 0, 0);


        system->RenderPresent();
    }

    return 0;
 }
