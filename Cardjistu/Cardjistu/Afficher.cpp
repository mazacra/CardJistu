#include <iostream>
#include "Afficher.h"
#include "Card.h"
#include "Element.h"

Afficher::Afficher()
{

}

Afficher::~Afficher()
{

}

void Afficher::menuPrincipal()
{
	system("cls");
	std::cout << "============================================================================" << std::endl;
	std::cout << " _____           _____  _____       _ _____ _______ _____ _    _\n" << "/ ____|    /\\   |  __ \\|  __ \\     | |_   _|__   __/ ____| |  | |\n" << "| |       /  \\  | |__) | |  | |    | | | |    | | | (___ | |  | |\n" << "| |      / /\\ \\ |  _  /| |  | |_   | | | |    | |  \\___ \\| |  | |\n" << "| |____ / ____ \\| | \\ \\| |__| | |__| |_| |_   | |  ____) | |__| |\n" << "\\_____ /_/    \\_\\_|  \\_\\_____/ \\____/|_____|  |_| |_____/ \\____/\n" << std::endl;
	std::cout << "============================================================================" << std::endl;

	std::cout << "Inserez soit le nombre de joueur (1 ou 2), I pour les informations ou Q pour quitter" << std::endl;
	std::cout << "Input : ";
}

void Afficher::menuInformation()
{
	system("cls");

	std::cout << "============================================================================" << std::endl;
	std::cout << " _____            _                 _           _\n" << "|  __ \\          | |               | |         (_)\n" << "| |__) |___  __ _| | ___  ___    __| |_   _     _  ___ _   _\n" << "|  _  // _ \\/ _` | |/ _ \\/ __|  / _` | | | |   | |/ _ \\ | | |\n" << "| | \\ \\  __/ (_| | |  __/\\__ \\ | (_| | |_| |   | |  __/ |_| |\n" << "|_|  \\_\\___|\\__, |_|\\___||___/  \\__,_|\\__,_|   | |\\___|\\__,_|\n" << "	     __/ |                            _/ |\n" << "	    |___/                            |__/\n" << std::endl;
	std::cout << "============================================================================" << std::endl;

	std::cout << "Les joueurs commencent chacun avec 5 cartes. Chaque carte a un element (Feu, Neige ou Eau), un nombre (entre 1 et 10) et une couleur." << std::endl << std::endl;
	std::cout << "Au debut de chaque manche, chaque joueur choisi une carte a jouer." << std::endl;
	std::cout << "La meilleure carte remporte la manche." << std::endl;
	std::cout << "\t -Le Feu l'emporte sur la Neige" << std::endl;
	std::cout << "\t -La Neige l'emporte sur l'Eau" << std::endl;
	std::cout << "\t -L'Eau l'emporte sur le Feu" << std::endl;
	std::cout << "\t -Si les deux cartes ont le même élément, le plus haut Nombre l'Emporte." << std::endl << std::endl;
	std::cout << "La carte gagante est placee dans la pile gagnate du joueur qui a remporté la manche, et la carte perdante est éliminee." << std::endl;
	std::cout << "Si l'element et le nombre est le même, aucun des joueurs ne l'emportent et ils conservent leur carte" << std::endl << std::endl;
	std::cout << "Pour remporter la partie, le joueur doit avoir un set gagnant dans sa pile, soit : " << std::endl;
	std::cout << "\t -Trois cartes du meme element;" << std::endl;
	std::cout << "\tOU" << std::endl;
	std::cout << "\t -Trois cartes d'un element different, chacune de couleur differente." << std::endl << std::endl;
	std::cout << "Pour retourner au menu principal, appuyez sur n'importe quelle touche" << std::endl;
}

void Afficher::menuSelection()
{
	system("cls");

	std::cout << "============================================================================" << std::endl;
	std::cout << "  _____ _           _     _       _                         _\n" << " / ____| |         (_)   (_)     | |                       | |\n" << "| |    | |__   ___  _ ___ _ ___  | |_ __ _    ___ __ _ _ __| |_ ___\n" << "| |    | '_ \\ / _ \\| / __| / __| | __/ _` |  / __/ _` | '__| __/ _ \\\n" << "| |____| | | | (_) | \\__ \\ \\__ \\ | || (_| | | (_| (_| | |  | ||  __/\n" << " \\_____|_| |_|\\___/|_|___/_|___/  \\__\\__,_|  \\___\\__,_|_|   \\__\\___|\n" << std::endl;
	std::cout << "============================================================================" << std::endl << std::endl;
}

void Afficher::infoCarte(Card* c)
{
	std::cout << c->getColor() << " " << c->getElement() << " (" << c->getNumber() << ")" << std::endl;
}
