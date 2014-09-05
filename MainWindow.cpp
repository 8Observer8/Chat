
#include <QTime>
#include <QMessageBox>
#include <QHostInfo>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ConnectDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFocusPolicy( Qt::StrongFocus );

    m_connection = new Connection;

    m_server = new Server;
    connect( m_server, SIGNAL( signalReceivedData( QString ) ),
             this, SLOT( slotReceivedData( QString ) ) );
    connect( m_server, SIGNAL( signalError( QString ) ),
             this, SLOT( slotShowError( QString ) ) );
    connect( m_server, SIGNAL( signalStatusText( QString ) ),
             this, SLOT( slotSetStatusText( QString ) ) );

    m_statusLabel = new QLabel( this );
    ui->statusBar->addPermanentWidget( m_statusLabel );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
    ConnectDialog dialog;
    dialog.setModal( true );
    connect( &dialog, SIGNAL( signalConnect( QString, int ) ),
             this, SLOT(slotConnect( QString, int ) ) );
    dialog.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_sendButton_clicked()
{
    QString time = QTime::currentTime().toString();
    QString text = ui->inputTextEdit->toPlainText();
    QString name = QHostInfo::localHostName();
    QString message = time + " " + name + ": " + text + "\n";
    ui->outputTextEdit->append( message );

    if ( m_statusLabel->text().isEmpty() ) {
        m_connection->send( message );
    } else {
        m_server->send( message );
    }

    ui->inputTextEdit->setText( "" );
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch ( event->key() ) {
    case Qt::Key_Enter:
        on_sendButton_clicked();
        break;
    }
}

void MainWindow::slotConnect( const QString &hostName,
                              const int portNumber )
{
    m_connection->open( hostName, portNumber );
    connect( m_connection, SIGNAL( signalReceivedData( QString ) ),
             this, SLOT( slotReceivedData( QString ) ) );
    connect( m_connection, SIGNAL( signalError( QString ) ),
             this, SLOT( slotShowError( QString ) ) );
}

void MainWindow::slotShowError(const QString &errorText)
{
    QMessageBox::information( this, tr( "Error" ), errorText );
}

void MainWindow::slotReceivedData( const QString &text )
{
    ui->outputTextEdit->append( text );
}

void MainWindow::slotSetStatusText(const QString &text)
{
    m_statusLabel->setText( text );
}
