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

	void getP1Name();
	void getP2Name();

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
	QLabel* label_info;
	QLabel* label_PlayerName;
	QLabel* p1_instruct;
	QLabel* p2_instruct;

	QPushButton* button_P1; 
	QPushButton* button_P2; 
	QPushButton* button_Info;
	QPushButton* button_Retour;
	QPushButton* button_GO;

	QLineEdit* name_P1;
	QLineEdit* name_P2;

	QAction* action_btnP1;
	QAction* action_btnP2;
	QAction* action_btnInfo;
	QAction* action_btnRetour;
	QAction* action_btnGO;

	//Cartes
	QLabel* c1;
	QLabel* c1P;
	QLabel* c1E;
		  
	QLabel* c2;
	QLabel* c2P;
	QLabel* c2E;
		  
	QLabel* c3;
	QLabel* c3P;
	QLabel* c3E;
		  
	QLabel* c4;
	QLabel* c4P;
	QLabel* c4E;
		  
	QLabel* c5;
	QLabel* c5P;
	QLabel* c5E;

	QList<QLabel*>* winP1;
	QList<QLabel*>* winP2;

	WinWidget* widget;

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