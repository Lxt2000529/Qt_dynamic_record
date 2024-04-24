#include "recordwindow.h"
#include"recordgrid.h"
#include "networkmanager.h"
#include"publishMsg.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QJsonObject>
#include <QJsonDocument>
#include <unordered_map>


RecordWindow::RecordWindow(QWidget *parent)
    : QWidget{parent}
{

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->setContentsMargins(0,0,0,0);
//================================actionBar====================================================
    topFrame = new QFrame;
    topFrame->setFrameShape(QFrame::StyledPanel); // 设置框架样式为面板
    topFrame->setFrameShadow(QFrame::Raised); // 设置框架阴影为凸起
    topFrame->setLineWidth(10); // 设置框架边框宽度
    topFrame->setStyleSheet("QFrame {background-color: #cb80ff; }"); // 单独设置QFrame的样式

    addNewRecord_bt = new QPushButton("添加记录");
    defaultQuestion_bt = new QPushButton("默认问题");
    addQuestion_bt = new QPushButton("添加问题");


    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(addNewRecord_bt);
    hlayout->addWidget(defaultQuestion_bt);
    hlayout->addWidget(addQuestion_bt);
    hlayout->addStretch();
    topFrame->setLayout(hlayout);
//======================================Grid=====================================================

    QWidget *container = new QWidget(this);
    RecordGrid *rgrid = new RecordGrid(container);
    container->setLayout(rgrid->getGrid());
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidget(container);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidgetResizable(true); // 允许表格调整大小以填满滚动区域
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    scrollArea->setFixedHeight(860);
    // scrollArea->setSizeAdjustPolicy(QScrollArea::AdjustToContents);
    vlayout->addWidget(topFrame);

    vlayout->addWidget(scrollArea,1);

    connect(addNewRecord_bt, &QPushButton::clicked, this, &RecordWindow::onAddRecordClicked);
    connect(defaultQuestion_bt, &QPushButton::clicked, this, &RecordWindow::onDefaultQuestioClicked);
    connect(addQuestion_bt, &QPushButton::clicked, this, &RecordWindow::onAddQuestionClicked);
}
//设置表头数据

void RecordWindow::onAddRecordClicked()
{
    //1.弹出对话框
    //2.将对话框中的数据发送给服务端
    QTcpSocket *tcpsocket = NetworkManager::instance().getSocket();
    QJsonObject json;
    json["msgid"] =EnMsgType::ADD_RECORD_MSG;
    json["id"] = 1;
    json["recordid"] = 1;
    json["dataid"] = 1;
    // 手动将QHash转换为QJsonObject
    QJsonObject qanda;
    QHash<QString,QString> hash;
    hash.insert("first_q", "first_a");
    hash.insert("second_q", "second_a");
    hash.insert("third_q", "third_a");
    for (auto it = hash.constBegin(); it != hash.constEnd(); ++it) {
        qanda[it.key()] = it.value();
    }

    json["qanda"] = qanda;

    QJsonDocument doc(json);
    QString jsonString = doc.toJson(QJsonDocument::Compact);
    tcpsocket->write(jsonString.toStdString().c_str());
}

void RecordWindow::onDefaultQuestioClicked()
{

}

void RecordWindow::onAddQuestionClicked()
{

}
