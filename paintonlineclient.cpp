#include "paintonlineclient.h"
#include "ui_paintonlineclient.h"
#include "threadclient.h"

PaintOnlineClient::PaintOnlineClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PaintOnlineClient)
{
    ui->setupUi(this);
    m_ZoneDessin = new ZoneDessin(ui->gvZoneDessin->viewport());
    m_ThreadClient = new ThreadClient();
    connect(this,SIGNAL(GrosseurEnvoie(int)),m_ZoneDessin,SLOT(GrosseurRecue(int)));
    connect(this,SIGNAL(CouleurEnvoie(QColor)),m_ZoneDessin,SLOT(CouleurRecu(QColor)));
    connect(m_ThreadClient,SIGNAL(DemanderInfoUsager()),this,SLOT(DemandeInfoUsagerSlot()));
    connect(this,SIGNAL(ReponseInfoUsager(InfoUsager)),m_ThreadClient,SLOT(RecuInfoUsagerClient(InfoUsager)));
    connect(m_ThreadClient,SIGNAL(AffichageMessageErreur()),this,SLOT(ReceptionDemandeMessageBox()));
    m_InfoUsager = InfoUsager();

    ui->txtAdresse->setInputMask("000.000.000.000");



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
       delete cd;
    }
    c = cd->getColor();
    *s = s->sprintf("*{ background-color: rgb(%d,%d,%d)}",c.red(),c.green(),c.blue());
    ui->pbCouleurPinceau->setStyleSheet(*s);
    emit CouleurEnvoie(c);

}





void PaintOnlineClient::on_pbCouleurUtilisateur_clicked()
{
    QString * s =  new QString();
    QColor c;
    QColorDialog * cd = new QColorDialog();
    cd->show();
    if(cd->result() || !cd->result())
    {
       delete cd;
    }
    c = cd->getColor();
    *s = s->sprintf("*{ background-color: rgb(%d,%d,%d)}",c.red(),c.green(),c.blue());
    ui->pbCouleurUtilisateur->setStyleSheet(*s);
    m_InfoUsager.Couleur = cd->getColor();

}

void PaintOnlineClient::DemandeInfoUsagerSlot()
{
    emit ReponseInfoUsager(m_InfoUsager);
}

void PaintOnlineClient::on_clbConnecteServeur_clicked()
{
    m_InfoUsager.Nom = ui->txtNom->text();
    m_InfoUsager.Adresse = ui->txtAdresse->text();
    m_ThreadClient->start();


}
void PaintOnlineClient::ReceptionDemandeMessageBox()
{
    QMessageBox::warning(this, "fuckface", "contenu de laffaire");
}
