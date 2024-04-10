#ifndef WINWIDGET_H
#define WINWIDGET_H

#include <QWidget>
#include <QGridlayout>
#include <Qlabel>
#include <iostream>
#include <string>

class WinWidget : public QWidget {
	Q_OBJECT

private:
	QGridLayout* layout;

	int cptFP1 = 1;
	int cptNP1 = 1;
	int cptEP1 = 1;

	int cptFP2 = 1;
	int cptNP2 = 1;
	int cptEP2 = 1;
public:
	WinWidget(QWidget* parent);
	~WinWidget();

	void addWin(int p, const char* text);
};

#endif