#ifndef CARD_H
#define CARD_H

#define ELEMENTS 3
#define NUMBERS 10
#define COLORS 4

#include "Element.h"

class Card
{
public:
	Card();
	~Card();

	Element getElement();
	void setElement(int e);
	int getNumber();
	void setNumber(int n);
	Color getColor();
	void setColor(int c);

private:
	Element _element; //1 : fire, 2 : water, 3 : snow
	int _number; //Nombres de 1 à 10
	Color _color;
};

#endif // !CARD_H
