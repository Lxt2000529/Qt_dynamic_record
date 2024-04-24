#ifndef RECORDGRIDTITLE_H
#define RECORDGRIDTITLE_H
#include "networkmanager.h"
#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
class RecordGridTitle : public QWidget
{
    Q_OBJECT
public:
    explicit RecordGridTitle(QWidget *parent = nullptr);
    void getQuestion(int userid,int recordid);
    QVariantMap &getResultMap();
    QVector<QString> &getQuestionList();
private:
    QVector<QString> _vec_question;
    QVariantMap _resultMap;
signals:
    void questionAlready();
private slots:
    void getMsg();
};

#endif // RECORDGRIDTITLE_H
