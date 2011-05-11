#include "zonedessin.h"


ZoneDessin::ZoneDessin(QWidget *parent) :
    QWidget(parent)
{

    m_parent = parent;
    m_SourisPresse  = false;
    painter = new QPainter();
    this->setFixedSize(771,441);
    m_InfoPoint =  new InfoPoint();
    m_grosseur = 5;
    m_pixmap = new QPixmap(771,441);
    m_pixmap->fill(Qt::transparent);
    m_ThClient =new ThreadClient();
    connect(this,SIGNAL(EnvoieInfoPoint(InfoPoint)),m_ThClient,SLOT(RecuInfoPoint(InfoPoint)));



}



void ZoneDessin::mousePressEvent(QMouseEvent * m)
{
    m_SourisPresse = true;
    m_InfoPoint = new InfoPoint();
    m_InfoPoint->Position = m->pos();
    m_InfoPoint = new InfoPoint(m_couleur,m_grosseur,m_InfoPoint->Position);
    m_parent->repaint(this->rect());





}

void ZoneDessin::mouseDoubleClickEvent(QMouseEvent * m)
{
    m_SourisPresse = true;
    m_InfoPoint = new InfoPoint();
    m_InfoPoint->Position = m->pos();


}

void ZoneDessin::mouseReleaseEvent(QMouseEvent *)
{
    m_SourisPresse = false;
    m_ListePoint.append(m_InfoPoint);
    m_InfoPoint = new InfoPoint(m_couleur,m_grosseur,m_position);

}


void ZoneDessin::paintEvent(QPaintEvent *)
{

    if(m_SourisPresse)
    {



        painter->begin(m_pixmap);
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(QPen(QBrush(m_InfoPoint->Couleur,Qt::SolidPattern),m_InfoPoint->Grosseur));
        painter->drawPoint(m_InfoPoint->Position);
        painter->end();
        painter->begin(this);
        painter->drawPixmap(0,0,771,441,*m_pixmap);
        painter->end();

    }



}


void ZoneDessin::enterEvent(QEvent *)
{
    m_parent->setCursor(Qt::CrossCursor);
}

void ZoneDessin::mouseMoveEvent(QMouseEvent * m)
{
    m_position = m->pos();
    m_InfoPoint = new InfoPoint(m_couleur,m_grosseur,m_position);
    m_parent->repaint(this->rect());






}

void ZoneDessin::GrosseurRecue(int i)
{
    m_grosseur = i;
}

void ZoneDessin::CouleurRecu(QColor c)
{
    m_couleur = c;

}
