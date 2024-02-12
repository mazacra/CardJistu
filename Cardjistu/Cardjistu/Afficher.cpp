#include <iostream>
#include "Afficher.h"

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
}
