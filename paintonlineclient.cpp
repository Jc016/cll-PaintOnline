#include "paintonlineclient.h"
#include "ui_paintonlineclient.h"

PaintOnlineClient::PaintOnlineClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PaintOnlineClient)
{
    ui->setupUi(this);


}


PaintOnlineClient::~PaintOnlineClient()
{
    delete ui;
}
