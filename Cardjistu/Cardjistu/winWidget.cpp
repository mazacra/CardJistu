#include "winWidget.h"

WinWidget::WinWidget(QWidget* parent) : QWidget(parent) {
	layout = new QGridLayout(this);

	layout->setColumnMinimumWidth(0, 30);
	layout->setColumnMinimumWidth(1, 30);
	layout->setColumnMinimumWidth(2, 30);

	layout->setColumnMinimumWidth(3, 200);

	layout->setColumnMinimumWidth(4, 30);
	layout->setColumnMinimumWidth(5, 30);
	layout->setColumnMinimumWidth(6, 30);

	QLabel* l = new QLabel();
	l->setFixedSize(25, 25);

	l->setPixmap(QPixmap("./img/fire.png"));
	l->setScaledContents(true);
	layout->addWidget(l, 0, 0);

	l = new QLabel();
	l->setFixedSize(25, 25);
	l->setPixmap(QPixmap("./img/water.png"));
	l->setScaledContents(true);
	layout->addWidget(l, 0, 1);

	l = new QLabel();
	l->setFixedSize(25, 25);
	l->setPixmap(QPixmap("./img/snow.png"));
	l->setScaledContents(true);
	layout->addWidget(l, 0, 2);

	l = new QLabel();
	l->setFixedSize(25, 25);
	l->setPixmap(QPixmap("./img/fire.png"));
	l->setScaledContents(true);
	layout->addWidget(l, 0, 4);

	l = new QLabel();
	l->setFixedSize(25, 25);
	l->setPixmap(QPixmap("./img/water.png"));
	l->setScaledContents(true);
	layout->addWidget(l, 0, 5);

	l = new QLabel();
	l->setFixedSize(25, 25);
	l->setPixmap(QPixmap("./img/snow.png"));
	l->setScaledContents(true);
	layout->addWidget(l, 0, 6);
}

WinWidget::~WinWidget() {

}

void WinWidget::addWin(int p, const char* text)
{
	QLabel* label = new QLabel();
	label->setFixedSize(25, 25);
	std::string color = "border-width: 1px; border-style: solid; border-color: black; border-radius: 25px; background-color: ";
	color += text[0] == '0' ? "yellow;" : text[0] == '1' ? "red;" : text[0] == '2' ? "green;" : "blue;";
	label->setStyleSheet(color.c_str());

	if (p == 0) {
		if (text[1] == '0') {
			//feu
			layout->addWidget(label, cptFP1, 0);
			cptFP1++;
		}
		else if (text[1] == '1')
		{
			//eau
			layout->addWidget(label, cptEP1, 1);
			cptEP1++;
		}
		else
		{
			//neige
			layout->addWidget(label, cptNP1, 2);
			cptNP1++;
		}
	}
	else {
		if (text[1] == '0') {
			//feu
			layout->addWidget(label, cptFP2, 4);
			cptFP2++;
		}
		else if (text[1] == '1')
		{
			//eau
			layout->addWidget(label, cptEP2, 5);
			cptEP2++;
		}
		else
		{
			//neige
			layout->addWidget(label, cptNP2, 6);
			cptNP2++;
		}
	}
}
