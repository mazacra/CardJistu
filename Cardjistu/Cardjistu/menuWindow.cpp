#include "menuWindow.h"
#include <QTextEdit>

menuWindow::menuWindow(QWidget* parent = nullptr) : QWidget(parent)
{
	this->setFixedSize(820, 700);

	//Background color
	QPalette pal = QPalette();
	pal.setColor(QPalette::Window, QColor(244, 242, 197).rgba());
	setAutoFillBackground(true);
	setPalette(pal);

	initImg();
	initButtons();
}

menuWindow::~menuWindow()
{
}


void menuWindow::initButtons()
{
	initAction();

    button_P1 = new QPushButton(tr("1 Joueur"), this);
    button_P1->setFixedSize(200, 75);
    button_P1->addAction(action_btnP1);
    button_P1->move(100, 275);
    connect(button_P1, &QPushButton::clicked, this, &menuWindow::showP1_Options);

    button_P2 = new QPushButton(tr("2 Joueurs"), this);
    button_P2->setFixedSize(200, 75);
    button_P2->addAction(action_btnP2);
    button_P2->move(100, 425);
    connect(button_P2, &QPushButton::clicked, this, &menuWindow::showP2_Options);

    button_Info = new QPushButton(tr("Informations"), this);
    button_Info->setFixedSize(200, 75);
    button_Info->addAction(action_btnInfo);
    button_Info->move(100, 575);
    connect(button_Info, &QPushButton::clicked, this, &menuWindow::show_Info);

    button_Retour = new QPushButton(tr("Retour"), this);
    button_Retour->setFixedSize(150, 50);
    button_Retour->addAction(action_btnRetour);
    button_Retour->move(20, 625);
    connect(button_Retour, &QPushButton::clicked, this, &menuWindow::show_Menu);
    button_Retour->hide();
}

void menuWindow::initImg()
{
	label_Title = new QLabel(this);
	label_Title->setPixmap(QPixmap("./img/title.png"));
	label_Title->setScaledContents(true);
	label_Title->setFixedSize(500, 250);
	label_Title->move(150, 10);

	label_Sensei = new QLabel(this);
	label_Sensei->setPixmap(QPixmap("./img/sensei.png"));
	label_Sensei->setScaledContents(true);
	label_Sensei->setFixedSize(200, 400);
	label_Sensei->move(550, 270);
}

void menuWindow::initAction()
{
    action_btnP1 = new QAction();

    action_btnP2 = new QAction();

    action_btnInfo = new QAction();

    action_btnRetour = new QAction();
}

void menuWindow::showP1_Options()
{
}

void menuWindow::showP2_Options()
{
}

void menuWindow::show_Info()
{
    button_P1->hide();
    button_P2->hide();
    button_Info->hide();

    button_Retour->show();

    label_info = new QLabel("Les joueurs commencent chacun avec 5 cartes. \nChaque carte a un element(Feu, Neige ou Eau), un nombre(entre 1 et 10) et une couleur.",this);
    label_info->setText(label_info->text() + "\nAu début de chaque manche, chaque joueur choisi une carte a jouer.");
    label_info->setText(label_info->text() + "\nLa meilleure carte remporte la manche.");
    label_info->setText(label_info->text() + "\n\t -Le Feu l'emporte sur la Neige");
    label_info->setText(label_info->text() + "\n\t -La Neige l'emporte sur l'Eau");
    label_info->setText(label_info->text() + "\n\t -L'Eau l'emporte sur le Feu");
    label_info->setText(label_info->text() + "\n\t -Si les deux cartes ont le même élément, le plus haut Nombre l'Emporte.\n");
    label_info->setText(label_info->text() + "\nLa carte gagnante est placée dans la pile gagnante du joueur qui a remporté la manche,\n et la carte perdante est éliminée.");
    label_info->setText(label_info->text() + "\nSi l'élément et le nombre est le même,\naucun des joueurs ne l'emportent et ils conservent leur carte\n");
    label_info->setText(label_info->text() + "\nPour remporter la partie, le joueur doit avoir un set gagnant dans sa pile, soit : ");
    label_info->setText(label_info->text() + "\n\t -Trois cartes du même élément;");
    label_info->setText(label_info->text() + "\n\t\t OU");
    label_info->setText(label_info->text() + "\n\t -Trois cartes d'un élément différent, chacune de couleur différente.");
	label_info->setStyleSheet("font-weight: bold;");


    QFont font;
    font.setPointSize(10); 
    label_info->setFont(font);
    //label_info->setStyleSheet("color: blue");
    label_info->move(20, 275);
    label_info->show();

}

void menuWindow::show_Menu() //Rajouter tout les nouveaux éléments à enlever
{
    button_P1->show();
    button_P2->show();
    button_Info->show();

    button_Retour->hide();
    label_info->hide();
}

#pragma endregion

void menuWindow::newGame(bool solo)
{
	winner = -1;
	activeP = 0;
	game = new Game();
	timer = new QTimer(this);

	game->newGame(solo);

	if (!timer->isActive()) {
		connect(timer, &QTimer::timeout, this, &menuWindow::gameLoop);
		timer->start(30);
	}
}

void menuWindow::gameLoop()
{
	if (winner == 0) {
		if (activeP == 0 || activeP == 1) {
			//Selection de la carte
			int i = game->selectCardManette(activeP + 1);

			//-2 == carte choisi
			if (i == -2) {
				if (activeP == 0)
					iCardP1 = iCard;
				else
					iCardP2 = iCard;

				//Si on est au 2eme joueur il faut comparer les cartes
				if (activeP) {
					activeP = 2;
					wp = game->winningPlayer();
				}
				else {
					//change pour le joueur 2
					activeP = !activeP;
				}
			}
			else {
				//sinon change l'index
				iCard = i;

				//change l'affichage
			}
		}
		else {
			//afficher les deux cartes jouées

			//afficher le gagant de la round
			if (wp == 1) {
				//Afficher que P1 a gagné

				if (game->getWinner(1))
					winner = 1;
			}
			else if (wp == 2) {
				//Afficher que P2 a gagné

				if (game->getWinner(2))
					winner = 2;
			}
			else
			{
				//Afficher que égalité
			}
		}
	}
	else
	{
		timer->stop();
	}
}
