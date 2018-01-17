#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void about();
    void clearScreenSlot();
    void signalActiveSlot();
    void pushButtonNodeSlot();
    void pushButtonLineSlot();
    void pushButtonConfigureSlot();
    void pushButtonDeleteSlot();
    void pushButtonArrowSlot();
    void pushButtonModeSlot();

private:
    Ui::MainWindow *ui;
    int signalActiveFlag;
    QAxWidget *IEwidget;
};

#endif // MAINWINDOW_H
