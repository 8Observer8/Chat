#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

namespace Ui {
    class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = 0);
    ~ConnectDialog();

signals:
    void signalConnect( const QString &hostName,
                        const int portNumber );

private slots:
    void on_connectButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ConnectDialog *ui;
};

#endif // CONNECTDIALOG_H
