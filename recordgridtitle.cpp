#include "recordgridtitle.h"
#include"publishMsg.h"
#include "networkmanager.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <Qvector>

RecordGridTitle::RecordGridTitle(QWidget *parent)
    : QWidget{parent}
{
}

void RecordGridTitle::getQuestion(int userid, int recordid)
{
    // _vec_question = {"杠铃卧推", "杠铃上斜", "胸围"};
    // Network connection setup
    QTcpSocket *tcpsocket = NetworkManager::instance().getSocket();
    QJsonObject json;
    json["msgid"] = static_cast<int>(EnMsgType::GET_RECORD_MSG);
    json["userid"] = userid;
    json["recordid"] = recordid;
    QJsonDocument doc(json);
    QString jsonString = doc.toJson(QJsonDocument::Compact);
    tcpsocket->write(jsonString.toUtf8());

    // Connect signal for response
    connect(tcpsocket, &QTcpSocket::readyRead, this, &RecordGridTitle::getMsg);
}

void RecordGridTitle::getMsg()
{
    QTcpSocket *tcpsocket = NetworkManager::instance().getSocket();
    QByteArray responseData = tcpsocket->readAll();
    QJsonParseError jsonError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData, &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "JSON Parsing Error:" << jsonError.errorString();
        return;
    }

    _resultMap = jsonResponse.toVariant().toMap();
    qDebug() << "Received data:" << _resultMap;
    QList<QVariant> list = _resultMap["question"].toList();
    for(auto &elem:list){
        _vec_question.push_back(elem.toString());
    }
    emit questionAlready();
}

QVariantMap &RecordGridTitle::getResultMap()
{
    return _resultMap;
}

QVector<QString> &RecordGridTitle::getQuestionList()
{
    return _vec_question;
}

