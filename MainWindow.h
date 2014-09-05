#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include "Connection.h"
#include "Server.h"

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
    void on_actionConnect_triggered();
    void on_actionExit_triggered();
    void on_sendButton_clicked();
    void keyPressEvent( QKeyEvent *event );
    void slotConnect( const QString &hostName,
                      const int portNumber );
    void slotShowError( const QString &errorText );
    void slotReceivedData( const QString &text );
    void slotSetStatusText( const QString &text );

private:
    Ui::MainWindow *ui;
    Connection *m_connection;
    Server *m_server;
    QLabel *m_statusLabel;
};

#endif // MAINWINDOW_H
