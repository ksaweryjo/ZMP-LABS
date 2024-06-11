#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    static bool Computerf;
    static bool Playerf;

private slots:
    void on_StartB_clicked();

    void on_PlayerB_clicked();

    void on_ComputerB_clicked();
private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
