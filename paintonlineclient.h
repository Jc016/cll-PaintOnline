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
protected:


private:
    Ui::PaintOnlineClient *ui;
    ZoneDessin*   m_ZoneDessin;

signals:
   void GrosseurEnvoie(int);
   void CouleurEnvoie(QColor);


private slots:


private slots:
    void on_pbCouleurPinceau_clicked();
    void on_sbGrosseur_valueChanged(int );

};

#endif // PAINTONLINECLIENT_H
