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
private:
	bool _AI;
	std::vector<Card*> _deck;
	std::vector<Card*> _wins;
};

#endif // !PLAYER_H
