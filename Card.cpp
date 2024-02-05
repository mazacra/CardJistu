#include "Card.h"
#include <iostream>

Card::Card(){
    _power = std::rand() % 10; //0 à 9
    _color = std::rand() % 5;  //0 à 4
    _type = std::rand() % 4;  //0 à 3
}

Card::Card(int p, int c, int t) : _power(p), _color(c), _type(t)
{

}

Card Card::generateRandomCard()
{
    int p = std::rand() % 10; //0 à 9
    int c = std::rand() % 5;  //0 à 4
    int t = std::rand() % 4;  //0 à 3

    return Card(p,c,t);
}

Card::~Card(){}