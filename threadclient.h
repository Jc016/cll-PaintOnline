#ifndef THREADCLIENT_H
#define THREADCLIENT_H

#include <QThread>
#include <QWidget>
#include <QtGui>
#include <QTcpSocket>
class ThreadClient : public QThread
{
    Q_OBJECT
public:
    explicit ThreadClient(QObject *parent = 0);
    struct InfoPoint
    {
        QPoint Position;
        QColor Couleur;
        uint Grosseur;

        InfoPoint()
        {
            Couleur = Qt::black;
            Grosseur = 5;

        }

        InfoPoint(QColor c, uint g, QPoint p)
        {
            Couleur = c;
            Grosseur = g;
            Position = p;
        }



    };
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




    bool m_bEtat;

private:
    InfoPoint m_InfoPoint;
    InfoUsager m_InfoUsager;
    QTcpSocket m_SockClient;
    QByteArray m_ReceptionPixmap;
    bool m_NouveauPoint;
protected:
    void run();
signals:
    void MAJPaint (QByteArray);
    void DemanderInfoUsager();
    void AffichageMessageErreur();

public slots:
    void RecuInfoPoint(InfoPoint);
    void RecuInfoUsagerClient(InfoUsager);

};

#endif // THREADCLIENT_H
