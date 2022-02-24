#include "Game.h"

void Game::Init()
{
	sys = System::GetPtr();
	background.Load(sys->GetBackgroundFile());

	player.Load();
}

void Game::Draw()
{
	sys->RenderImage(&background, 0, 0);
	player.Draw();
}

void Game::Update()
{

}