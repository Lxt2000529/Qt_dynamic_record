#ifndef LFRAMEDATAINIT_H
#define LFRAMEDATAINIT_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QStandardItem>
class LFrameDataInit : public QObject
{
    Q_OBJECT
public:
    static LFrameDataInit& getInstance();
    QStandardItemModel * modelInit(QVariantMap &resourse);
private:
    explicit LFrameDataInit(QObject *parent = nullptr);

private:
    QVariantMap _res;
    QStandardItemModel *_model;
signals:
};

#endif // LFRAMEDATAINIT_H
