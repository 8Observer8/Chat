
#include <QHostInfo>
#include "ConnectDialog.h"
#include "ui_ConnectDialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    ui->hostNameLineEdit->setText( QHostInfo::localHostName() );
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::on_connectButton_clicked()
{
    QString hostName = ui->hostNameLineEdit->text();
    int portNumber = ui->portNumberSpinBox->value();
    emit signalConnect( hostName, portNumber );
    this->close();
}

void ConnectDialog::on_cancelButton_clicked()
{
    this->close();
}
