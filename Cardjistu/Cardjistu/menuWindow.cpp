#include "menuWindow.h"

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


#pragma region Init Functions

/// <summary>
/// Fonction d'initialisation des boutons et de leurs actions
/// </summary>
void menuWindow::initButtons()
{
    initAction();

    button_P1 = new QPushButton(tr("1 Joueur"), this);
    button_P1->setFixedSize(200, 75);
    connect(button_P1, &QPushButton::clicked, action_btnP1, &QAction::trigger);
    button_P1->move(100, 275);

    button_P2 = new QPushButton(tr("2 Joueurs"), this);
    button_P2->setFixedSize(200, 75);
    connect(button_P2, &QPushButton::clicked, action_btnP2, &QAction::trigger);
    button_P2->move(100, 425);

    button_Info = new QPushButton(tr("Informations"), this);
    button_Info->setFixedSize(200, 75);
    connect(button_Info, &QPushButton::clicked, action_btnInfo, &QAction::trigger);
    button_Info->move(100, 575);

    button_GO = new QPushButton(tr("GO!"), this);
    button_GO->setFixedSize(200, 75);
    connect(button_GO, &QPushButton::clicked, action_btnGO, &QAction::trigger);
    button_GO->move(50, 575);
    button_GO->hide();
}


/// <summary>
/// Fonction d<initialisation des images
/// </summary>
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
    label_Sensei->move(500, 270);
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

/// <summary>
/// Fonction d'initialisation des actions des boutons
/// </summary>
void menuWindow::initAction()
{
    action_btnP1 = new QAction();
    connect(action_btnP1, &QAction::triggered, this, &menuWindow::show1P_Options);

    action_btnP2 = new QAction();
    connect(action_btnP2, &QAction::triggered, this, &menuWindow::show2P_Options);

    action_btnInfo = new QAction();
    connect(action_btnInfo, &QAction::triggered, this, &menuWindow::show_Info);

    action_btnGO = new QAction();
    connect(action_btnGO, &QAction::triggered, this, &menuWindow::show_Info); //Changer à la bonne fct
}

void menuWindow::show1P_Options()
{
    button_P1->hide();
    button_P2->hide();
    button_Info->hide();

    initLineEdit();
    p1_instruct->show();
    name_P1->show();
    button_GO->show();
}

void menuWindow::show2P_Options()
{
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
}

void menuWindow::getP1Name()
{
    QString p1Name = name_P1->text();
}

void menuWindow::getP2Name()
{
    QString p2Name = name_P2->text();
}
