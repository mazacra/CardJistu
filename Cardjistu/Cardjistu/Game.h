#ifndef GAME_H
#define GAME_H

#include "Afficher.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void newGame(bool solo);
	void play();
	Card* winningCard(Card* c1, Card* c2);
	Player winningPlayer();

	void color(int color);
	void gotoxy(int x, int y);

private:
	Afficher show;
	Player _p1;
	Player _p2;
	int _winningPlayer = 0;
};

#endif // !GAME_H
