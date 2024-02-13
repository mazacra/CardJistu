#include <cstdlib>
#include "Card.h"
#include "Element.h"

Card::Card() 
{
	_element = rand() % ELEMENTS + 1;
	_number = rand() % NUMBERS + 1;
	_color = rand() % COLORS + 1;
}

Card::~Card()
{
	
}

Element Card::getElement()
{
	return _element;
}

void Card::setElement(int e)
{
	_element = (Element)e;
}

int Card::getNumber()
{
	return _number;
}

void Card::setNumber(int n)
{
	_number = n;
}

Color Card::getColor()
{
	return _color;
}

void Card::setColor(int c)
{
	_color = (Color)c;
}