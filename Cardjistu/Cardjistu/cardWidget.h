#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <Qlabel>
#include <iostream>
#include <string>

class CardWidget : public QWidget
{
	Q_OBJECT

public:
	CardWidget(QWidget* parent);
	~CardWidget();

	void createCards();
	void showPlayerCard(std::vector<std::string> l);
	void changeSelected(int last, int newI);

private:

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

	const char* selectedStyle = "border-width: 5px; border-style: solid; border-color: black;";
};

#endif // !CARDWIDGET_H

