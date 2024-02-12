#include <cstdlib>
#include "Card.h"

Card::Card() 
{
	_power = rand() % POWERS;
	_color = rand() % COLORS;
	_type = rand() % TYPES;
}

Card::~Card()
{
	
}