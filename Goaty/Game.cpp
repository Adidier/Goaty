#include "Game.h"

void Game::Init()
{
	sys = System::GetPtr();
	background.Load();

	player.Load();

	enemy.Load(); //Examen crear un vector de enemigos y leer del archivo de configuracion cuantos enemigos se van a mostrar
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
	obj1.w += obj1.x;

	float enemyX, enemyY;
	auto obj2 = enemy.GetBox();
	enemy.GetPosition(enemyX, enemyY);

	obj2.x += enemyX;
	obj2.w += obj2.x;

	if (IsColliding(obj1, obj2))
	{
		player.Respawn();
	}
}

bool Game::IsColliding(Box obj1, Box obj2) //Examen arreglar
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


