#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QWidget>

class ZoneDessin : public QWidget
{
    Q_OBJECT
public:
    explicit ZoneDessin(QWidget *parent = 0);

protected:

void enterEvent(QEvent *);
void mousePressEvent(QMouseEvent *);


signals:

public slots:

};

#endif // ZONEDESSIN_H
