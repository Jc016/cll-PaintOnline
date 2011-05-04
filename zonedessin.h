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



    };
    InfoPoint * m_InfoPoint;
    QWidget * m_parent;
    QPoint m_PositionSouris;
    QPainter *painter;
    QList <InfoPoint *> m_ListePoint;
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

};

#endif // ZONEDESSIN_H
