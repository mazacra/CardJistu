#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>

#include "Game.h"

class menuWindow : public QWidget
{

public:
	menuWindow(QWidget* parent);
	~menuWindow();

	//init functions
	void initButtons();
	void initImg();
	void initAction();

	//actions functions
	void showP1_Options();
	void showP2_Options();
	void show_Info();
	void show_Menu();

	//fonctions jeu
	void newGame(bool solo);
	void gameLoop();

private:
	QTimer* timer;
	QGridLayout* mainLayout;

	QLabel* label_Title;
	QLabel* label_Sensei;
	QLabel* label_info;

	QPushButton* button_P1; 
	QPushButton* button_P2; 
	QPushButton* button_Info;
	QPushButton* button_Retour;

	QAction* action_btnP1;
	QAction* action_btnP2;
	QAction* action_btnInfo;
	QAction* action_btnRetour;

	Game* game;
	int winner;
	int wp;
	int activeP;
	int iCard;
	int iCardP1, iCardP2;
};

#endif // !MENU_WINDOW_H