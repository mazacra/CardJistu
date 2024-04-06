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
bool btnIsPressed;

Game::Game()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	btnIsPressed = false;
}

Game::~Game()
{

}

void Game::newGame(bool solo)
{
	//if (manette == TRUE)
	//{
	const char* com = "COM3";
	arduino = new SerialPort(com, BAUD);

	if (!arduino->isConnected()) {
		manette = FALSE;
		//std::cerr << "Impossible de se connecter au port " << std::string(com) << ". Fermeture du programme!" << std::endl;
		//exit(1);
		if (!solo)
			return;
	}
	else
	{
		manette = TRUE;
	}
	//}

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
	char raw_msg[255];
	std::string str = "";
	std::string joystick = "";
	std::string btn = "";
	json j_msg_rcv;

	while (_winningPlayer == 0)
	{
		joystick = "";
		btn = "";
		str = "";

		show.menuSelection();
		afficherWins();

		std::vector<int> l = { -1, -1 };
		if (manette == FALSE)
		{
			l[0] = selectCardClavier(_p1);
			l[1] = selectCardClavier(_p2);
		}

		if (manette == TRUE)
			l = selectCardManette(_p1, _p2);

		_cp1 = _p1.getCard(l[0]);
		_cp2 = _p2.getCard(l[1]);

		system("CLS");
		gotoxy(15, 5);
		show.afficherCard(_cp1);
		gotoxy(15, 6);
		std::cout << "   VS   " << std::endl;
		gotoxy(15, 7);
		show.afficherCard(_cp2);
		std::cout << std::endl << std::endl << std::endl;
		if (manette == FALSE)
			system("pause");
		else if (manette == TRUE)
		{
			while (btn == "" && joystick == "") {
				j_msg_rcv.clear();
				Sleep(100);
				if (arduino->readSerialPort(raw_msg, 255) != 0) {
					str = raw_msg;
					if (str.find_last_of('\n') == std::string::npos) {
						arduino->readSerialPort(raw_msg, 255);
						str += raw_msg;
					}
					if (str[0] != '{')
						str = str.substr(str.find_first_of("\n") + 1, str.length());
					str = str.substr(0, str.find_last_of('\n') - 1);
					str = str.substr(str.find_last_of('\n') + 1, str.length());

					if (str.find('}') != std::string::npos && str.find('{') != std::string::npos) {
						j_msg_rcv = json::parse(str);

						btn = j_msg_rcv["bouton"];
						joystick = j_msg_rcv["JoyStick"];
					}
				}
			}
		}

		winningPlayer();

		if (getWinner(_p1))
		{
			_winningPlayer = 1;
		}
		if (getWinner(_p2))
		{
			_winningPlayer = 2;
		}

		_p1.removeCard(l[0]);
		_p2.removeCard(l[1]);
		_p1.drawCard();
		_p2.drawCard();
	}

	show.winner(_winningPlayer);
}

int Game::selectCardClavier(Player p)
{
	int index = 0;

	if (p.getAI())
		return p.AISelectCard();
	else {
		playerTurn();
		int set[] = { 7, 7, 7 };
		char key = 0;

		while (true) {
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

				show.afficherCard(c);

				set[0] = 7;
				color(set[0]);
			}

			key = _getch();
		}
	}

	return index;
}

std::vector<int> Game::selectCardManette(Player p1, Player p2)
{
	char raw_msg[255];
	int indexP1 = 0;
	int indexP2 = 0;
	json j_msg_send, j_msg_rcv;
	std::string str;

	//afficherTour();
	std::vector<int> cards = { -1, -1 };
	int set[] = { 7, 7, 7 };
	std::string joystick = "";
	std::string accel = "";
	std::string btn = "";

	//Print une premi�re fois les carte du joueur 1
	for (int i = 0; i < p1.getDeckSize(); i++)
	{
		Card* c = p1.getCard(i);

		set[0] = 7;
		if (indexP1 == i) {
			j_msg_send["led"] = (int)c->getColor();
			j_msg_send["power"] = (int)c->getNumber();

			Game::SendToSerial(arduino, j_msg_send);

			set[0] = 12;
		}

		gotoxy(0, i + OFFSET_Y);
		color(set[0]);

		show.afficherCard(c);

		set[0] = 7;
		color(set[0]);
	}

	while (cards[0] == -1 || cards[1] == -1) {
		Sleep(100);
		//Selection joueur 2
		//Si le joueur � choisi sa carte on peut le skip
		if (cards[1] == -1) {
			if (!p2.getAI()) {
				if (!btnIsPressed) {
					if (GetKeyState(VK_UP) && indexP2 > 0) {
						btnIsPressed = true;
						indexP2--;
					}
					if (GetKeyState(VK_DOWN) && indexP2 < p2.getDeckSize() - 1) {
						btnIsPressed = true;
						indexP2++;
					}
					if (GetKeyState(VK_RETURN)) {
						btnIsPressed = true;
						cards[1] = indexP2;
					}


					for (int i = 0; i < p2.getDeckSize(); i++)
					{
						Card* c = p2.getCard(i);

						set[0] = 7;
						if (indexP2 == i)
							set[0] = 12;

						gotoxy(0 + OFFSET_X, i + OFFSET_Y);
						color(set[0]);

						show.afficherCard(c);

						set[0] = 7;
						color(set[0]);
					}

				}
				else {
					if (!GetKeyState(VK_UP) && !GetKeyState(VK_DOWN) && !GetKeyState(VK_RETURN)) {
						btnIsPressed = false;
					}
				}
			}
			else
				cards[1] = p2.AISelectCard();
		}

		if (cards[0] == -1) {
			if (manette == TRUE) {

				j_msg_rcv.clear(); // effacer le message precedent
				btn = "";
				joystick = "";
				accel = "";

				if (arduino->readSerialPort(raw_msg, 255) != 0) {
					str = raw_msg;
					if (str.find_last_of('\n') == std::string::npos) {
						arduino->readSerialPort(raw_msg, 255);
						str += raw_msg;
					}
					if (str[0] != '{')
						str = str.substr(str.find_first_of("\n") + 1, str.length());
					str = str.substr(0, str.find_last_of('\n') - 1);
					str = str.substr(str.find_last_of('\n') + 1, str.length());

					// Transfert du message en json
					if (str.find('}') != std::string::npos && str.find('{') != std::string::npos) {
						j_msg_rcv = json::parse(str);

						btn = j_msg_rcv["bouton"];
						joystick = j_msg_rcv["JoyStick"];
						accel = j_msg_rcv["accel"];

						if (joystick == "jh" && indexP1 > 0)
							indexP1--;
						if (joystick == "jb" && indexP1 < p1.getDeckSize() - 1)
							indexP1++;
						if (btn == "On" || accel == "myb" || accel == "mxb")
							cards[0] = indexP1;

						for (int i = 0; i < p1.getDeckSize(); i++)
						{
							Card* c = p1.getCard(i);

							set[0] = 7;
							if (indexP1 == i) {
								//if(manette)
								j_msg_send["led"] = (int)c->getColor();
								j_msg_send["power"] = (int)c->getNumber();

								Game::SendToSerial(arduino, j_msg_send);

								set[0] = 12;
							}

							gotoxy(0, i + OFFSET_Y);
							color(set[0]);

							show.afficherCard(c);

							set[0] = 7;
							color(set[0]);
						}
					}
				}
			}
			else {
				int set[] = { 7, 7, 7 };
				char key = 0;

				while (true) {
					if (key == 72 && indexP1 > 0)
						indexP1--;
					if (key == 80 && indexP1 < p1.getDeckSize() - 1)
						indexP1++;
					if (key == '\r') {
						cards[0] = indexP1;
						break;
					}
					for (int i = 0; i < p1.getDeckSize(); i++)
					{
						Card* c = p1.getCard(i);

						set[0] = 7;
						if (indexP1 == i) {
							set[0] = 12;
						}

						gotoxy(0, i + OFFSET_Y);
						color(set[0]);

						show.afficherCard(c);

						set[0] = 7;
						color(set[0]);
					}

					key = _getch();
				}
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

	return nullptr;
}

Player Game::winningPlayer()
{
	json j_msg_send;
	Card* c = winningCard(_cp1, _cp2);
	char raw_msg[255];
	json j_msg_rcv;
	std::string str = "";
	std::string joystick = "";
	std::string btn = "";

	if (c != nullptr) {

		j_msg_send.clear();
		j_msg_send["Element"] = (int)c->getElement();
		j_msg_send["Couleur"] = (int)c->getColor();
		j_msg_send["Valeur"] = c->getNumber();
		Game::SendToSerial(arduino, j_msg_send);
	}

	if (c == _cp1)
	{
		_p1.addToWins(c);
		system("CLS");
		gotoxy(25, 5);
		//std::cout << "P1 gagne la manche!" << std::endl << std::endl << std::endl;
		show.afficherRoundWinner(1);

		if (manette == FALSE)
			system("pause");

		if (manette == TRUE)
		{
			while (btn == "" && joystick == "") {
				j_msg_rcv.clear();
				Sleep(100);
				if (arduino->readSerialPort(raw_msg, 255) != 0) {
					str = raw_msg;
					if (str.find_last_of('\n') == std::string::npos) {
						arduino->readSerialPort(raw_msg, 255);
						str += raw_msg;
					}
					if (str[0] != '{')
						str = str.substr(str.find_first_of("\n") + 1, str.length());
					str = str.substr(0, str.find_last_of('\n') - 1);
					str = str.substr(str.find_last_of('\n') + 1, str.length());

					if (str.find('}') != std::string::npos && str.find('{') != std::string::npos) {
						j_msg_rcv = json::parse(str);

						btn = j_msg_rcv["bouton"];
						joystick = j_msg_rcv["JoyStick"];
					}
				}
			}
		}
		//system("pause");
		return _p1;
	}

	if (c == _cp2)
	{
		_p2.addToWins(c);
		system("CLS");
		gotoxy(25, 5);
		//std::cout << "P2 gagne la manche!" << std::endl << std::endl << std::endl;
		show.afficherRoundWinner(2);

		if (manette == FALSE)
			system("pause");

		if (manette == TRUE)
		{
			while (str == "") {
				Sleep(100);
				if (arduino->readSerialPort(raw_msg, 255) != 0) {
					str = raw_msg;
				}
			}
		}
		//system("pause");
		return _p2;
	}

	system("CLS");
	gotoxy(25, 5);
	std::cout << "Aucun gagnant!" << std::endl << std::endl << std::endl;
	return _p1;
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
	gotoxy(30, OFFSET_Y - 2);
	std::cout << "Player 1";

	for (int i = 0; i < _p1.getWinsSize(); i++)
	{
		Card* c = _p1.getCardWins(i);
		gotoxy(30, i + OFFSET_Y);
		show.afficherCard(c);
	}

	gotoxy(50, OFFSET_Y - 2);
	std::cout << "Player 2";

	for (int i = 0; i < _p2.getWinsSize(); i++)
	{
		Card* c = _p2.getCardWins(i);
		gotoxy(50, i + OFFSET_Y);
		show.afficherCard(c);
	}
}

void Game::playerTurn()
{
	system("CLS");
	gotoxy(25, 5);
	if (player)
		//std::cout << "P2 choisis sa carte" << std::endl << std::endl << std::endl;
		show.afficherRoundTurn(2);
	else
		//std::cout << "P1 choisis sa carte" << std::endl << std::endl << std::endl;
		show.afficherRoundTurn(1);

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

// Version fonctionnelle dans VScode et Visual Studio
	buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
	str_buffer.assign(char_buffer, buffer_size);
	msg.append(str_buffer);

	//msg.pop_back(); //remove '/n' from string

	return true;
}

bool Game::SendToSerial(SerialPort* arduino, json j_msg) {
	// Return 0 if error
	std::string msg = j_msg.dump();
	bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
	return ret;
}