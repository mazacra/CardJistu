#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int _power;
    int _color;
    int _type;
public:
    Card();
    Card(int p, int c, int t);

    Card generateRandomCard();

    ~Card();
};

#endif