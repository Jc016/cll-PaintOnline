#ifndef PAINTONLINECLIENT_H
#define PAINTONLINECLIENT_H

#include <QMainWindow>

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

};

#endif // PAINTONLINECLIENT_H
