#ifndef CARD_H
#define CARD_H

#define ELEMENTS 3
#define NUMBERS 10
#define COLORS 5

class Card
{
public:
	Card();
	~Card();

	int getElement();
	void setElement(int e);
	int getNumber();
	void setNumber(int n);
	int getColor();
	void setColor(int c);

private:
	int _element; //1 : fire, 2 : water, 3 : snow
	int _number; //Nombres de 1 à 10
	int _color;
};

#endif // !CARD_H
