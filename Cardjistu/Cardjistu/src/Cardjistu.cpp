#include <iostream>
#include <string>
#include "Afficher.h"
#include "Game.h"

int main_console()
{
	char choix = ' ';
	Game game;
	Afficher show;
	while (choix != 'Q')
	{
		show.menuPrincipal();
		std::cin >> choix;
		choix = std::toupper(choix);
		if (choix == 'Q')
			exit(0);

		if (choix == 'I') {
			show.menuInformation();
			system("pause");
		}

		if(choix == '1' || choix == '2')
		{
			int iChoix = choix - '0';

			switch (iChoix)
			{
			case 1:
				game.newGame(true);
				break;
			case 2:
				game.newGame(false);
				break;
			}
		}
	}
}
