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
	int getDeckSize();
	int getWinsSize();
	Card* getCard(int i);
	Card* getCardWins(int i);

	void generateDeck();
	Card* getPlayedCard();

	void addToDeck(Card* c);
	void addToWins(Card* c);

private:
	bool _AI;
	std::vector<Card*> _deck;
	std::vector<Card*> _wins;
	Card* _playedCard;
};

#endif // !PLAYER_H
