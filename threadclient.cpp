#include "threadclient.h"

ThreadClient::ThreadClient(QObject *parent) :
    QThread(parent)
{
    m_InfoPoint = InfoPoint();
    m_bEtat = true;
    m_NouveauPoint = false;


}

void ThreadClient::run()
{
    emit DemanderInfoUsager();
    this->sleep(10);

    m_SockClient.connectToHost(m_InfoUsager.Adresse,20001);


    if(m_SockClient.waitForConnected(1000))
    {
        while(m_bEtat)
        {
            while(m_SockClient.waitForReadyRead(100))
            {
                if(m_NouveauPoint)
                {
                    QByteArray ba;
                    memcpy(&m_InfoPoint, &ba, sizeof(m_InfoPoint));
                    m_SockClient.write(ba);
                    m_SockClient.waitForBytesWritten(10);
                    m_NouveauPoint = false;
                }
                m_ReceptionPixmap.append((m_SockClient.read(m_SockClient.bytesAvailable())));
                emit MAJPaint(m_ReceptionPixmap);
                m_ReceptionPixmap.clear();
                m_SockClient.write("#");
                m_SockClient.waitForBytesWritten();

            }

            m_SockClient.disconnectFromHost();
            m_SockClient.close();
            this->terminate();
        }

    }
    else
    {
      emit AffichageMessageErreur();
      this->terminate();

    }



}

void ThreadClient::RecuInfoPoint(InfoPoint Info)
{
    m_InfoPoint = Info;
    m_NouveauPoint = true;

}
void ThreadClient::RecuInfoUsagerClient(InfoUsager Iu)
{
       m_InfoUsager = Iu;
}

