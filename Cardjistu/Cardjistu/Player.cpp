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

int Player::getWinsSize()
{
	return _wins.size();
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

Card* Player::getCardWins(int i)
{
	try
	{
		return _wins[i];
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}

void Player::removeCard(int index)
{
	std::vector<Card*> newD;

	for (int i = 0; i < _deck.size(); i++)
	{
		if (index != i)
			newD.push_back(_deck[i]);
	}

	_deck.clear();
	_deck = newD;
}

int Player::getHighest()
{
	int index = 0;
	int max = -1;

	for (int i = 0; i < _deck.size(); i++)
	{
		Card* c = _deck[i];

		if (c->getNumber() > max) {
			index = i;
			max = c->getNumber();
		}
	}

	return index;
}

int Player::getHighestFire()
{
	int index = 0;
	int max = -1;

	for (int i = 0; i < _deck.size(); i++)
	{
		Card* c = _deck[i];

		if (c->getElement() == (Element)0) {
			if (c->getNumber() > max) {
				index = i;
				max = c->getNumber();
			}
		}
	}

	return index;
}

int Player::getHighestWater()
{
	int index = 0;
	int max = -1;

	for (int i = 0; i < _deck.size(); i++)
	{
		Card* c = _deck[i];

		if (c->getElement() == (Element)1) {
			if (c->getNumber() > max) {
				index = i;
				max = c->getNumber();
			}
		}
	}

	return index;
}

int Player::getHighestSnow()
{
	int index = 0;
	int max = -1;

	for (int i = 0; i < _deck.size(); i++)
	{
		Card* c = _deck[i];

		if (c->getElement() == (Element)2) {
			if (c->getNumber() > max) {
				index = i;
				max = c->getNumber();
			}
		}
	}

	return index;
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

void Player::drawCard()
{
	Card* c = new Card();
	_deck.push_back(c);
}

int Player::AISelectCard()
{
	int cptF = 0;
	int cptW = 0;
	int cptS = 0;
	int ordre[3];

	for (int i = 0; i < _wins.size(); i++)
	{
		Card* c = _wins[i];
		if (c->getElement() == (Element)0)
			cptF++;
		else if (c->getElement() == (Element)1)
			cptW++;
		else
			cptS++;

	}

	if (cptF != 0 && cptS != 0 && cptW != 0)
	{
		if (cptF > cptS && cptF > cptW) {
			getHighestFire();
		}
		if (cptS > cptF && cptS > cptW) {
			getHighestSnow();
		}
		if (cptW > cptF && cptW > cptS) {
			getHighestWater();
		}
	}

	return getHighest();
}

void Player::addToDeck(Card* c)
{
	_deck.push_back(c);
}

void Player::addToWins(Card* c)
{
	_wins.push_back(c);
}