#include "lframedatainit.h"

LFrameDataInit::LFrameDataInit(QObject *parent){}

QStandardItemModel *LFrameDataInit::modelInit(QVariantMap &res)
{
    QStandardItemModel *model = new QStandardItemModel;

    // 获取模型的根节点
    QStandardItem *rootNode = model->invisibleRootItem();

    // 创建并添加地区为节点，这里是“America”和“Europe”
    QStandardItem *redord = new QStandardItem("记录");
    QStandardItem *card = new QStandardItem("卡片");
    QStandardItem *friends = new QStandardItem("好友");
    rootNode->appendRow(redord);  // 将美洲节点添加到根节点
    rootNode->appendRow(friends);   // 将欧洲节点添加到根节点
    rootNode->appendRow(card);   // 将欧洲节点添加到根节点

    // 为“America”节点添加子节点
    QStandardItem *fit = new QStandardItem("健身");
    QStandardItem *canadaItem = new QStandardItem("电影");
    redord->appendRow(fit);
    redord->appendRow(canadaItem);

    QStandardItem *brest = new QStandardItem("胸部训练");
    fit->appendRow(brest);
    // 为“Europe”节点添加子节点
    QStandardItem *germanyItem = new QStandardItem("在线");
    QStandardItem *franceItem = new QStandardItem("不在线");
    friends->appendRow(germanyItem);
    friends->appendRow(franceItem);

    QStandardItem *mysql = new QStandardItem("mysql");
    QStandardItem *network = new QStandardItem("网络");
    card->appendRow(mysql);
    card->appendRow(network);

    // 设置模型的列标题，这里只有一列，标题为"Country"
    model->setHorizontalHeaderLabels(QStringList() << "Country" << "Description");
    return model;

}

LFrameDataInit& LFrameDataInit::getInstance(){
    static LFrameDataInit _instance;
    return _instance;
}
