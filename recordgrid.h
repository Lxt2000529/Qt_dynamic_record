#ifndef RECORDGRID_H
#define RECORDGRID_H

#include "qgridlayout.h"
#include <QWidget>

class RecordGrid : public QWidget
{
    Q_OBJECT
public:
    explicit RecordGrid(QWidget *parent = nullptr);
    void setQuestion(QGridLayout * grid);
    void setContent(QGridLayout * grid);
    QGridLayout * getGrid();
private:
    QGridLayout *grid;
signals:
};

#endif // RECORDGRID_H
