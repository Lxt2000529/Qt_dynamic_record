#include "framestyledelegate.h"

FrameStyleDelegate::FrameStyleDelegate() {}

void FrameStyleDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    // 画背景为Frame风格
    QStyleOptionFrame frameOption;
    frameOption.rect = option.rect.adjusted(2, 2, -2, -2); // 略微调整尺寸以模拟边框
    frameOption.lineWidth = 2; // 设置线宽
    frameOption.midLineWidth = 0;
    frameOption.state = QStyle::State_Sunken | QStyle::State_Enabled;

    painter->save();
    painter->setBrush(QBrush(QColor("#f0f0f0"))); // 设置背景颜色
    painter->setPen(Qt::black); // 设置边框颜色
    painter->drawRect(frameOption.rect); // 绘制矩形边框
    painter->restore();

    // 绘制文本
    QRect textRect = frameOption.rect.adjusted(5, 5, -5, -5); // 文本区域需要在Frame内部
    painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, index.data().toString());
}
