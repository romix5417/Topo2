#include "nodesetdialog.h"
#include "ui_nodesetdialog.h"

#include "globaldefs.h"

#include <QMessageBox>
#include <QDebug>

NodeSetDialog::NodeSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NodeSetDialog)
{
    ui->setupUi(this);
}

quint32 NodeSetDialog::get_spinbox_value()
{
    return ui->spinBox->value();
}

void NodeSetDialog::set_spinbox_value(quint32 i)
{
    ui->spinBox->setValue(i);
}

quint32 NodeSetDialog::get_ipv4addr()
{
    int error = 0;

    QString ip_32 = ui->lineEdit_ip_1->text();
    QString ip_24 = ui->lineEdit_ip_2->text();
    QString ip_16 = ui->lineEdit_ip_3->text();
    QString ip_8  = ui->lineEdit_ip_4->text();

    quint32 uint_ip32, uint_ip24, uint_ip16, uint_ip8, ipv4addr;

    if(ip_32.isEmpty())
        error = 1;

    if(ip_24.isEmpty())
        error = 1;

    if(ip_16.isEmpty())
        error = 1;

    if(ip_8.isEmpty())
        error = 1;

    uint_ip32 = ip_32.toInt();
    uint_ip24 = ip_24.toInt();
    uint_ip16 = ip_16.toInt();
    uint_ip8 = ip_8.toInt();

    if(uint_ip32 > 255 || uint_ip32 == 0){
        error = 1;
    }

    if(uint_ip24 > 255){
        error = 1;
    }

    if(uint_ip16 > 255){
        error = 1;
    }

    if(uint_ip8 > 255 || uint_ip8 == 0){
        error = 1;
    }

    if(error == 1){
        QMessageBox::information(NULL, "Error", "IP地址设置错误！");
        return error;
    }

    ipv4addr = (uint_ip32 << 24) | (uint_ip24 << 16) | (uint_ip16 << 8) | (uint_ip8);

    return ipv4addr;
}

quint32 NodeSetDialog::get_ipv4mask()
{
    return 0;
}


void NodeSetDialog::set_ipv4addr(quint32 ipv4addr)
{
    quint32 uint_ip32, uint_ip24, uint_ip16, uint_ip8;

    uint_ip32 = ipv4addr >> 24;
    uint_ip24 = (ipv4addr&0x00ff0000) >> 16;
    uint_ip16 = (ipv4addr&0x0000ff00) >> 8;
    uint_ip8 = (ipv4addr&0x000000ff);

    ui->lineEdit_ip_1->setText(QString::number(uint_ip32));
    ui->lineEdit_ip_2->setText(QString::number(uint_ip24));
    ui->lineEdit_ip_3->setText(QString::number(uint_ip16));
    ui->lineEdit_ip_4->setText(QString::number(uint_ip8));
}

void NodeSetDialog::set_ipv4mask(quint32 ipv4mask)
{
    quint32 mask;
    quint32 uint_mask32, uint_mask24, uint_mask16, uint_mask8;

    qDebug()<<"ipv4mask:"<<ipv4mask<<endl;

    mask = 0xffffffff << (32 - ipv4mask);

    uint_mask32 = mask >> 24;
    uint_mask24 = (mask &0x00ff0000) >> 16;
    uint_mask16 = (mask &0x0000ff00) >> 8;
    uint_mask8 = (mask &0x000000ff);

    ui->lineEdit_mask_1->setText(QString::number(uint_mask32));
    ui->lineEdit_mask_2->setText(QString::number(uint_mask24));
    ui->lineEdit_mask_3->setText(QString::number(uint_mask16));
    ui->lineEdit_mask_4->setText(QString::number(uint_mask8));

    return;
}

QString NodeSetDialog::get_protocol()
{
    QString temp;

    return temp;
}

void set_protocal(QString protocol);

NodeSetDialog::~NodeSetDialog()
{
    delete ui;
}
