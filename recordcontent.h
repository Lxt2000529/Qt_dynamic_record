#ifndef RECORDCONTENT_H
#define RECORDCONTENT_H

#include <QWidget>
#include<QFrame>
#include <QPushButton>
#include <QVBoxLayout>

class RecordContent : public QWidget
{
    Q_OBJECT
public:
    explicit RecordContent(QWidget *parent = nullptr);
    QFrame * getContent();

public:
    QFrame *_contentframe;
    QVector<QString> vec_content;
    QPushButton *editRecord_bt;
    QPushButton *delRecord_bt;
    QHBoxLayout *btnvlayout;

signals:
};

#endif // RECORDCONTENT_H
