#include <QApplication>
#include "mainmenu.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainMenu mainMenu;
    mainMenu.show();

    return a.exec();
}
