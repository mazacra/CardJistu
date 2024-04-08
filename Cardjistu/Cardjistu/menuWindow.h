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

	//fonctions jeu
	void newGame(bool solo);
	void gameLoop();

private:
	QTimer* timer;
	QGridLayout* mainLayout;

	QLabel* label_Title;
	QLabel* label_Sensei;

	QPushButton* button_P1; 
	QPushButton* button_P2; 
	QPushButton* button_Info;

	QAction* action_btnP1;
	QAction* action_btnP2;
	QAction* action_btnInfo;

	Game* game;
	int winner;
	int wp;
	int activeP;
	int iCard;
	int iCardP1, iCardP2;
};

#endif // !MENU_WINDOW_H