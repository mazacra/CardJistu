#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void newGame(bool solo);
	void play();
	Card carteGagnante(Card c1, Card c2);

private:
	Player _p1;
	Player _p2;
};

#endif // !GAME_H
