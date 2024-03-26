#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Afficher.h"
#include "Player.h"
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"

class Game
{
public:
	Game();
	~Game();

	void newGame(bool solo);
	void play();
	std::vector<int> selectCard(Player p1 ,Player p2);
	Card* winningCard(Card* c1, Card* c2);
	Player winningPlayer();
	bool getWinner(Player p);
	void afficherWins();
	void afficherTour();
	std::string readSerial();

	void color(int color);
	void gotoxy(int x, int y);

	bool RcvFromSerial(SerialPort* arduino, std::string& msg);

private:
	Afficher show;
	Player _p1;
	Player _p2;
	Card* _cp1;
	Card* _cp2;
	bool player;
	bool _solo;
	int _winningPlayer = 0;
};

#endif // !GAME_H
