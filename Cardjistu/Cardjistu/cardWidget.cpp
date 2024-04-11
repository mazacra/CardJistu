#include "cardWidget.h"

CardWidget::CardWidget(QWidget* parent) : QWidget(parent) {
	c1 = new QLabel(this);
	c1E = new QLabel(this);
	c1P = new QLabel(this);
	c2 = new QLabel(this);
	c2E = new QLabel(this);
	c2P = new QLabel(this);
	c3 = new QLabel(this);
	c3E = new QLabel(this);
	c3P = new QLabel(this);
	c4 = new QLabel(this);
	c4E = new QLabel(this);
	c4P = new QLabel(this);
	c5 = new QLabel(this);
	c5E = new QLabel(this);
	c5P = new QLabel(this);
}

CardWidget::~CardWidget()
{
}

void CardWidget::createCards()
{
	c1->setFixedSize(120, 120);
	c1->move(70, 550);
	c1E->setFixedSize(50, 50);
	c1E->move(105, 600);
	c1P->setStyleSheet("font-size: 18pt;");
	c1P->move(123, 560);

	c2->setFixedSize(120, 120);
	c2->move(210, 550);
	c2E->setFixedSize(50, 50);
	c2E->move(245, 600);
	c2P->setStyleSheet("font-size: 18pt;");
	c2P->move(261, 560);

	c3->setFixedSize(120, 120);
	c3->move(350, 550);
	c3E->setFixedSize(50, 50);
	c3E->move(385, 600);
	c3P->setStyleSheet("font-size: 18pt;");
	c3P->move(401, 560);

	c4->setFixedSize(120, 120);
	c4->move(490, 550);
	c4E->setFixedSize(50, 50);
	c4E->move(525, 600);
	c4P->setStyleSheet("font-size: 18pt;");
	c4P->move(541, 560);

	c5->setFixedSize(120, 120);
	c5->move(630, 550);
	c5E->setFixedSize(50, 50);
	c5E->move(665, 600);
	c5P->setStyleSheet("font-size: 18pt;");
	c5P->move(681, 560);
}

void CardWidget::showPlayerCard(std::vector<std::string> l)
{
	for (int i = 0; i < l.size(); i++)
	{
		std::string s = l[i];
		std::string color = "border-radius: 25px; background-color: ";
		color += s[0] == '0' ? "yellow;" : s[0] == '1' ? "red;" : s[0] == '2' ? "green;" : "blue;";
		std::string element = "./img/";
		element += s[1] == '0' ? "fire.png" : s[1] == '1' ? "water.png" : "snow.png";
		const char* power = &s[2];

		switch (i)
		{
		case 0:
			c1->setStyleSheet((color.append(selectedStyle)).c_str());
			c1E->setPixmap(QPixmap(element.c_str()));
			c1E->setScaledContents(true);
			c1P->setText(power);

			c1->show();
			c1E->show();
			c1P->show();
			break;
		case 1:
			c2->setStyleSheet(color.c_str());
			c2E->setPixmap(QPixmap(element.c_str()));
			c2E->setScaledContents(true);
			c2P->setText(power);

			c2->show();
			c2E->show();
			c2P->show();
			break;
		case 2:
			c3->setStyleSheet(color.c_str());
			c3E->setPixmap(QPixmap(element.c_str()));
			c3E->setScaledContents(true);
			c3P->setText(power);

			c3->show();
			c3E->show();
			c3P->show();
			break;
		case 3:
			c4->setStyleSheet(color.c_str());
			c4E->setPixmap(QPixmap(element.c_str()));
			c4E->setScaledContents(true);
			c4P->setText(power);

			c4->show();
			c4E->show();
			c4P->show();
			break;
		case 4:
			c5->setStyleSheet(color.c_str());
			c5E->setPixmap(QPixmap(element.c_str()));
			c5E->setScaledContents(true);
			c5P->setText(power);

			c5->show();
			c5E->show();
			c5P->show();
			break;
		default:
			break;
		}
	}
}

void CardWidget::changeSelected(int last, int newI)
{
	std::string s;
	int i;
	switch (last)
	{
	case 0:
		s = c1->styleSheet().toStdString();
		i = s.find("border-width");
		s = s.substr(0, i) + s.substr(i + 60, s.length());

		c1->setStyleSheet(s.c_str());
		break;
	case 1:
		s = c2->styleSheet().toStdString();
		i = s.find("border-width");
		s = s.substr(0, i) + s.substr(i + 60, s.length());

		c2->setStyleSheet(s.c_str());
		break;
	case 2:
		s = c3->styleSheet().toStdString();
		i = s.find("border-width");
		s = s.substr(0, i) + s.substr(i + 60, s.length());

		c3->setStyleSheet(s.c_str());
		break;
	case 3:
		s = c4->styleSheet().toStdString();
		i = s.find("border-width");
		s = s.substr(0, i) + s.substr(i + 60, s.length());

		c4->setStyleSheet(s.c_str());
		break;
	case 4:
		s = c5->styleSheet().toStdString();
		i = s.find("border-width");
		s = s.substr(0, i) + s.substr(i + 60, s.length());

		c5->setStyleSheet(s.c_str());
		break;
	default:
		break;
	}

	switch (newI)
	{
	case 0:
		c1->setStyleSheet(c1->styleSheet() + selectedStyle);
		break;
	case 1:
		c2->setStyleSheet(c2->styleSheet() + selectedStyle);
		break;
	case 2:
		c3->setStyleSheet(c3->styleSheet() + selectedStyle);
		s = c3->styleSheet().toStdString();
		break;
	case 3:
		c4->setStyleSheet(c4->styleSheet() + selectedStyle);
		break;
	case 4:
		c5->setStyleSheet(c5->styleSheet() + selectedStyle);
		break;
	default:
		break;
	}
}