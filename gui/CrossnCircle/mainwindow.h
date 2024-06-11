#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_B1_clicked();
    void on_B2_clicked();
    void on_B3_clicked();
    void on_B4_clicked();
    void on_B5_clicked();
    void on_B6_clicked();
    void on_B7_clicked();
    void on_B8_clicked();
    void on_B9_clicked();
    void StartAI();
    void on_Restart_clicked();

private:
    void computerMove();
    bool checkGameResult();
    bool checkWin(QChar player);
    bool checkWinMove(QChar player, int &move);
    bool isBoardFull();
    void resetBoard();
    void handlePlayerMove(QPushButton* button);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
