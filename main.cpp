#include "LoginWindow.h"
#include <QApplication>
#include <QGridLayout>
#include <QTableWidget>
#include <qlabel.h>
#include <QScrollArea>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginWindow loginWindow;
    loginWindow.show();
    return app.exec();
}
