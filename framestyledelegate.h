#ifndef FRAMESTYLEDELEGATE_H
#define FRAMESTYLEDELEGATE_H
#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyle>
class FrameStyleDelegate : public QStyledItemDelegate
{
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    FrameStyleDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index);
};

#endif // FRAMESTYLEDELEGATE_H
