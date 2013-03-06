#include "input_thread.h"

#define MODE_ASCII 0

Input_Thread::Input_Thread(QObject *parent,AbstractSerial *port, proto_uso *uso) :
    QThread(parent)
{
        this->port=port;
   //     connect(port,SIGNAL(readyRead()),this,SLOT(ReadPort()));
     //   Timeout=new QTimer();//таймер таймаута
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
               if(ba.length()>=6)//если длина до значения длины содержимого
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
                              while((i=ba.indexOf(head,j))!=(-1))//обрабатываем массив
                              {
                                   ba.remove(i+1,1);
                                   j=i+1;
                              }
                              qDebug() <<"after handle";
                              qDebug() <<ba.toHex();

                               if((ba.length()-6)!=ba[5])//все равно больше или меньше? ошибка
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

//    if(ba.length()<5)//если длина до значения длины содержимого
//    {
//        return;
//    }
//    else
//    {
//        if(ba.mid(6,ba.length()-6).length()<ba[5])//приняли все
//        {
//            return;
//        }
//        else
//        {
//            if(ba.mid(6,ba.length()-6).length()>ba[5])//если длина массива больше настоящей длины
//            {
//                while((i=ba.indexOf(head,j))>0)//обрабатываем массив
//                {
//                    ba.remove(i+1,1);
//                    j=i+1;
//                }
//                if(ba.mid(6,ba.length()-6).length()>ba[5])//все равно больше? ошибка
//                {
//                   emit ReadOK(false);
//                   return;
//                }
//            }
//            else//длина совпала
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
