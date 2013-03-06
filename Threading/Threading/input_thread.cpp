#include "input_thread.h"

#define MODE_ASCII 0

Input_Thread::Input_Thread(QObject *parent,AbstractSerial *port, proto_uso *uso) :
    QThread(parent)
{
        this->port=port;
   //     connect(port,SIGNAL(readyRead()),this,SLOT(ReadPort()));
     //   Timeout=new QTimer();//������ ��������
        p_uso=uso;

}

void Input_Thread::run()
{
    QByteArray head;
    qint8 i,j=3;

    head.append((char)0xD7);
    head.append((char)0x00);

    while (1)
    {
        msleep(20);
            if ((port->bytesAvailable() > 0) && port->isOpen() )
            {
               qDebug() <<"bytesAvaible";
                ba.append(port->read(256));
               if(ba.length()>=6)//���� ����� �� �������� ����� �����������
               {
                   if((ba.length()-6)==ba[5])//
                   {
                        qDebug() << "Readed is : " << ba.size() << " bytes";
                        qDebug() <<ba.toHex();
                        //emit isRead(ba);
                        p_uso->ResponseHandling(ba);
                        ba.clear();

                       // msleep(10);
                       // ba.clear();
                   }
                   else
                   {
                       if((ba.length()-6)>ba[5])
                       {
                              i=0;
                              j=3;
                              qDebug() <<"before handle";
                              qDebug() <<ba.toHex();
                              while((i=ba.indexOf(head,j))!=(-1))//������������ ������
                              {
                                   ba.remove(i+1,1);
                                   j=i+1;
                              }
                              qDebug() <<"after handle";
                              qDebug() <<ba.toHex();

                               if((ba.length()-6)!=ba[5])//��� ����� ������ ��� ������? ������
                               {
                                  qDebug() <<"LEN ERR!";
                                  ba.clear();
                               }
                               else
                               {
                                   qDebug() << "Readed is : " << ba.size() << " bytes with handle";
                                   qDebug() <<ba.toHex();
                                   //emit isRead(ba);
                                    p_uso->ResponseHandling(ba);
                                    ba.clear();
                               }
                        }
                    }
               }
           }
    }
}

 void Input_Thread::ReadPort(void)
 {
//     QByteArray head;
//     qint8 i,j=3;
//     QByteArray temp_data=port->read(256);
//    ba.append(temp_data);

//    head.append((char)0xD7);
//    head.append((char)0x00);

//    if(ba.length()<5)//���� ����� �� �������� ����� �����������
//    {
//        return;
//    }
//    else
//    {
//        if(ba.mid(6,ba.length()-6).length()<ba[5])//������� ���
//        {
//            return;
//        }
//        else
//        {
//            if(ba.mid(6,ba.length()-6).length()>ba[5])//���� ����� ������� ������ ��������� �����
//            {
//                while((i=ba.indexOf(head,j))>0)//������������ ������
//                {
//                    ba.remove(i+1,1);
//                    j=i+1;
//                }
//                if(ba.mid(6,ba.length()-6).length()>ba[5])//��� ����� ������? ������
//                {
//                   emit ReadOK(false);
//                   return;
//                }
//            }
//            else//����� �������
//            {
//                qDebug() << "Readed is : " << ba.size() << " bytes";
//                      qDebug()<< ba.toHex();
//                emit isRead(ba);
//                emit ReadOK(true);

//                ba.clear();
//            }
//        }
//    }
 }

 Input_Thread::~Input_Thread()
 {
   this->terminate();
 }
