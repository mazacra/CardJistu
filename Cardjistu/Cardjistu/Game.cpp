#include "Game.h"
#include "Card.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>

#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
using json = nlohmann::json;

#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message

#define OFFSET_Y 12
#define OFFSET_X 70

SerialPort* arduino;

Game::Game()
{

}

Game::~Game()
{

}

void Game::newGame(bool solo)
{
	const char* com = "COM3";
	arduino = new SerialPort(com, BAUD);

	if (!arduino->isConnected()) {
		std::cerr << "Impossible de se connecter au port " << std::string(com) << ". Fermeture du programme!" << std::endl;
		exit(1);
	}

	Player player1, player2;

	player1.generateDeck();
	player2.generateDeck();

	_winningPlayer = 0;
	_solo = solo;

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
		show.menuSelection();
		afficherWins();

		int* iP;
		iP = selectCard(_p1, _p2);

		_cp1 = _p1.getCard(iP[0]);
		_cp2 = _p2.getCard(iP[1]);

		system("CLS");
		gotoxy(15, 5);
		_cp1->afficherCard();
		gotoxy(15, 6);
		std::cout << "   VS   " << std::endl;
		gotoxy(15, 7);
		_cp2->afficherCard();
		std::cout << std::endl << std::endl << std::endl;
		system("pause");

		winningPlayer();

		if (getWinner(_p1))
		{
			_winningPlayer = 1;
		}
		if (getWinner(_p2))
		{
			_winningPlayer = 2;
		}

		_p1.removeCard(iP[0]);
		_p2.removeCard(iP[1]);
		_p1.drawCard();
		_p2.drawCard();
	}

	show.winner(_winningPlayer);
}

int* Game::selectCard(Player p1, Player p2)
{
	std::string raw_msg;
	int indexP1, indexP2 = 0;
	json j_msg_rcv;

	//afficherTour();
	int cards[2] = { -1, -1 };
	int set[] = { 7, 7, 7 };
	std::string joystick = "";
	std::string accel = "";
	std::string btn = "";

	while (cards[0] == -1 && cards[1] == -1) {
		//Selection joueur 2
		//Si le joueur à choisi sa carte on peut le skip
		if (cards[1] == -1) {

			if (GetKeyState(VK_UP) && indexP2 > 0)
				indexP2--;
			if (GetKeyState(VK_DOWN) && indexP2 < p2.getDeckSize() - 1)
				indexP2++;
			if (GetKeyState(VK_RETURN))
				cards[1] = indexP2;

			if (!p2.getAI()) {

				for (int i = 0; i < p2.getDeckSize(); i++)
				{
					Card* c = p2.getCard(i);

					set[0] = 7;
					if (indexP2 == i)
						set[0] = 12;

					gotoxy(0 + OFFSET_X, i + OFFSET_Y);
					color(set[0]);

					c->afficherCard();

					set[0] = 7;
					color(set[0]);
				}
			}
			else
				cards[1] = p2.AISelectCard();
		}

		if (cards[0] == -1) {
			j_msg_rcv.clear(); // effacer le message precedent
			if (!RcvFromSerial(arduino, raw_msg)) {
				std::cerr << "Erreur lors de la reception du message. " << std::endl;
			}	
			if (raw_msg.size() > 0) {
				// Transfert du message en json
				j_msg_rcv = json::parse(raw_msg);

				btn = j_msg_rcv["bouton"];
				joystick = j_msg_rcv["JoyStick"];
				accel = j_msg_rcv["accel"];
			}

			if (joystick == "jb" && indexP1 > 0)
				indexP1--;
			if (joystick == "jh" && indexP1 < p1.getDeckSize() - 1)
				indexP1++;
			if (btn == "On" || accel == "myb")
				cards[1] = indexP1;

			for (int i = 0; i < p1.getDeckSize(); i++)
			{
				Card* c = p1.getCard(i);

				set[0] = 7;
				if (indexP1 == i)
					set[0] = 12;

				gotoxy(0, i + OFFSET_Y);
				color(set[0]);

				c->afficherCard();

				set[0] = 7;
				color(set[0]);
			}
		}
	}


	return cards;
}

Card* Game::winningCard(Card* c1, Card* c2)
{
	if (c1->getElement() == c2->getElement() && c1->getNumber() == c2->getNumber()) return nullptr;

	if (c1->getElement() == (Element)1 && c2->getElement() == (Element)0) return c1;
	if (c1->getElement() == (Element)2 && c2->getElement() == (Element)1) return c1;
	if (c1->getElement() == (Element)0 && c2->getElement() == (Element)2) return c1;

	if (c1->getElement() == (Element)0 && c2->getElement() == (Element)1) return c2;
	if (c1->getElement() == (Element)1 && c2->getElement() == (Element)2) return c2;
	if (c1->getElement() == (Element)2 && c2->getElement() == (Element)0) return c2;


	if (c1->getNumber() > c2->getNumber()) return c1;

	if (c1->getNumber() < c2->getNumber()) return c2;
}

Player Game::winningPlayer()
{
	Card* c = winningCard(_cp1, _cp2);

	if (c == _cp1)
	{
		_p1.addToWins(c);
		system("CLS");
		gotoxy(25, 5);
		std::cout << "P1 gagne la manche!" << std::endl << std::endl << std::endl;
		system("pause");
		return _p1;
	}

	if (c == _cp2)
	{
		_p2.addToWins(c);
		system("CLS");
		gotoxy(25, 5);
		std::cout << "P2 gagne la manche!" << std::endl << std::endl << std::endl;
		system("pause");
		return _p2;
	}
}

bool Game::getWinner(Player p)
{
	std::string sF = "";
	std::string sW = "";
	std::string sS = "";

	if (p.getWinsSize() >= 3) {
		for (int i = 0; i < p.getWinsSize(); i++)
		{
			Card* c = p.getCardWins(i);

			if (c->getElement() == (Element)0) {
				if (sF.find((int)c->getColor()) == std::string::npos)
					sF += (int)c->getColor();
			}
			if (c->getElement() == (Element)1) {
				if (sW.find((int)c->getColor()) == std::string::npos)
					sW += (int)c->getColor();
			}
			if (c->getElement() == (Element)2) {
				if (sS.find((int)c->getColor()) == std::string::npos)
					sS += (int)c->getColor();
			}

			if (sF.size() > 0 && sW.size() > 0 && sS.size() > 0)
				return true;
			if (sF.size() > 2 || sW.size() > 2 || sS.size() > 2)
				return true;
		}
	}

	return false;
}

void Game::afficherWins()
{
	gotoxy(50, OFFSET_Y - 2);
	std::cout << "Player 1";

	for (int i = 0; i < _p1.getWinsSize(); i++)
	{
		Card* c = _p1.getCardWins(i);
		gotoxy(50, i + OFFSET_Y);
		c->afficherCard();
	}

	gotoxy(70, OFFSET_Y - 2);
	std::cout << "Player 2";

	for (int i = 0; i < _p2.getWinsSize(); i++)
	{
		Card* c = _p2.getCardWins(i);
		gotoxy(70, i + OFFSET_Y);
		c->afficherCard();
	}
}

void Game::afficherTour()
{
	system("CLS");
	gotoxy(25, 5);
	if (player)
		std::cout << "P2 choisis sa carte" << std::endl << std::endl << std::endl;
	else
		std::cout << "P1 choisis sa carte" << std::endl << std::endl << std::endl;

	if (!_p2.getAI())
		player = !player;

	system("pause");
	show.menuSelection();
	afficherWins();
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

bool Game::RcvFromSerial(SerialPort* arduino, std::string& msg) {
	// Return 0 if error
	// Message output in msg
	std::string str_buffer;
	char char_buffer[MSG_MAX_SIZE];
	int buffer_size;

	msg.clear(); // clear string
	// Read serialport until '\n' character (Blocking)

	// Version fonctionnel dans VScode, mais non fonctionnel avec Visual Studio
/*
	while(msg.back()!='\n'){
		if(msg.size()>MSG_MAX_SIZE){
			return false;
		}

		buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
		str_buffer.assign(char_buffer, buffer_size);
		msg.append(str_buffer);
	}
*/

// Version fonctionnelle dans VScode et Visual Studio
	buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
	str_buffer.assign(char_buffer, buffer_size);
	msg.append(str_buffer);

	//msg.pop_back(); //remove '/n' from string

	return true;
}