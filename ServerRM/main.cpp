#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(186,48+20);
    QPixmap exi(":/icons/icons/main_i.png");
    QIcon ex(exi);
    w.setWindowIcon(ex);
    w.show();
    return a.exec();
}
