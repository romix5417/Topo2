#ifndef NODESETDIALOG_H
#define NODESETDIALOG_H

#include <QDialog>

namespace Ui {
class NodeSetDialog;
}

class NodeSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NodeSetDialog(QWidget *parent = 0);

    quint32 get_spinbox_value();
    void set_spinbox_value(quint32 i);

    quint32 get_ipv4addr();
    quint32 get_ipv4mask();

    void set_ipv4addr(quint32 ipv4addr);
    void set_ipv4mask(quint32 ipv4mask);

    QString get_protocol();
    void set_protocal(QString protocol);

    ~NodeSetDialog();

private:
    Ui::NodeSetDialog *ui;
};

#endif // NODESETDIALOG_H
