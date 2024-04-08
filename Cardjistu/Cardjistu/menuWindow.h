#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>
#include <QLineEdit>

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
	void initLineEdit();

	//actions functions
	void show1P_Options();
	void show2P_Options();
	void show_Info();

	void getP1Name();
	void getP2Name();

private:
	QTimer* timer;
	QGridLayout* mainLayout;

	QLabel* label_Title;
	QLabel* label_Sensei;
	QLabel* p1_instruct;
	QLabel* p2_instruct;

	QPushButton* button_P1; 
	QPushButton* button_P2; 
	QPushButton* button_Info;
	QPushButton* button_GO;

	QLineEdit* name_P1;
	QLineEdit* name_P2;

	QAction* action_btnP1;
	QAction* action_btnP2;
	QAction* action_btnInfo;
	QAction* action_btnGO;
};

#endif // !MENU_WINDOW_H