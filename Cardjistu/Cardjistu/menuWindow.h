#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>
#include <QList>
#include <iostream>
#include <string>

#include "Game.h"
#include "winWidget.h"
#include <cardWidget.h>

class menuWindow : public QWidget
{

public:
	menuWindow(QWidget* parent);
	~menuWindow();

	//init functions
	void initButtons();
	void initImg();
	void initAction();
	void initLabel();
	void initLineEdit();

	//actions functions
	void showP1_Options();
	void showP2_Options();
	void show_Info();
	void show_Menu();
	void showTurn(int i);
	void showCardChose();
	void toggleCard();

	void getP1Name();
	void getP2Name();
	std::vector<std::string> getCardChose();

	//fonctions jeu
	void newGame();
	void gameLoop();
	void createCards();
	void showPlayerCard(int i);
	void changeSelected(int last, int newI);

private:
	QTimer* timer;

	QLabel* label_Title;
	QLabel* label_Sensei;
	QLabel* label_CardBG;
	QLabel* label_Belt;
	QLabel* label_info;
	QLabel* label_PlayerName;
	QLabel* label_Win;
	QLabel* p1_instruct;
	QLabel* p2_instruct;
	QLabel* messageGagnant;
	QLabel* overlayscreen;
	QLabel* text;

	QPushButton* button_P1; 
	QPushButton* button_P2; 
	QPushButton* button_Info;
	QPushButton* button_Retour;
	QPushButton* button_GO;
	QPushButton* button_Choix;

	QLineEdit* name_P1;
	QLineEdit* name_P2;

	QAction* action_btnP1;
	QAction* action_btnP2;
	QAction* action_btnInfo;
	QAction* action_btnRetour;
	QAction* action_btnGO;
	QAction* action_btnChoix;

	//Carte choisi
	QLabel* c1Choisi;
	QLabel* c1PChoisi;
	QLabel* c1EChoisi;

	QLabel* c2Choisi;
	QLabel* c2PChoisi;
	QLabel* c2EChoisi;

	WinWidget* wWidget;
	CardWidget* cWidget;

	bool solo;
	Game* game;
	int winner;
	int wp;
	int activeP;
	int lastActiveP;
	int iCard;
	int iCardP1, iCardP2;
	std::string p1Name, p2Name;
	const char* selectedStyle = "border-width: 5px; border-style: solid; border-color: black;";
};

#endif // !MENU_WINDOW_H