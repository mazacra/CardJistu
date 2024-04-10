#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Afficher.h"
#include "Player.h"
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"

using json = nlohmann::json;

class Game
{
public:
	Game();
	~Game();

	void newGame(bool solo);
	void play();
	int selectCardClavier(Player p);
	int selectCardManette(int p);
	int winningCard(int iC1, int iC2);
	int winningPlayer();
	bool getWinner(int iP);
	void afficherWins();
	void playerTurn();
	bool inputManette();
	std::string readSerial();
	std::vector<std::string> getPlayerCards(int p);
	std::vector<std::string> getPlayedCards();

	void color(int color);
	void gotoxy(int x, int y);

	bool RcvFromSerial(SerialPort* arduino, std::string& msg);
	bool SendToSerial(SerialPort* arduino, json j_msg);

private:
	Afficher show;
	Player _p1;
	Player _p2;
	Card* _cp1;
	Card* _cp2;
	bool player;
	bool _solo;
	int _winningPlayer = 0;
	bool manette;
	int indexP1 = 0;
	int indexP2 = 0;

};

#endif // !GAME_H
