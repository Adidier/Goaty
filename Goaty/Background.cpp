#include "Background.h"


void Background::Draw()
{
    sys->RenderImage(&background, x, y);
    sys->RenderImage(&background2, x + background.GetWidth(), y);
    if(x <= background.GetWidth() * -1){
        x = 0;
    }
    --x;
}

void Background::Load()
{
    sys = System::GetPtr();
    background.Load(sys->GetBackgroundFile());
    background2.Load(sys->GetBackgroundFile());
    x = y =0;
    width = sys->GetWidth();
    height = sys->GetHeight();
}
    
void Background::Reset()
{

}