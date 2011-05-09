#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QWidget>
#include <QtGui>


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
    QPoint m_PositionSouris;
    QPainter *painter;
    QList <InfoPoint * > m_ListePoint;
    int m_grosseur;
    QColor m_couleur;
    QPoint m_position;
protected:

void enterEvent(QEvent *);
void mousePressEvent(QMouseEvent *);
void mouseReleaseEvent(QMouseEvent *);
void mouseMoveEvent(QMouseEvent *);
void paintEvent(QPaintEvent *);

private:

    bool m_SourisPresse;


signals:



public slots:
    void GrosseurRecue(int);
    void CouleurRecu(QColor);

};

#endif // ZONEDESSIN_H
