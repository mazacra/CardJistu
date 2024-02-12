#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

#define STARTING_HAND 5

class Player
{
public:
	Player();
	~Player();

	bool getAI();
	void setAI(bool b);
	void generateDeck();

	void addToDeck(Card* c);
	void addToWins(Card* c);

private:
	bool _AI;
	std::vector<Card*> _deck;
	std::vector<Card*> _wins;
	Card* playedCard;
};

#endif // !PLAYER_H
