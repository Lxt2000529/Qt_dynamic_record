#include "recordgrid.h"

#include <RecordContent.h>
#include <RecordGridTitle.h>
#include <qlabel.h>

RecordGrid::RecordGrid(QWidget *parent)
    : QWidget{parent}
{
    grid = new QGridLayout(parent);
    grid->setSpacing(0);
    grid->setContentsMargins(10, 10, 10, 10);
    grid->setVerticalSpacing(10);
    grid->setColumnStretch(4, 2);
    grid->setSpacing(0);    // 第三列的拉伸系数设为1
    setQuestion(grid);
    setContent(grid);

}
void RecordGrid::setQuestion(QGridLayout * grid){
    RecordGridTitle *title = new RecordGridTitle;
    title->getQuestion(1,1);
    QVariantMap res = title->getResultMap();

    connect(title,&RecordGridTitle::questionAlready,this,[=]{
        QVector<QString> question = title->getQuestionList();
        QFrame *frame = new QFrame();
        frame->setStyleSheet("background-color: lightblue;border: none;"); // 设置背景颜色
        frame->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
        QLabel *label = new QLabel("id");
        QVBoxLayout *frameLayout = new QVBoxLayout(frame);
        frameLayout->addWidget(label);

        grid->addWidget(frame,0,0);
        for(int i=0;i<question.length();++i){
            frame = new QFrame();
            frame->setStyleSheet("background-color: lightblue;border: none;"); // 设置背景颜色
            frame->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
            label = new QLabel(question[i]);
            frameLayout = new QVBoxLayout(frame);
            frameLayout->addWidget(label);
            grid->addWidget(frame, 0,i+1); // 将带背景的框架添加到布局
        }

        frame = new QFrame();
        frame->setStyleSheet("background-color: lightblue;border: none;"); // 设置背景颜色
        frame->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
        label = new QLabel("操作");
        frameLayout = new QVBoxLayout(frame);
        frameLayout->addWidget(label);

        grid->addWidget(frame,0,question.length()+1);
    });

}
void onQuestionListAlready(RecordGridTitle *title){


}
//设置表内容
void RecordGrid::setContent(QGridLayout * grid){
    for(int j = 0;j<40;++j){
        RecordContent *content = new RecordContent;
        for(int i = 0;i<content->vec_content.length();++i){
            grid->addWidget(new QLabel(content->vec_content[i]),j+1,i);
        }
        grid->addLayout(content->btnvlayout,j+1,content->vec_content.length());
    }


}

QGridLayout *RecordGrid::getGrid()
{
    return grid;
}
