/********************************************************************************
** Form generated from reading UI file 'nodesetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODESETDIALOG_H
#define UI_NODESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NodeSetDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_ip;
    QLabel *label_mask;
    QLineEdit *lineEdit_ip_1;
    QLabel *label_number;
    QLabel *label_protocol;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QLabel *label_ip_2;
    QLineEdit *lineEdit_ip_2;
    QLabel *label_ip_3;
    QLineEdit *lineEdit_ip_3;
    QLabel *label_ip_4;
    QLineEdit *lineEdit_ip_4;
    QLineEdit *lineEdit_mask_1;
    QLineEdit *lineEdit_mask_3;
    QLabel *label_ip_5;
    QLabel *label_ip_6;
    QLineEdit *lineEdit_mask_4;
    QLineEdit *lineEdit_mask_2;
    QLabel *label_ip_7;

    void setupUi(QDialog *NodeSetDialog)
    {
        if (NodeSetDialog->objectName().isEmpty())
            NodeSetDialog->setObjectName(QStringLiteral("NodeSetDialog"));
        NodeSetDialog->resize(349, 243);
        buttonBox = new QDialogButtonBox(NodeSetDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(180, 200, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_ip = new QLabel(NodeSetDialog);
        label_ip->setObjectName(QStringLiteral("label_ip"));
        label_ip->setGeometry(QRect(60, 120, 31, 21));
        label_mask = new QLabel(NodeSetDialog);
        label_mask->setObjectName(QStringLiteral("label_mask"));
        label_mask->setGeometry(QRect(60, 160, 61, 21));
        lineEdit_ip_1 = new QLineEdit(NodeSetDialog);
        lineEdit_ip_1->setObjectName(QStringLiteral("lineEdit_ip_1"));
        lineEdit_ip_1->setGeometry(QRect(100, 120, 31, 20));
        label_number = new QLabel(NodeSetDialog);
        label_number->setObjectName(QStringLiteral("label_number"));
        label_number->setGeometry(QRect(60, 40, 51, 21));
        label_protocol = new QLabel(NodeSetDialog);
        label_protocol->setObjectName(QStringLiteral("label_protocol"));
        label_protocol->setGeometry(QRect(60, 80, 61, 21));
        comboBox = new QComboBox(NodeSetDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 80, 69, 22));
        spinBox = new QSpinBox(NodeSetDialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(140, 40, 42, 22));
        label_ip_2 = new QLabel(NodeSetDialog);
        label_ip_2->setObjectName(QStringLiteral("label_ip_2"));
        label_ip_2->setGeometry(QRect(130, 120, 16, 21));
        QFont font;
        font.setPointSize(20);
        label_ip_2->setFont(font);
        lineEdit_ip_2 = new QLineEdit(NodeSetDialog);
        lineEdit_ip_2->setObjectName(QStringLiteral("lineEdit_ip_2"));
        lineEdit_ip_2->setGeometry(QRect(140, 120, 31, 20));
        label_ip_3 = new QLabel(NodeSetDialog);
        label_ip_3->setObjectName(QStringLiteral("label_ip_3"));
        label_ip_3->setGeometry(QRect(170, 120, 16, 21));
        label_ip_3->setFont(font);
        lineEdit_ip_3 = new QLineEdit(NodeSetDialog);
        lineEdit_ip_3->setObjectName(QStringLiteral("lineEdit_ip_3"));
        lineEdit_ip_3->setGeometry(QRect(180, 120, 31, 20));
        label_ip_4 = new QLabel(NodeSetDialog);
        label_ip_4->setObjectName(QStringLiteral("label_ip_4"));
        label_ip_4->setGeometry(QRect(210, 120, 16, 21));
        label_ip_4->setFont(font);
        lineEdit_ip_4 = new QLineEdit(NodeSetDialog);
        lineEdit_ip_4->setObjectName(QStringLiteral("lineEdit_ip_4"));
        lineEdit_ip_4->setGeometry(QRect(220, 120, 31, 20));
        lineEdit_mask_1 = new QLineEdit(NodeSetDialog);
        lineEdit_mask_1->setObjectName(QStringLiteral("lineEdit_mask_1"));
        lineEdit_mask_1->setGeometry(QRect(100, 160, 31, 20));
        lineEdit_mask_3 = new QLineEdit(NodeSetDialog);
        lineEdit_mask_3->setObjectName(QStringLiteral("lineEdit_mask_3"));
        lineEdit_mask_3->setGeometry(QRect(180, 160, 31, 20));
        label_ip_5 = new QLabel(NodeSetDialog);
        label_ip_5->setObjectName(QStringLiteral("label_ip_5"));
        label_ip_5->setGeometry(QRect(130, 160, 16, 21));
        label_ip_5->setFont(font);
        label_ip_6 = new QLabel(NodeSetDialog);
        label_ip_6->setObjectName(QStringLiteral("label_ip_6"));
        label_ip_6->setGeometry(QRect(170, 160, 16, 21));
        label_ip_6->setFont(font);
        lineEdit_mask_4 = new QLineEdit(NodeSetDialog);
        lineEdit_mask_4->setObjectName(QStringLiteral("lineEdit_mask_4"));
        lineEdit_mask_4->setGeometry(QRect(220, 160, 31, 20));
        lineEdit_mask_2 = new QLineEdit(NodeSetDialog);
        lineEdit_mask_2->setObjectName(QStringLiteral("lineEdit_mask_2"));
        lineEdit_mask_2->setGeometry(QRect(140, 160, 31, 20));
        label_ip_7 = new QLabel(NodeSetDialog);
        label_ip_7->setObjectName(QStringLiteral("label_ip_7"));
        label_ip_7->setGeometry(QRect(210, 160, 16, 21));
        label_ip_7->setFont(font);

        retranslateUi(NodeSetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NodeSetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NodeSetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NodeSetDialog);
    } // setupUi

    void retranslateUi(QDialog *NodeSetDialog)
    {
        NodeSetDialog->setWindowTitle(QApplication::translate("NodeSetDialog", "Dialog", Q_NULLPTR));
        label_ip->setText(QApplication::translate("NodeSetDialog", "IP\357\274\232", Q_NULLPTR));
        label_mask->setText(QApplication::translate("NodeSetDialog", "Mask\357\274\232", Q_NULLPTR));
        lineEdit_ip_1->setText(QString());
        label_number->setText(QApplication::translate("NodeSetDialog", "Number\357\274\232", Q_NULLPTR));
        label_protocol->setText(QApplication::translate("NodeSetDialog", "Protocol\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("NodeSetDialog", "dynamic", Q_NULLPTR)
         << QApplication::translate("NodeSetDialog", "static", Q_NULLPTR)
        );
        label_ip_2->setText(QApplication::translate("NodeSetDialog", ".", Q_NULLPTR));
        lineEdit_ip_2->setText(QString());
        label_ip_3->setText(QApplication::translate("NodeSetDialog", ".", Q_NULLPTR));
        lineEdit_ip_3->setText(QString());
        label_ip_4->setText(QApplication::translate("NodeSetDialog", ".", Q_NULLPTR));
        lineEdit_ip_4->setText(QString());
        lineEdit_mask_1->setText(QString());
        lineEdit_mask_3->setText(QString());
        label_ip_5->setText(QApplication::translate("NodeSetDialog", ".", Q_NULLPTR));
        label_ip_6->setText(QApplication::translate("NodeSetDialog", ".", Q_NULLPTR));
        lineEdit_mask_4->setText(QString());
        lineEdit_mask_2->setText(QString());
        label_ip_7->setText(QApplication::translate("NodeSetDialog", ".", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NodeSetDialog: public Ui_NodeSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODESETDIALOG_H
