#include "recordcontent.h"
#include "qdebug.h"

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

RecordContent::RecordContent(QWidget *parent)
    : QWidget{parent}
{

    vec_content = {"1","111","222","333"};

    editRecord_bt = new QPushButton("编辑");
    delRecord_bt = new QPushButton("删除");

    QIcon editIcon(":/image/editBtn.png");
    editRecord_bt = new QPushButton;
    editRecord_bt->setFixedSize(30, 30); // 设置按钮的大小1   1231
    editRecord_bt->setIcon(editIcon); // 设置图标
    editRecord_bt->setIconSize(editRecord_bt->size()); // 将图标大小设置为按钮大小
    editRecord_bt->setStyleSheet("QPushButton { border: none; }");

    QIcon delIcon(":/image/deleteBtn.png");
    delRecord_bt = new QPushButton;
    delRecord_bt->setFixedSize(25, 25); // 设置按钮的大小1   1231
    delRecord_bt->setIcon(delIcon); // 设置图标
    delRecord_bt->setIconSize(delRecord_bt->size()); // 将图标大小设置为按钮大小
    delRecord_bt->setStyleSheet("QPushButton { border: none; }");

    btnvlayout = new QHBoxLayout;
    btnvlayout->addWidget(editRecord_bt);
    btnvlayout->addSpacing(10);
    btnvlayout->addWidget(delRecord_bt);
}

QFrame* RecordContent::getContent()
{
    return _contentframe;
}
