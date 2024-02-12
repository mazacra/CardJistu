#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::newGame(bool solo)
{
	Player player1, player2;

	if (solo)
		player2.setAI(true);

	_p1 = player1;
	_p2 = player2;

	play();
}

void Game::play()
{
	
}