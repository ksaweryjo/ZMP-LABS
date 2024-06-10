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

void MainWindow::on_B1_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B1->setText("X");
        ui->B1->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}
void MainWindow::on_B2_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B2->setText("X");
        ui->B2->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}
void MainWindow::on_B3_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B3->setText("X");
        ui->B3->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}
void MainWindow::on_B4_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B4->setText("X");
        ui->B4->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}
void MainWindow::on_B5_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B5->setText("X");
        ui->B5->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}
void MainWindow::on_B6_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B6->setText("X");
        ui->B6->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}
void MainWindow::on_B7_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B7->setText("X");
        ui->B7->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}
void MainWindow::on_B8_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B8->setText("X");
        ui->B8->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}
void MainWindow::on_B9_clicked()
{
    if (MainMenu::Playerf == true)
    {
        ui->B9->setText("X");
        ui->B9->setEnabled(false);
        // Check for game result
        checkGameResult();
        // Switch turn to computer

        // Let computer play
        computerMove();
        // Check for game result again after computer's move
        checkGameResult();
    }
}


void MainWindow::on_StartAI_clicked()
{
    if (MainMenu::Computerf == true)
    {
        ui->B5->setText("O");
        ui->B5->setEnabled(false);
        MainMenu::Playerf = true;
        MainMenu::Computerf = false;
    }
}


void MainWindow::checkGameResult()
{
    // Check rows
    if ((ui->B1->text() == "X" && ui->B2->text() == "X" && ui->B3->text() == "X") ||
        (ui->B4->text() == "X" && ui->B5->text() == "X" && ui->B6->text() == "X") ||
        (ui->B7->text() == "X" && ui->B9->text() == "X" && ui->B8->text() == "X"))
    {
        // Player wins
        qDebug() << "Player wins!";
    }
    // Check columns
    else if ((ui->B1->text() == "X" && ui->B4->text() == "X" && ui->B7->text() == "X") ||
             (ui->B2->text() == "X" && ui->B5->text() == "X" && ui->B9->text() == "X") ||
             (ui->B3->text() == "X" && ui->B6->text() == "X" && ui->B8->text() == "X"))
    {
        // Player wins
        qDebug() << "Player wins!";
    }
    // Check diagonals
    else if ((ui->B1->text() == "X" && ui->B5->text() == "X" && ui->B8->text() == "X") ||
             (ui->B3->text() == "X" && ui->B5->text() == "X" && ui->B7->text() == "X"))
    {
        // Player wins
        qDebug() << "Player wins!";
    }
    // Check for a draw
    else
    {
        qDebug() << "No winner yet.";
    }
}

void MainWindow::computerMove()
{
    // Implement the computer's move here using an AI algorithm
    // You can use the minimax algorithm with or without alpha-beta pruning
    // Here, let's just choose a random empty cell for the computer's move
    QList<QPushButton*> emptyCells;
    if (ui->B1->text().isEmpty()) emptyCells.append(ui->B1);
    if (ui->B8->text().isEmpty()) emptyCells.append(ui->B8);
    if (ui->B9->text().isEmpty()) emptyCells.append(ui->B9);
    if (ui->B7->text().isEmpty()) emptyCells.append(ui->B7);
    if (ui->B6->text().isEmpty()) emptyCells.append(ui->B6);
    if (ui->B5->text().isEmpty()) emptyCells.append(ui->B5);
    if (ui->B4->text().isEmpty()) emptyCells.append(ui->B4);
    if (ui->B3->text().isEmpty()) emptyCells.append(ui->B3);
    if (ui->B2->text().isEmpty()) emptyCells.append(ui->B2);
    // Add other buttons similarly
    if (!emptyCells.isEmpty()) {
        QPushButton* button = emptyCells[QRandomGenerator::global()->bounded(emptyCells.size())];
        button->setText("O"); // Assuming computer uses "O"
        button->setEnabled(false);

    }
}

