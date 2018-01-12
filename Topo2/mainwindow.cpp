#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"

#include "graphwidget.h"
#include "globaldefs.h"

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

    GraphWidget *widget = new GraphWidget;
    //set layout
    ui->gridLayout->addWidget(widget,0,1);
    ui->gridLayout->setColumnStretch(1,12);
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

void MainWindow::pushButtonConfigureSlot()
{
    //set cursor
    setCursor(QCursor(Qt::WaitCursor));

    buttonFlag = CLICK_CONFIG_BUTTON;

    calculate_route();

    httpRequest();
}

void MainWindow::pushButtonArrowSlot()
{
    //set cursor
    setCursor(QCursor(Qt::ArrowCursor));

    buttonFlag = CLICK_ARROW_BUTTON;
}

MainWindow::~MainWindow()
{
    delete ui;
}
