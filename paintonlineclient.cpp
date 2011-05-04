#include "paintonlineclient.h"
#include "ui_paintonlineclient.h"

PaintOnlineClient::PaintOnlineClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PaintOnlineClient)
{
    ui->setupUi(this);
    m_ZoneDessin = new ZoneDessin(ui->gvZoneDessin->viewport());



}


PaintOnlineClient::~PaintOnlineClient()
{
    delete ui;
}
