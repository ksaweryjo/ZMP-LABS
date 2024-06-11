#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"
#include <QDebug>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    StartAI();
}

void MainWindow::StartAI()
{
    if (MainMenu::Computerf)
    {
        computerMove();
        MainMenu::Playerf = true;
    }
}

void MainWindow::on_Restart_clicked()
{
    resetBoard();
    if (MainMenu::Computerf)
    {
        computerMove();
    }
}

void MainWindow::resetBoard()
{
    QPushButton* buttons[9] = {ui->B1, ui->B2, ui->B3, ui->B4, ui->B5, ui->B6, ui->B7, ui->B8, ui->B9};
    for (QPushButton* button : buttons) {
        button->setText("");
        button->setEnabled(true);
    }
    ui->Winner->setText("");
}

void MainWindow::on_B1_clicked() { handlePlayerMove(ui->B1); }
void MainWindow::on_B2_clicked() { handlePlayerMove(ui->B2); }
void MainWindow::on_B3_clicked() { handlePlayerMove(ui->B3); }
void MainWindow::on_B4_clicked() { handlePlayerMove(ui->B4); }
void MainWindow::on_B5_clicked() { handlePlayerMove(ui->B5); }
void MainWindow::on_B6_clicked() { handlePlayerMove(ui->B6); }
void MainWindow::on_B7_clicked() { handlePlayerMove(ui->B7); }
void MainWindow::on_B8_clicked() { handlePlayerMove(ui->B8); }
void MainWindow::on_B9_clicked() { handlePlayerMove(ui->B9); }

void MainWindow::handlePlayerMove(QPushButton* button)
{
    if (MainMenu::Playerf && !checkGameResult() && button->text().isEmpty())
    {
        button->setText("x");
        button->setEnabled(false);
        if (!checkGameResult())
        {
            computerMove();
            checkGameResult();
        }
    }
}

void MainWindow::computerMove()
{
    int move = -1;

    if (checkWinMove('o', move)) {
        QPushButton* button = findChild<QPushButton*>(QString("B%1").arg(move + 1));
        if (button) {
            button->setText("o");
            button->setEnabled(false);
            return;
        }
    }

    if (checkWinMove('x', move)) {
        QPushButton* button = findChild<QPushButton*>(QString("B%1").arg(move + 1));
        if (button) {
            button->setText("o");
            button->setEnabled(false);
            return;
        }
    }

    if (ui->B5->text().isEmpty()) {
        ui->B5->setText("o");
        ui->B5->setEnabled(false);
        return;
    }

    int corners[] = {0, 2, 6, 8};
    for (int i = 0; i < 4; ++i) {
        QPushButton* button = findChild<QPushButton*>(QString("B%1").arg(corners[i] + 1));
        if (button && button->text().isEmpty()) {
            button->setText("o");
            button->setEnabled(false);
            return;
        }
    }

    for (int i = 0; i < 9; ++i) {
        QPushButton* button = findChild<QPushButton*>(QString("B%1").arg(i + 1));
        if (button && button->text().isEmpty()) {
            button->setText("o");
            button->setEnabled(false);
            return;
        }
    }
}

bool MainWindow::checkWin(QChar player)
{
    const int winCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; ++i) {
        if (findChild<QPushButton*>(QString("B%1").arg(winCombinations[i][0] + 1))->text() == player &&
            findChild<QPushButton*>(QString("B%1").arg(winCombinations[i][1] + 1))->text() == player &&
            findChild<QPushButton*>(QString("B%1").arg(winCombinations[i][2] + 1))->text() == player) {
            return true;
        }
    }
    return false;
}

bool MainWindow::checkWinMove(QChar player, int &move)
{
    for (int i = 0; i < 9; ++i) {
        QPushButton* button = findChild<QPushButton*>(QString("B%1").arg(i + 1));
        if (button && button->text().isEmpty()) {
            button->setText(player);
            if (checkWin(player)) {
                button->setText("");
                move = i;
                return true;
            }
            button->setText("");
        }
    }
    return false;
}

bool MainWindow::checkGameResult()
{
    if (checkWin('x')) {
        ui->Winner->setText("Player Wins");
        return true;
    } else if (checkWin('o')) {
        ui->Winner->setText("AI Wins");
        return true;
    } else if (isBoardFull()) {
        ui->Winner->setText("DRAW");
        return true;
    }
    return false;
}

bool MainWindow::isBoardFull()
{
    for (int i = 0; i < 9; ++i) {
        QPushButton* button = findChild<QPushButton*>(QString("B%1").arg(i + 1));
        if (button && button->text().isEmpty()) {
            return false;
        }
    }
    return true;
}
