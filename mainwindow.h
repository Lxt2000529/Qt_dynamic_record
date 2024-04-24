#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"LoginWindow.h"
#include <QWidget>
#include"recordwindow.h"
#include<QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QLabel>
#include<QIcon>
#include<QPushButton>
#include <QVBoxLayout>
#include <qsplitter.h>
#include <QStandardItemModel>
#include <QItemSelection>
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(LoginWindow *login,QVariantMap &resourse,QWidget *parent = nullptr);

private:
    QLabel *welcomeLabel;
    QVariantMap _resmap;
    QFrame *frame;
    QLabel *userName;
    QPushButton *exitbutton;
    QSplitter *splitter;
    QFrame *Lframe;
    QFrame *Rframe;
    LoginWindow *_login;
private slots:
    void ExitLogin();
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
};

#endif // MAINWINDOW_H
