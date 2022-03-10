#include "Game.h"

void Game::Init()
{
	sys = System::GetPtr();
	background.Load();

	player.Load();

	enemy.Load();
}

void Game::Draw()
{
	background.Draw();
	player.Draw();
	enemy.Draw();
}

void Game::Update()
{
	player.Update();
	enemy.Update();
	float playerX, playerY;
	auto obj1 = player.GetBox();
	player.GetPosition(playerX, playerY);
	obj1.x += playerX;
	obj1.y += playerY;
	float enemyX, enemyY;
	auto obj2 = enemy.GetBox();
	obj2.x += playerX;
	obj2.y += playerY;
	if (IsColliding(obj1, obj2))
	{
		player.Respawn();
	}
}

bool Game::IsColliding(Box obj1, Box obj2)
{
	//Derecha player - izquierda enemy
	if(obj1.x + obj1.w > obj2.x && obj1.x < obj2.x + obj2.w && obj1.y + obj1.h > obj2.y && obj1.y < obj2.y + obj2.h)
	{
		return true;
	}
	
	//Abajo player - arriba enemy
	if(obj1.x + obj1.w > obj2.x && obj1.x < obj2.x + obj2.w && obj1.y + obj1.h > obj2.y && obj1.y < obj2.y + obj2.h)
	{
		return true;
	}
	return false;
}

void Game::Input()
{
	char key = sys->Input();

	if (key == ' ')
	{
		player.Jump();
	}
}


