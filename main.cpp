#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //wyswietlanie okienka
    w.show();

    return a.exec();
}
