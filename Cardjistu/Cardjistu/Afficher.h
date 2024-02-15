#ifndef AFFICHER_H
#define AFFICHER_H

#include "Card.h"

class Afficher
{
public:
	Afficher();
	~Afficher();

	void menuPrincipal();
	void menuInformation();
	void menuSelection();
	void infoCarte(Card* c);
	void winner(int i);
private:

};

#endif // !AFFICHER_H
