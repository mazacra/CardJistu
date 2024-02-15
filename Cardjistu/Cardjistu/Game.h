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
	int selectCard(Player p);
	Card* winningCard(Card* c1, Card* c2);
	Player winningPlayer();
	bool getWinner(Player p);
	void afficherWins();
	void afficherTour();

	void color(int color);
	void gotoxy(int x, int y);

private:
	Afficher show;
	Player _p1;
	Player _p2;
	Card* _cp1;
	Card* _cp2;
	bool player;
	int _winningPlayer = 0;
};

#endif // !GAME_H
