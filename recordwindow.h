#ifndef RECORDWINDOW_H
#define RECORDWINDOW_H

#include <QObject>
#include <QFrame>
#include <QPushButton>
#include<QGridLayout>>
class RecordWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RecordWindow(QWidget *parent = nullptr);
private:
    QFrame *topFrame;
    QPushButton *addNewRecord_bt;
    QPushButton *defaultQuestion_bt;
    QPushButton *addQuestion_bt;
signals:
private slots:
    void onAddRecordClicked();
    void onDefaultQuestioClicked();
    void onAddQuestionClicked();

};

#endif // RECORDWINDOW_H
