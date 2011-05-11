#ifndef PAINTONLINECLIENT_H
#define PAINTONLINECLIENT_H

#include <QMainWindow>
#include "zonedessin.h"


namespace Ui {
    class PaintOnlineClient;
}

class PaintOnlineClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit PaintOnlineClient(QWidget *parent = 0);
    ~PaintOnlineClient();
    struct InfoUsager
    {
        QString Nom;
        QColor Couleur;
        QString Adresse;


        InfoUsager()
        {
            Nom = "Usager";
            Couleur = Qt::blue;
            Adresse = "127.0.0.1";

        }

        InfoUsager(QString n, QColor c, QString a)
        {
            Couleur = c;
            Nom = n;
            Adresse = a;

        }



    };
protected:


private:
    Ui::PaintOnlineClient *ui;
    ZoneDessin*   m_ZoneDessin;
    ThreadClient * m_ThreadClient;
    InfoUsager m_InfoUsager;

signals:
   void GrosseurEnvoie(int);
   void CouleurEnvoie(QColor);
   void ReponseInfoUsager(InfoUsager);



private slots:


private slots:
    void on_clbConnecteServeur_clicked();
    void on_pbCouleurUtilisateur_clicked();
    void on_pbCouleurPinceau_clicked();
    void on_sbGrosseur_valueChanged(int );
    void DemandeInfoUsagerSlot();
    void ReceptionDemandeMessageBox();

};

#endif // PAINTONLINECLIENT_H
