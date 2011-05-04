#include "zonedessin.h"

ZoneDessin::ZoneDessin(QWidget *parent) :
    QWidget(parent)
{
    m_parent = parent;
    m_SourisPresse  = false;
    painter = new QPainter();
    this->setFixedSize(771,441);
    m_InfoPoint =  new InfoPoint();


}



void ZoneDessin::mousePressEvent(QMouseEvent *)
{
    m_SourisPresse = true;



}

void ZoneDessin::mouseReleaseEvent(QMouseEvent *)
{
    m_SourisPresse = false;
}


void ZoneDessin::paintEvent(QPaintEvent *)
{
    if(m_SourisPresse)
    {

        painter->begin(this);
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(QPen(QBrush(m_InfoPoint->Couleur,Qt::SolidPattern),m_InfoPoint->Grosseur));
        m_ListePoint.append(m_InfoPoint);
        painter->drawPoint(m_InfoPoint->Position);
        painter->end();
        foreach (InfoPoint * i ,m_ListePoint)
        {
            painter->begin(this);
            painter->setPen(QPen(QBrush(i->Couleur,Qt::SolidPattern),i->Grosseur));
            painter->drawPoint(i->Position);
            painter->end();


        }

    }



}


void ZoneDessin::enterEvent(QEvent *)
{
    m_parent->setCursor(Qt::CrossCursor);
}

void ZoneDessin::mouseMoveEvent(QMouseEvent * m)
{
    m_InfoPoint->Position = m->pos();
    m_parent->repaint(this->rect());

}

