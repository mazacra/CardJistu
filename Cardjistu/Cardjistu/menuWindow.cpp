#include "menuWindow.h"

menuWindow::menuWindow(QWidget* parent = nullptr) : QWidget(parent)
{
	this->setFixedSize(820, 700);

	//Background color
	QPalette pal = QPalette();
	pal.setColor(QPalette::Window, QColor(244, 242, 197).rgba());
	setAutoFillBackground(true);
	setPalette(pal);

	initLabel();
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

	button_GO = new QPushButton(tr("GO!"), this);
	button_GO->setFixedSize(200, 75);
	connect(button_GO, &QPushButton::clicked, this, &menuWindow::newGame); //Changer show_info
	button_GO->move(50, 575);
	button_GO->hide();
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

	label_CardBG = new QLabel(this);
	label_CardBG->setPixmap(QPixmap("./img/card_bg.png"));
	label_CardBG->setScaledContents(true);
	label_CardBG->setFixedSize(820, 200);
	label_CardBG->move(0, 500);
	label_CardBG->hide();
}

void menuWindow::initAction()
{
	action_btnP1 = new QAction();

	action_btnP2 = new QAction();

	action_btnInfo = new QAction();

    action_btnRetour = new QAction();

	action_btnGO = new QAction();
}

void menuWindow::initLineEdit()
{
	p1_instruct = new QLabel(tr("P1, entrez votre nom"), this);
	p1_instruct->move(100, 280);

	p2_instruct = new QLabel(tr("P2, entrez votre nom"), this);
	p2_instruct->move(100, 330);

	name_P1 = new QLineEdit(this);
	name_P1->setPlaceholderText("Nom");
	name_P1->setFixedSize(200, 25);
	name_P1->move(100, 300);
	connect(name_P1, &QLineEdit::returnPressed, this, &menuWindow::getP1Name);
	name_P1->hide();

	name_P2 = new QLineEdit(this);
	name_P2->setPlaceholderText("Nom");
	name_P2->setFixedSize(200, 25);
	name_P2->move(100, 350);
	connect(name_P2, &QLineEdit::returnPressed, this, &menuWindow::getP2Name);
	name_P2->hide();
}

void menuWindow::initLabel()
{
	label_info = new QLabel(this);
	label_info->setStyleSheet("font-weight: bold;");
	QFont font;
	font.setPointSize(10);
	label_info->setFont(font);
	label_info->move(20, 275);
	label_info->hide();

	label_PlayerName = new QLabel(this);
	label_PlayerName->move(50, 100);
	label_PlayerName->hide();
}

void menuWindow::showP1_Options()
{
	solo = true;
	button_P1->hide();
	button_P2->hide();
	button_Info->hide();

	initLineEdit();
	p1_instruct->show();
	name_P1->show();
	button_GO->show();
}

void menuWindow::showP2_Options()
{
	solo = false;
	button_P1->hide();
	button_P2->hide();
	button_Info->hide();

	initLineEdit();
	p1_instruct->show();
	name_P1->show();
	p2_instruct->show();
	name_P2->show();
	button_GO->show();
}

void menuWindow::show_Info()
{
	button_P1->hide();
	button_P2->hide();
	button_Info->hide();

	button_Retour->show();

	if (label_info->text() == "") {
		label_info->setText(label_info->text() + "Les joueurs commencent chacun avec 5 cartes. \nChaque carte a un element(Feu, Neige ou Eau), un nombre(entre 1 et 10) et une couleur.");
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
	}
	label_info->show();
}

void menuWindow::show_Menu() //Rajouter tout les nouveaux éléments à enlever
{
	button_P1->show();
	button_P2->show();
	button_Info->show();

	button_Retour->hide();
	label_info->hide();

	label_PlayerName->hide();

}

void menuWindow::getP1Name()
{
	QString p1Name = name_P1->text();
}

void menuWindow::getP2Name()
{
	QString p2Name = name_P2->text();
}

void menuWindow::newGame(bool solo)
{
	winner = -1;
	activeP = 0;
	iCardP1 = 0;
	iCardP1 = 0;
	game = new Game();
	timer = new QTimer(this);

	label_Sensei->hide();
	label_CardBG->show();
	createCards();
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
			label_PlayerName->setText(p1Name.c_str());
			showPlayerCard(activeP);

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

void menuWindow::createCards()
{
	if (c1 == nullptr) {
		c1 = new QLabel(this);
		c1->setFixedSize(120, 120);
		c1->move(70, 550);
		c1->setStyleSheet("border-radius: 25px;");
		c1E = new QLabel(this);
		c1E->setFixedSize(50, 50);
		c1E->move(105, 600);
		c1P = new QLabel(this);
		c1P->setStyleSheet("font-size: 18pt;");
		c1P->move(123, 560);

		c2 = new QLabel(this);
		c2->setFixedSize(120, 120);
		c2->move(210, 550);
		c2->setStyleSheet("border-radius: 25px;");
		c2E = new QLabel(this);
		c2E->setFixedSize(50, 50);
		c2E->move(245, 600);
		c2P = new QLabel(this);
		c2P->setStyleSheet("font-size: 18pt;");
		c2P->move(261, 560);

		c3 = new QLabel(this);
		c3->setFixedSize(120, 120);
		c3->move(350, 550);
		c3->setStyleSheet("border-radius: 25px;");
		c3E = new QLabel(this);
		c3E->setFixedSize(50, 50);
		c3E->move(385, 600);
		c3P = new QLabel(this);
		c3P->setStyleSheet("font-size: 18pt;");
		c3P->move(401, 560);

		c4 = new QLabel(this);
		c4->setFixedSize(120, 120);
		c4->move(490, 550);
		c4->setStyleSheet("border-radius: 25px;");
		c4E = new QLabel(this);
		c4E->setFixedSize(50, 50);
		c4E->move(525, 600);
		c4P = new QLabel(this);
		c4P->setStyleSheet("font-size: 18pt;");
		c4P->move(541, 560);

		c5 = new QLabel(this);
		c5->setFixedSize(120, 120);
		c5->move(630, 550);
		c5->setStyleSheet("border-radius: 25px;");
		c5E = new QLabel(this);
		c5E->setFixedSize(50, 50);
		c5E->move(665, 600);
		c5P = new QLabel(this);
		c5P->setStyleSheet("font-size: 18pt;");
		c5P->move(681, 560);
	}
}

void menuWindow::showPlayerCard(int i)
{
	std::vector<std::string> l = game->getPlayerCards(i);

	for (int i = 0; i < l.size(); i++)
	{
		std::string s = l[i];
		std::string color = "background-color: ";
		color += s[0] == '0' ? "yellow" : s[0] == '1' ? "red" : s[0] == '2' ? "green" : "blue";
		std::string element = "background-color: ";
		element += s[1] == '0' ? "red" : s[1] == '1' ? "blue" : "aqua";
		const char* power = &s[2];

		switch (i)
		{
		case 0:
			c1->setStyleSheet(c1->styleSheet().append(color.c_str()));
			c1E->setStyleSheet(element.c_str());
			c1P->setText(power);
			break;
		case 1:
			c2->setStyleSheet(c2->styleSheet().append(color.c_str()));
			c2E->setStyleSheet(element.c_str());
			c2P->setText(power);
			break;
		case 2:
			c3->setStyleSheet(c3->styleSheet().append(color.c_str()));
			c3E->setStyleSheet(element.c_str());
			c3P->setText(power);
			break;
		case 3:
			c4->setStyleSheet(c4->styleSheet().append(color.c_str()));
			c4E->setStyleSheet(element.c_str());
			c4P->setText(power);
			break;
		case 4:
			c5->setStyleSheet(c5->styleSheet().append(color.c_str()));
			c5E->setStyleSheet(element.c_str());
			c5P->setText(power);
			break;
		default:
			break;
		}
	}
}
