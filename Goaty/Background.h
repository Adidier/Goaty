#pragma once
#include "Image.h"
#include "System.h"

class Background
{
    public:
        void Draw();
        void Load();

    private:
        void Reset();
        int x, y;
        int height;
        int width;
        Image background;
        Image background2;
        System* sys;
};

