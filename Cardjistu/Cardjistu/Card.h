#ifndef CARD_H
#define CARD_H

#define ELEMENTS 3
#define NUMBERS 10
#define COLORS 4

enum class Element {
	fire,
	water,
	snow
};

enum class Color {
	yellow,
	red,
	green,
	blue
};

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

	//void afficherCard();

private:
	Element _element; //0 : fire, 1 : water, 2 : snow
	int _number; //Nombres de 0 à 9
	Color _color;
};

#endif // !CARD_H
