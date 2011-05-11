#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QWidget>
#include <QtGui>
#include "threadclient.h"


class ZoneDessin : public QWidget
{
    Q_OBJECT
public:
    explicit ZoneDessin(QWidget *parent = 0);
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
    InfoPoint * m_InfoPoint;
    QWidget * m_parent;
    QPainter *painter;
    QList <InfoPoint *> m_ListePoint;
    int m_grosseur;
    QColor m_couleur;
    QPoint m_position;
    QPixmap * m_pixmap;
    ThreadClient * m_ThClient;
protected:

void enterEvent(QEvent *);
void mousePressEvent(QMouseEvent *);
void mouseReleaseEvent(QMouseEvent *);
void mouseMoveEvent(QMouseEvent *);
void paintEvent(QPaintEvent *);
void mouseDoubleClickEvent(QMouseEvent *);

private:

    bool m_SourisPresse;


signals:

    void EnvoieInfoPoint(InfoPoint);



public slots:
    void GrosseurRecue(int);
    void CouleurRecu(QColor);

};

#endif // ZONEDESSIN_H
