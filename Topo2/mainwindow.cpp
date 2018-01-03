#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "graphwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GraphWidget *widget = new GraphWidget;
    //set layout
    ui->gridLayout->addWidget(widget,0,1);
    ui->gridLayout->setColumnStretch(1,12);
}

MainWindow::~MainWindow()
{
    delete ui;
}
