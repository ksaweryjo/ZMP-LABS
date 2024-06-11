#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)

{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_StartB_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

bool MainMenu::Playerf = true;
bool MainMenu::Computerf = false;

void MainMenu::on_PlayerB_clicked()
{
    Playerf = true;
    Computerf = false;
    ui->PlayerB->setEnabled(false);
    ui->ComputerB->setEnabled(true);
}


void MainMenu::on_ComputerB_clicked()
{
    Computerf = true;
    Playerf = false;
    ui->PlayerB->setEnabled(true);
    ui->ComputerB->setEnabled(false);
}



