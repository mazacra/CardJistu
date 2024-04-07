#include "menuWindow.h"

menuWindow::menuWindow(QWidget* parent = nullptr) : QWidget(parent)
{
    this->setFixedSize(820, 700);

    //Background color
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(240, 230, 140).rgba());
    setAutoFillBackground(true);
    setPalette(pal);

    //Init gridLayout
    mainLayout = new QGridLayout(this);

    initImg();
    initButtons();

    //Ajout au gridLayout
    mainLayout->addWidget(label_Title, 0, 0, Qt::AlignTop);
    mainLayout->addWidget(button_P1, 1, 0, Qt::AlignLeft);
    mainLayout->addWidget(button_P2, 3, 0, Qt::AlignLeft);
    mainLayout->addWidget(button_Info, 7, 0, Qt::AlignLeft);
}

menuWindow::~menuWindow()
{
}

void menuWindow::initButtons()
{
    initAction();

    button_P1 = new QPushButton(tr("1 Joueur"));
    button_P1->setFixedSize(200, 75);
    button_P1->addAction(action_btnP1);
    button_P2 = new QPushButton(tr("2 Joueurs"));
    button_P2->setFixedSize(200, 75);
    button_P2->addAction(action_btnP2);
    button_Info = new QPushButton(tr("Informations"));
    button_Info->setFixedSize(200, 75);
    button_Info->addAction(action_btnInfo);
}

void menuWindow::initImg()
{
    label_Title = new QLabel();
    label_Title->setPixmap(QPixmap("../../img/title.png"));
    label_Title->setScaledContents(true);
    label_Title->setFixedSize(500, 250);
}

void menuWindow::initAction()
{
    action_btnP1 = new QAction();
    connect(action_btnP1, &QAction::triggered, this, &menuWindow::showP1_Options);

    action_btnP2 = new QAction();
    connect(action_btnP2, &QAction::triggered, this, &menuWindow::showP2_Options);

    action_btnInfo = new QAction();
    connect(action_btnInfo, &QAction::triggered, this, &menuWindow::show_Info);
}

void menuWindow::showP1_Options()
{
}

void menuWindow::showP2_Options()
{
}

void menuWindow::show_Info()
{
}
