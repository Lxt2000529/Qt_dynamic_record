#include "LoginWindow.h"
#include"mainwindow.h"
#include"registwindow.h"
#include"networkmanager.h"
#include"publishMsg.h"
#include<QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVBoxLayout>
#include <QLabel>


LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("登录"); // 设置窗口标题
    this->resize(1600, 900); // 设置窗口初始大小
    this->setMinimumSize(1600, 900);
    this->setMaximumSize(1600, 900);
    // 直接应用于窗口的背景图片
    backgroundImage.load("://image/Login_bac.png");
    // 创建QFrame作为登录区域的背景容器
    QFrame *frame = new QFrame();
    frame->setFrameShape(QFrame::StyledPanel); // 设置框架样式为面板
    frame->setFrameShadow(QFrame::Raised); // 设置框架阴影为凸起
    frame->setLineWidth(10); // 设置框架边框宽度
    frame->setMinimumSize(400, 300); // 设置QFrame的最小尺寸
    frame->setStyleSheet("QFrame { border-radius: 15px; background-color: #59a5f5; }"); // 单独设置QFrame的样式

    // 设置用户名的水平布局
    QHBoxLayout *userNameHLayout = new QHBoxLayout();

    QLabel *luserName = new QLabel("userName:");
    luserName->setStyleSheet("QLabel { color : white; font-weight: bold; font-size: 20px; }");
    luserName->setMargin(20);

    userNameHLayout->addStretch();
    userNameHLayout->addWidget(luserName);
    usernameLineEdit = new QLineEdit();
    usernameLineEdit->setAlignment(Qt::AlignCenter);
    usernameLineEdit->setStyleSheet("QLineEdit {border-radius: 15px}");
    usernameLineEdit->setFixedSize(300, 30);
    userNameHLayout->addWidget(usernameLineEdit);
    userNameHLayout->addStretch();

    // 设置密码的水平布局
    QHBoxLayout *pwdHLayout = new QHBoxLayout();

    QLabel *lpwd = new QLabel("passWord:");
    lpwd->setStyleSheet("QLabel { color : white; font-weight: bold; font-size: 20px; }");
    lpwd->setMargin(20);

    pwdHLayout->addStretch();
    pwdHLayout->addWidget(lpwd);
    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setAlignment(Qt::AlignCenter);
    passwordLineEdit->setStyleSheet("QLineEdit {border-radius: 15px}");
    passwordLineEdit->setFixedSize(300, 30);
    passwordLineEdit->setEchoMode(QLineEdit::Password); // 设置为密码模式，输入隐藏
    pwdHLayout->addWidget(passwordLineEdit);
    pwdHLayout->addStretch();

    // 设置登录和注册按钮的水平布局
    QHBoxLayout *btnHLayout = new QHBoxLayout();
    loginButton = new QPushButton("登录");
    loginButton->setFixedSize(200, 40);
    registButton = new QPushButton("注册");
    registButton->setFixedSize(100, 40);
    btnHLayout->addStretch();
    btnHLayout->addWidget(loginButton);
    btnHLayout->addWidget(registButton);
    btnHLayout->addStretch();

    // 添加上面的布局组成垂直
    QVBoxLayout *frameLayout = new QVBoxLayout(); // 创建垂直布局管理器
    frameLayout->addLayout(userNameHLayout);
    frameLayout->addLayout(pwdHLayout);
    frameLayout->addLayout(btnHLayout);

    // 添加登录按钮到布局

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    connect(registButton, &QPushButton::clicked, this, &LoginWindow::onRegistButtonClicked);

    frame->setLayout(frameLayout); // 将布局应用到QFrame

    // 使用水平和垂直布局来居中QFrame
    QVBoxLayout *mainLayout = new QVBoxLayout(this); // 主窗口布局为垂直布局
    QHBoxLayout *hCenterLayout = new QHBoxLayout(); // 创建水平布局管理器用于居中QFrame
    hCenterLayout->addStretch(); // 添加伸展项，用于推动QFrame居中
    hCenterLayout->addWidget(frame); // 将QFrame添加到水平布局
    hCenterLayout->addStretch(); // 添加伸展项，用于推动QFrame居中
    mainLayout->addStretch(); // 添加伸展项，用于推动QFrame居中
    mainLayout->addLayout(hCenterLayout); // 将水平布局添加到垂直布局
    mainLayout->addStretch(); // 添加伸展项，用于推动QFrame居中

    // 将主布局设置到窗口
    this->setLayout(mainLayout);
}

void LoginWindow::onLoginButtonClicked()
{
    // 简单的用户名和密码验证
    QTcpSocket *tcpsocket = NetworkManager::instance().getSocket();
    QString userName = usernameLineEdit->text();
    QString pwd = passwordLineEdit->text();

    QJsonObject json;
    json["id"] = userName.toInt();
    json["password"] = pwd;
    json["msgid"] = EnMsgType::LOGIN_MSG;
    QJsonDocument doc(json);
    QString jsonString = doc.toJson(QJsonDocument::Compact);
    tcpsocket->write(jsonString.toStdString().c_str());
    // 接收数据
    connect(tcpsocket, &QTcpSocket::readyRead, this,&LoginWindow::getLoginMsg);

}
void LoginWindow::getLoginMsg(){
    QTcpSocket *tcpsocket = NetworkManager::instance().getSocket();
    QByteArray responseData = tcpsocket->readAll();
    // 处理接收到的数据
    qDebug()<<responseData;
    // 解析 JSON 数据
    QJsonParseError jsonError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData, &jsonError);

    // 检查解析是否成功
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "JSON 解析错误:" << jsonError.errorString();
    } else {
        // 解析成功，将 JSON 对象转换为 QVariantMap
        QVariantMap resultMap = jsonResponse.toVariant().toMap();
        if(resultMap["msgid"].toInt()==EnMsgType::LOGIN_ACK){
            if(resultMap["erron"].toInt()==0){
                qDebug()<<resultMap["errno"].toInt();
                MainWindow *mainWindow = new MainWindow(this,resultMap);
                mainWindow->show();
                this->close();
            }else{
                QMessageBox::information(nullptr, "提示", resultMap["errmsg"].toString());
            }
        }

    }
    disconnect(tcpsocket, &QTcpSocket::readyRead, this, &LoginWindow::getLoginMsg);
}

void LoginWindow::onRegistButtonClicked()
{
    RegistWindow * registWindow = new RegistWindow;
    registWindow->show();
}

void LoginWindow::showLogin()
{
    this->show();
}
void LoginWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), backgroundImage);  // 使图片填充整个窗口

    QWidget::paintEvent(event);  // 调用基类的paintEvent以处理其他绘图事件
}
