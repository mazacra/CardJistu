#include <cstdlib>
#include <iostream>
#include <string>
#include "Card.h"

Card::Card() 
{
	_element = (Element)((rand()) % ELEMENTS);
	_number = ((rand()) % NUMBERS);
	_color = (Color)((rand()) % COLORS);
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

//void Card::afficherCard()
//{
//	std::string element;
//    switch (_element)
//    {
//	case Element::fire: element = "Fire"; break;
//	case Element::water: element = "Water"; break;
//	case Element::snow: element = "Snow"; break;
//    }
//
//	std::string color;
//	switch (_color)
//	{
//	case Color::yellow: color = "Yellow"; break;
//	case Color::red: color = "Red"; break;
//	case Color::green: color = "Green"; break;
//	case Color::blue: color = "Blue"; break;
//	}
//
//	std::cout << element << " " << color << " (" << _number << ")    " << std::endl;
//}