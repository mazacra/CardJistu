#include "Player.h"
#include "Card.h"

Player::Player()
{
    Card* card = new Card();

    _deck.push_back(card);
}

Player::~Player(){}