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

Card Game::carteGagnante(Card c1, Card c2)
{
	//if (c1.getElement() == c2.getElement() && c1.getNumber() == c2.getNumber()) return ???

	if (c1.getElement() == 2 && c2.getElement() == 1) return c1;
	if (c1.getElement() == 3 && c2.getElement() == 2) return c1;
	if (c1.getElement() == 1 && c2.getElement() == 3) return c1;

	if (c1.getElement() == 1 && c2.getElement() == 2) return c2;
	if (c1.getElement() == 2 && c2.getElement() == 3) return c2;
	if (c1.getElement() == 3 && c2.getElement() == 1) return c2;

	else
	{
		if (c1.getNumber() > c2.getNumber()) return c1;

		if (c1.getNumber() < c2.getNumber()) return c2;
	}
}