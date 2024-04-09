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
	std::vector<Card*> getCards();
	Card* getCardWins(int i);
	void removeCard(int index);

	int getHighest();
	int getHighestFire();
	int getHighestWater();
	int getHighestSnow();

	void generateDeck();
	Card* getPlayedCard();
	void drawCard();

	int AISelectCard();

	void addToDeck(Card* c);
	void addToWins(Card* c);

private:
	bool _AI;
	std::vector<Card*> _deck;
	std::vector<Card*> _wins;
	Card* _playedCard;
};

#endif // !PLAYER_H
