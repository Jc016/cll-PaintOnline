#include "paintonlineclient.h"
#include "ui_paintonlineclient.h"

PaintOnlineClient::PaintOnlineClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PaintOnlineClient)
{
    ui->setupUi(this);
    m_ZoneDessin = new ZoneDessin(ui->gvZoneDessin->viewport());
    connect(this,SIGNAL(GrosseurEnvoie(int)),m_ZoneDessin,SLOT(GrosseurRecue(int)));



}


PaintOnlineClient::~PaintOnlineClient()
{
    delete ui;
}



void PaintOnlineClient::on_sbGrosseur_valueChanged(int i )
{
    emit GrosseurEnvoie(i);
}


void PaintOnlineClient::on_pbCouleurPinceau_clicked()
{
    QColorDialog * cd = new QColorDialog();
    cd->show();
}


