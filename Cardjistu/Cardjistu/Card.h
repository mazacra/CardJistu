#ifndef CARD_H
#define CARD_H

#define POWERS 10
#define COLORS 5
#define TYPES 3

class Card
{
public:
	Card();
	~Card();

private:
	int _power;
	int _color;
	int _type;
};

#endif // !CARD_H
