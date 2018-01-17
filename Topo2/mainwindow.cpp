#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"
#include "nodesetdialog.h"

#include <QMessageBox>
#include <QAxWidget>
#include <QGraphicsScene>

#include "graphwidget.h"
#include "globaldefs.h"
#include "edge.h"

int buttonFlag = CLICK_ARROW_BUTTON;

extern NManager nodeInfoManager;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_node, &QPushButton::clicked,this,&MainWindow::pushButtonNodeSlot);
    QObject::connect(ui->pushButton_line, &QPushButton::clicked,this,&MainWindow::pushButtonLineSlot);
    QObject::connect(ui->pushButton_delete, &QPushButton::clicked,this,&MainWindow::pushButtonDeleteSlot);
    QObject::connect(ui->pushButton_configure, &QPushButton::clicked,this,&MainWindow::pushButtonConfigureSlot);
    QObject::connect(ui->pushButton_arrow, &QPushButton::clicked,this,&MainWindow::pushButtonArrowSlot);
    QObject::connect(ui->pushButton_mode, &QPushButton::clicked,this,&MainWindow::pushButtonModeSlot);

    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionSignal_Active, SIGNAL(triggered()), this, SLOT(signalActiveSlot()));
    connect(ui->actionClear_Screen, SIGNAL(triggered()), this, SLOT(clearScreenSlot()));

    GraphWidget *widget = new GraphWidget;
    //set layout
    ui->gridLayout->addWidget(widget,0,1);
    ui->gridLayout->setColumnStretch(1,12);

    signalActiveFlag = 0;
    IEwidget = NULL;
}

void MainWindow::pushButtonNodeSlot()
{
    //set cursor
    QCursor cursor;
    QPixmap pixmap;
    pixmap.load(":/images/node.png");
    cursor = QCursor(pixmap, -1, -1);
    setCursor(cursor);

    buttonFlag = CLICK_NODE_BUTTON;
}

void MainWindow::pushButtonLineSlot()
{
    //set cursor
    QCursor cursor;
    QPixmap pixmap;
    pixmap.load(":/images/line_16x16.png");
    cursor = QCursor(pixmap, -1, -1);
    setCursor(cursor);

    buttonFlag = CLICK_LINE_BUTTON;
}

void MainWindow::pushButtonDeleteSlot()
{
    //set cursor
    QCursor cursor;
    QPixmap pixmap;

    pixmap.load(":/images/delete_16x16.png");
    cursor = QCursor(pixmap, -1, -1);
    setCursor(cursor);

    buttonFlag = CLICK_DELETE_BUTTON;
}

void MainWindow::about()
//! [11] //! [12]
{
    QString str = "Mesh Network Router Configure Software.\nVersion Number: ";

    str = str + QString(gVersion) + QString("\nDeveloper: LuoMin Wenkun");


    QMessageBox::about(this, tr("About Topo"),str);
}

void MainWindow::clearScreenSlot()
{
    Node *node, *tempNode;
    Edge *edge;

    foreach (node, nodeInfoManager.nodeList) {
        foreach (edge, node->edges()) {
           node->edges().removeAll(edge);
           if(edge->destNode() == node){
              tempNode = edge->sourceNode();
              tempNode->edges().removeAll(edge);
           }else{
              tempNode = edge->destNode();
              tempNode->edges().removeAll(edge);
           }
           nodeInfoManager.g_scene->removeItem(edge);
           delete edge;
        }

        nodeInfoManager.nodeList.removeAll(node);
        nodeInfoManager.g_scene->removeItem(node);
        delete node;
    }

    nodeInfoManager.nodePool = 0;
    nodeInfoManager.ipv4addrPool = 0xa000064;
    nodeInfoManager.ipv4addrMask = 0xffffff00;
    nodeInfoManager.curNode = NULL;
    nodeInfoManager.lasterNode = NULL;
}

void MainWindow::signalActiveSlot()
{
    if(signalActiveFlag == 0){
        if(IEwidget == NULL){
            IEwidget = new QAxWidget;

            ui->gridLayout->addWidget(IEwidget,0,2);
            ui->gridLayout->setColumnStretch(2, 4);

            IEwidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}")); //设置插件为IE

            IEwidget->dynamicCall("Navigate(const QString&)", "http://192.168.8.1/cgi-bin/luci/admin/etws/lists?username=root&password=etwsadmin");

            signalActiveFlag = 1;
        }

    }else{
        ui->gridLayout->removeWidget(IEwidget);
        ui->gridLayout->setColumnStretch(0,1);
        ui->gridLayout->setColumnStretch(1,12);
        ui->gridLayout->setColumnStretch(2,0);
        delete IEwidget;
        IEwidget = NULL;
        signalActiveFlag = 0;
    }
}

void MainWindow::pushButtonConfigureSlot()
{
    //set cursor
    setCursor(QCursor(Qt::WaitCursor));

    buttonFlag = CLICK_CONFIG_BUTTON;

    calculate_route();

    QMessageBox::information(NULL, "提示", "配置路由器设备成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    setCursor(QCursor(Qt::ArrowCursor));
}

void MainWindow::pushButtonArrowSlot()
{
    //set cursor
    setCursor(QCursor(Qt::ArrowCursor));

    buttonFlag = CLICK_ARROW_BUTTON;
}

void MainWindow::pushButtonModeSlot()
{
    //set cursor
    setCursor(QCursor(Qt::ArrowCursor));

    if(DYNAMIC_MODE == nodeInfoManager.mode_flag){
        nodeInfoManager.mode_flag = STATIC_MODE;
        ui->pushButton_mode->setIcon(QIcon(":/images/mode_32x32.png"));
    }else{
        nodeInfoManager.mode_flag = DYNAMIC_MODE;
        ui->pushButton_mode->setIcon(QIcon(":/images/dynamic_32x32.png"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
