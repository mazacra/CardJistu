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

int Player::getDeckSize()
{
	return _deck.size();
}

Card* Player::getCard(int i)
{
	try
	{
		return _deck[i];
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}

void Player::generateDeck()
{
	for (int i = 0; i < STARTING_HAND; i++)
	{
		Card* c = new Card();
		_deck.push_back(c);
	}
}

Card* Player::getPlayedCard()
{
	return _playedCard;
}

void Player::addToDeck(Card* c)
{
	_deck.push_back(c);
}

void Player::addToWins(Card* c)
{
	_wins.push_back(c);
}