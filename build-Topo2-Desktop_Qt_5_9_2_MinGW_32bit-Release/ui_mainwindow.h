/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionExit;
    QAction *actionClear_Screen;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_mode;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_arrow;
    QPushButton *pushButton_configure;
    QPushButton *pushButton_node;
    QPushButton *pushButton_line;
    QPushButton *pushButton_null;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOption;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(923, 552);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/mainflag.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionClear_Screen = new QAction(MainWindow);
        actionClear_Screen->setObjectName(QStringLiteral("actionClear_Screen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(249, 249, 247);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(7);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_mode = new QPushButton(widget);
        pushButton_mode->setObjectName(QStringLiteral("pushButton_mode"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_mode->sizePolicy().hasHeightForWidth());
        pushButton_mode->setSizePolicy(sizePolicy3);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/dynamic_32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_mode->setIcon(icon1);
        pushButton_mode->setIconSize(QSize(32, 32));
        pushButton_mode->setAutoRepeatDelay(300);
        pushButton_mode->setFlat(true);

        gridLayout_2->addWidget(pushButton_mode, 0, 0, 1, 1);

        pushButton_delete = new QPushButton(widget);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        sizePolicy3.setHeightForWidth(pushButton_delete->sizePolicy().hasHeightForWidth());
        pushButton_delete->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_delete->setIcon(icon2);
        pushButton_delete->setIconSize(QSize(32, 32));
        pushButton_delete->setFlat(true);

        gridLayout_2->addWidget(pushButton_delete, 4, 0, 1, 1);

        pushButton_arrow = new QPushButton(widget);
        pushButton_arrow->setObjectName(QStringLiteral("pushButton_arrow"));
        sizePolicy3.setHeightForWidth(pushButton_arrow->sizePolicy().hasHeightForWidth());
        pushButton_arrow->setSizePolicy(sizePolicy3);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/arrow_32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_arrow->setIcon(icon3);
        pushButton_arrow->setIconSize(QSize(32, 32));
        pushButton_arrow->setFlat(true);

        gridLayout_2->addWidget(pushButton_arrow, 5, 0, 1, 1);

        pushButton_configure = new QPushButton(widget);
        pushButton_configure->setObjectName(QStringLiteral("pushButton_configure"));
        sizePolicy3.setHeightForWidth(pushButton_configure->sizePolicy().hasHeightForWidth());
        pushButton_configure->setSizePolicy(sizePolicy3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_configure->setIcon(icon4);
        pushButton_configure->setIconSize(QSize(32, 32));
        pushButton_configure->setFlat(true);

        gridLayout_2->addWidget(pushButton_configure, 1, 0, 1, 1);

        pushButton_node = new QPushButton(widget);
        pushButton_node->setObjectName(QStringLiteral("pushButton_node"));
        sizePolicy3.setHeightForWidth(pushButton_node->sizePolicy().hasHeightForWidth());
        pushButton_node->setSizePolicy(sizePolicy3);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/node.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_node->setIcon(icon5);
        pushButton_node->setIconSize(QSize(32, 32));
        pushButton_node->setFlat(true);

        gridLayout_2->addWidget(pushButton_node, 2, 0, 1, 1);

        pushButton_line = new QPushButton(widget);
        pushButton_line->setObjectName(QStringLiteral("pushButton_line"));
        sizePolicy3.setHeightForWidth(pushButton_line->sizePolicy().hasHeightForWidth());
        pushButton_line->setSizePolicy(sizePolicy3);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_line->setIcon(icon6);
        pushButton_line->setIconSize(QSize(32, 32));
        pushButton_line->setFlat(true);

        gridLayout_2->addWidget(pushButton_line, 3, 0, 1, 1);

        pushButton_null = new QPushButton(widget);
        pushButton_null->setObjectName(QStringLiteral("pushButton_null"));
        sizePolicy3.setHeightForWidth(pushButton_null->sizePolicy().hasHeightForWidth());
        pushButton_null->setSizePolicy(sizePolicy3);
        pushButton_null->setIconSize(QSize(32, 32));
        pushButton_null->setFlat(true);

        gridLayout_2->addWidget(pushButton_null, 6, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setRowStretch(3, 1);
        gridLayout_2->setRowStretch(4, 1);
        gridLayout_2->setRowStretch(5, 1);
        gridLayout_2->setRowStretch(6, 5);

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 923, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 127, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 170, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        menuBar->setPalette(palette);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionExit);
        menuOption->addAction(actionClear_Screen);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Topo", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionClear_Screen->setText(QApplication::translate("MainWindow", "Clear Screen", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_mode->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#5500ff;\">\350\267\257\347\224\261\346\250\241\345\274\217</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_mode->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_delete->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#5500ff;\">\345\210\240\351\231\244\351\241\271\347\233\256</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_delete->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_arrow->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#5500ff;\">\347\247\273\345\212\250\350\212\202\347\202\271</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_arrow->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_configure->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#5500ff;\">\350\267\257\347\224\261\351\205\215\347\275\256</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_configure->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_node->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#5500ff;\">\350\212\202\347\202\271\350\256\276\347\275\256</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_node->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_line->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#5500ff;\">\351\223\276\350\267\257\350\256\276\347\275\256</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_line->setText(QString());
        pushButton_null->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuOption->setTitle(QApplication::translate("MainWindow", "Option", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
