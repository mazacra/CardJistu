#include "Game.h"
#include "Card.h"
#include <windows.h>
#include <conio.h>

#define OFFSET_Y 10

Game::Game()
{

}

Game::~Game()
{

}

void Game::newGame(bool solo)
{
	Player player1, player2;

	player1.generateDeck();
	player2.generateDeck();

	_winningPlayer = 0;

	if (solo)
		player2.setAI(true);

	_p1 = player1;
	_p2 = player2;

	play();
}

void Game::play()
{
	int index = 0;
	int set[] = { 7, 7, 7 };
	char key = 0;

	while (_winningPlayer == 0)
	{
		show.menuSelection();
		if (key == 72 && index > 0)
			index--;
		if (key == 80 && index < _p1.getDeckSize() - 1)
			index++;
		if (key == '\r')
			break;
		for (int i = 0; i < _p1.getDeckSize(); i++)
		{
			Card* c = _p1.getCard(i);

			set[0] = 7;
			if (index == i)
				set[0] = 12;

			gotoxy(0, i + OFFSET_Y);
			color(set[0]);
			show.infoCarte(c);

			set[0] = 7;
			color(set[0]);
		}
		key = _getch();
	}
}

Card* Game::winningCard(Card* c1, Card* c2)
{
	if (c1->getElement() == c2->getElement() && c1->getNumber() == c2->getNumber()) return nullptr;

	if (c1->getElement() == 2 && c2->getElement() == 1) return c1;
	if (c1->getElement() == 3 && c2->getElement() == 2) return c1;
	if (c1->getElement() == 1 && c2->getElement() == 3) return c1;

	if (c1->getElement() == 1 && c2->getElement() == 2) return c2;
	if (c1->getElement() == 2 && c2->getElement() == 3) return c2;
	if (c1->getElement() == 3 && c2->getElement() == 1) return c2;


	if (c1->getNumber() > c2->getNumber()) return c1;

	if (c1->getNumber() < c2->getNumber()) return c2;
}

Player Game::winningPlayer()
{
	Card* c = winningCard(_p1.getPlayedCard(), _p2.getPlayedCard());

	if (c == _p1.getPlayedCard())
	{
		_p1.addToWins(c);
		return _p1;
	}

	if (c == _p2.getPlayedCard())
	{
		_p2.addToWins(c);
		return _p2;
	}
}

void Game::color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Game::gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
