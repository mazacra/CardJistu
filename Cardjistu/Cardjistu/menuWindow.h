#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

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

private:
	QTimer* timer;
	QGridLayout* mainLayout;

	QLabel* label_Title;

	QPushButton* button_P1; 
	QPushButton* button_P2; 
	QPushButton* button_Info;

	QAction* action_btnP1;
	QAction* action_btnP2;
	QAction* action_btnInfo;
};

#endif // !MENU_WINDOW_H