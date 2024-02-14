#include "Game.h"
#include "Card.h"
#include <windows.h>
#include <conio.h>

#define OFFSET_Y 12

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

	while (_winningPlayer == 0)
	{
		int iP1 = selectCard(_p1);
		int iP2 = selectCard(_p2);

		_cp1 = _p1.getCard(iP1);
		_cp2 = _p2.getCard(iP2);

		winningPlayer();

		_p1.removeCard(iP1);
		_p2.removeCard(iP2);
		_p1.drawCard();
		_p2.drawCard();
	}
}

int Game::selectCard(Player p)
{
	int index = 0;

	if (p.getAI())
		return p.AISelectCard();
	else {

		int set[] = { 7, 7, 7 };
		char key = 0;

		while (true) {
			show.menuSelection();
			if (key == 72 && index > 0)
				index--;
			if (key == 80 && index < p.getDeckSize() - 1)
				index++;
			if (key == '\r')
				break;
			for (int i = 0; i < p.getDeckSize(); i++)
			{
				Card* c = p.getCard(i);

				set[0] = 7;
				if (index == i)
					set[0] = 12;

				gotoxy(0, i + OFFSET_Y);
				color(set[0]);

				c->afficherCard();

				set[0] = 7;
				color(set[0]);
			}

for (int i = 0; i < _p1.getWinsSize(); i++)
		{
			Card* c = _p1.getCardWins(i);
			gotoxy(50, i + OFFSET_Y);
			c->afficherCard();
		}

			key = _getch();
		}
	}

	return index;
}

Card* Game::winningCard(Card* c1, Card* c2)
{
	if (c1->getElement() == c2->getElement() && c1->getNumber() == c2->getNumber()) return nullptr;

	if (c1->getElement() == (Element)2 && c2->getElement() == (Element)1) return c1;
	if (c1->getElement() == (Element)3 && c2->getElement() == (Element)2) return c1;
	if (c1->getElement() == (Element)1 && c2->getElement() == (Element)3) return c1;

	if (c1->getElement() == (Element)1 && c2->getElement() == (Element)2) return c2;
	if (c1->getElement() == (Element)2 && c2->getElement() == (Element)3) return c2;
	if (c1->getElement() == (Element)3 && c2->getElement() == (Element)1) return c2;


	if (c1->getNumber() > c2->getNumber()) return c1;

	if (c1->getNumber() < c2->getNumber()) return c2;
}

Player Game::winningPlayer()
{
	Card* c = winningCard(_cp1, _cp2);

	if (c == _cp1)
	{
		_p1.addToWins(c);
		return _p1;
	}

	if (c == _cp2)
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
