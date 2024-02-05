#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player
{
private:
    std::vector<Card*> _deck;
    std::vector<Card*> _wins;
public:
    Player();
    ~Player();
};

#endif