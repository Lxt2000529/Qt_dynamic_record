#include "MainWindow.h"
#include "lframedatainit.h"
#include"framestyledelegate.h"
#include <QTreeView>
MainWindow::MainWindow(LoginWindow *login,QVariantMap &resourse,QWidget *parent) : QWidget(parent),_resmap(resourse),_login(login)
{
    setFixedSize(1760, 990);
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->setContentsMargins(0, 0, 0, 0);
    frame = new QFrame;
    frame->setFrameShape(QFrame::StyledPanel); // 设置框架样式为面板
    frame->setFrameShadow(QFrame::Raised); // 设置框架阴影为凸起
    frame->setLineWidth(10); // 设置框架边框宽度
    frame->setFixedSize(width(), 50);  // 设置QFrame的固定大小
    frame->setStyleSheet("QFrame {background-color: #59a5f5; }"); // 单独设置QFrame的样式

    QHBoxLayout *hfLayout = new QHBoxLayout;
    hfLayout->setContentsMargins(0, 0, 0, 0);
    //用户名显示
    userName = new QLabel(resourse["username"].toString());
    userName->setStyleSheet("QLabel { color : white; font-weight: bold; font-size: 20px; }");
    userName->setMargin(10);
    //退出图标按钮
    QIcon exitIcon(":/image/exit.png");
    exitbutton = new QPushButton;
    exitbutton->setFixedSize(50, 50); // 设置按钮的大小1   1231
    exitbutton->setIcon(exitIcon); // 设置图标
    exitbutton->setIconSize(exitbutton->size()); // 将图标大小设置为按钮大小
    exitbutton->setStyleSheet("QPushButton { border: none; }");

    hfLayout->addWidget(userName);
    hfLayout->addStretch();
    hfLayout->addWidget(exitbutton);
    frame->setLayout(hfLayout);

//==============================DownSite=============================================================
    splitter = new QSplitter(Qt::Horizontal, this);
    splitter->setHandleWidth(10); // 设置分隔器宽度
//==============================DownLeft=============================================================
    Lframe = new QFrame;
    Lframe->setFrameShape(QFrame::StyledPanel); // 设置框架样式为面板
    Lframe->setFrameShadow(QFrame::Raised); // 设置框架阴影为凸起
    Lframe->setStyleSheet("QFrame {background-color: #f5f5f5; }"); // 单独设置QFrame的样式

    QTreeView *treeView = new QTreeView;
    QStandardItemModel *model = LFrameDataInit::getInstance().modelInit(_resmap);
    treeView->setModel(model);    // 展开所有节点，以便所有项都可见
    treeView->expandAll();    // 根据内容调整第一列的宽度
    treeView->resizeColumnToContents(0);

    QVBoxLayout *vtreelayout = new QVBoxLayout;
    vtreelayout->addWidget(treeView);
    Lframe->setLayout(vtreelayout);

//==============================DownRight============================================================
    Rframe = new QFrame;
    Rframe->setFrameShape(QFrame::StyledPanel); // 设置框架样式为面板
    Rframe->setFrameShadow(QFrame::Raised); // 设置框架阴影为凸起
    Rframe->setStyleSheet("QFrame {background-color: #FFFFFF; }"); // 单独设置QFrame的样式
    Rframe->setContentsMargins(0,0,0,0);
    QVBoxLayout *RframeVlayout = new QVBoxLayout;
    RframeVlayout->setContentsMargins(0, 0, 0, 0);
    RecordWindow *recordWindow = new RecordWindow;
    RframeVlayout->addWidget(recordWindow);
    RframeVlayout->addStretch();
    Rframe->setLayout(RframeVlayout);
//==============================total================================================================
    splitter = new QSplitter;
    splitter->addWidget(Lframe);
    splitter->addWidget(Rframe);
    QList<int> sizes;
    sizes << width()*0.2 << width()*0.8; // 设置Lframe和Rframe的初始大小
    splitter->setSizes(sizes);

    vlayout->addWidget(frame);
    vlayout->addWidget(splitter);

    setWindowTitle("Main Window");
    connect(exitbutton, &QPushButton::clicked, this, &MainWindow::ExitLogin);
    connect(treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::onSelectionChanged);
}

void MainWindow::ExitLogin()
{
    //1.向服务端发送下线请求
    //2.展示登陆界面)
    _login->show();
    this->close();

}

void MainWindow::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected)
    if (!selected.indexes().isEmpty()) {
        QModelIndex index = selected.indexes().first();
        QString itemText = index.data(Qt::DisplayRole).toString();
        qDebug()<<"You have selected: " + itemText;
        // 根据选中的节点更新RFrame内容
    }
}
