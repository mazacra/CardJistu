#include "Player.h"
#include "Card.h"

Player::Player()
{
	_AI = false;
}

Player::~Player()
{

}

bool Player::getAI()
{
	return _AI;
}

void Player::setAI(bool b)
{
	_AI = b;
}

void Player::generateDeck()
{
	for (int i = 0; i < STARTING_HAND; i++)
	{
		Card* c = new Card();
		_deck.push_back(c);
	}
}

void Player::addToDeck(Card* c)
{
	_deck.push_back(c);
}

void Player::addToWins(Card* c)
{
	_wins.push_back(c);
}