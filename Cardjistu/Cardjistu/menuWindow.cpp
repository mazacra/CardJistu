﻿#include "menuWindow.h"

menuWindow::menuWindow(QWidget* parent = nullptr) : QWidget(parent)
{
    this->setFixedSize(820, 700);

    //Background color
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(244, 242, 197).rgba());
    setAutoFillBackground(true);
    setPalette(pal);

    //Init gridLayout
    //mainLayout = new QGridLayout(this);

    initImg();
    initButtons();

    //Ajout au gridLayout
    //mainLayout->addWidget(label_Title, 0, 0);
    //mainLayout->addWidget(button_P1, 1, 0, Qt::AlignLeft);
    //mainLayout->addWidget(button_P2, 3, 0, Qt::AlignLeft);
    //mainLayout->addWidget(button_Info, 7, 0, Qt::AlignLeft);
    //mainLayout->addWidget(label_Sensei, 2, 4);
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

    button_P2 = new QPushButton(tr("2 Joueurs"), this);
    button_P2->setFixedSize(200, 75);
    button_P2->addAction(action_btnP2);
    button_P2->move(100, 425);

    button_Info = new QPushButton(tr("Informations"), this);
    button_Info->setFixedSize(200, 75);
    button_Info->addAction(action_btnInfo);
    button_Info->move(100, 575);
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
    label_Sensei->move(500, 270);
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
