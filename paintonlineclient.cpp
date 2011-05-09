#include "paintonlineclient.h"
#include "ui_paintonlineclient.h"

PaintOnlineClient::PaintOnlineClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PaintOnlineClient)
{
    ui->setupUi(this);
    m_ZoneDessin = new ZoneDessin(ui->gvZoneDessin->viewport());
    connect(this,SIGNAL(GrosseurEnvoie(int)),m_ZoneDessin,SLOT(GrosseurRecue(int)));
    connect(this,SIGNAL(CouleurEnvoie(QColor)),m_ZoneDessin,SLOT(CouleurRecu(QColor)));



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
    QString * s =  new QString();
    QColor c;
    QColorDialog * cd = new QColorDialog();
    cd->show();
    if(cd->result() || !cd->result())
    {
        cd->close();
    }
    c = cd->getColor();
    *s = s->sprintf("*{ background-color: rgb(%d,%d,%d)}",c.red(),c.green(),c.blue());
    ui->pbCouleurPinceau->setStyleSheet(*s);
    emit CouleurEnvoie(c);

}



