#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onLoginButtonClicked();
    void onRegistButtonClicked();


private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *registButton;
    QPixmap backgroundImage;
private slots:
    void showLogin();
    void getLoginMsg();
};

#endif // LOGINWINDOW_H
