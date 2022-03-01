#include "Game.h"

void Game::Init()
{
	sys = System::GetPtr();
	background.Load();

	player.Load();
}

void Game::Draw()
{
	background.Draw();
	player.Draw();
}

void Game::Update()
{

}
void Game::Input()
{
	char key = sys->Input();

	if (key == ' ')
	{
		player.Jump();
	}
}


