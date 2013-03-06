#include "proto_uso.h"

proto_uso::proto_uso(QObject *parent,AbstractSerial *port) :
    QObject(parent)
{
    this->port=port;



 //   connect(in_thread,SIGNAL(isRead(QByteArray)),this,SLOT(ResponseHandling(QByteArray)));
    //connect(this,SIGNAL(WriteToOut_Thread(QByteArray)),out_thread,SLOT(Send(QByteArray)));


    timer=new QTimer(this);
    RecieveDelay=new QTimer(this);
    DEV=new DEVICE();
    //connect(timer,SIGNAL(timeout()),this,SIGNAL(DEVICE_NOT_CONNECTED()));
   connect(timer,SIGNAL(timeout()),this,SLOT(Device_Not_Response()));
    connect(timer,SIGNAL(timeout()),this,SIGNAL(TIMEOUT_ERROR()));

    //connect(port,SIGNAL(readyRead()),this,SLOT(Recieve_Frame()));
    RecieveDelay->setInterval(20);
    connect(port,SIGNAL(readyRead()),RecieveDelay,SLOT(start()));
    connect(RecieveDelay,SIGNAL(timeout()),this,SLOT(Recieve_Frame()));
    connect(RecieveDelay,SIGNAL(timeout()),RecieveDelay,SLOT(stop()));
}

proto_uso::~proto_uso()//деструктор
{
    delete timer;
}

void proto_uso::GET_DEV_INFO_REQ(quint8 dev_addr)//запрос на получение информации об устройстве
{
  //  QString debug;

    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(GET_DEV_INFO_REQ_);
    current_request=GET_DEV_INFO_REQ_;
    request.append(0x1);
    CRC=CRC8(request,request.length());
    request.append(CRC);
    //this->in_thread->ba.clear();
    timer->start(500);
    Send_Frame(request);

    return;
}

void proto_uso::GET_DEV_INFO_RESP(QByteArray response)//обработчик полученной информации об устройстве
{
    quint8 len;

   if(response.length()<=5)
    {
       qDebug("NOT ACCEPTED!!!");
       return;//вылетаем
    }

    len=response[5];//получим длину оставшейся части
    DEV->state_byte=response[6];//получим байт статуса узла
    DEV->device_name.clear();//очищаем перед занесением нового имени
    DEV->device_name.append(response.mid(7,20));
    DEV->version=response.mid(27,5);//?
    DEV->channel_num=response[32];

    DEV->Init_Channels(DEV->channel_num);

    DEV->notice.clear();
    DEV->notice.append(response.mid(33+DEV->channel_num*2,response.length()-34-DEV->channel_num*2));

    for(quint8 i=0;i<DEV->channel_num;i++)
    {
        DEV->channel_type[i]=response[33+i*2];
        DEV->channel_mas[i]->channel_type=response[33+i*2];

    }
    emit DEV_INFO_RESPONSED();
    qDebug("ACCEPTED!!! %i",DEV->channel_num );
    return;
}

void proto_uso::CHANNEL_SET_PARAMETERS_REQ(quint8 dev_addr, class CHANNEL *chnl[])//установить параметры каналов
{
    //qDebug()<<"SETTINGS SET "<<chnl[8]->state_byte1;
    QByteArray request, set_request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_SET_PARAMETERS_REQ_);
    current_request=CHANNEL_SET_PARAMETERS_REQ_;
    for(quint8 i=0;i< this->DEV->channel_num;i++)
    {
        if(i<8)
        {
            set_request.append(i);
            set_request.append(chnl[i]->channel_type);
            set_request.append(chnl[i]->state_byte1);
            set_request.append(chnl[i]->state_byte2);
        }
        else
        {
           // set_request.append(i);
           // set_request.append(chnl[i]->channel_type);
          //  set_request.append(chnl[i]->state_byte1);
        }
    }
    request.append(set_request.length()+1);//оставшаяся длина кадра +crc
    request.append(set_request);
    CRC=CRC8(request,request.length());
    request.append(CRC);
    //this->in_thread->ba.clear();
    timer->start(500);
    Send_Frame(request);


    return;
}

void proto_uso::CHANNEL_ALL_GET_DATA_REQ(qint8 dev_addr)//выдать информацию по всем каналам
{
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_ALL_GET_DATA_REQ_);
    current_request=CHANNEL_ALL_GET_DATA_REQ_;
    request.append(0x1);
    CRC=CRC8(request,request.length());
    request.append(CRC);
    //this->in_thread->ba.clear();

     Send_Frame(request);
     timer->start(200);
     qDebug("DATA REQUESTED!!!");
    return;
}

void proto_uso::CHANNEL_ALL_GET_DATA_RESP(QByteArray response)//ответ на запрос выдачи информации по всем каналам
{
    //quint8 len;
    quint8 index=7, counter=0;
    timer->stop();
   if(response.length()<=5)
    {
       qDebug("NOT ACCEPTED!!!");
       return;//вылетаем
    }
    qDebug("CHANNELS %i", this->DEV->channel_num);
   while( counter< this->DEV->channel_num)
   {
        switch(/*this->DEV->channel_mas[counter]->channel_type>>4&0xF*/(quint8)response[index+1]>>4&0xF)
        {
            case CHN_ADC:
            {
                switch(/*this->DEV->channel_mas[counter]->channel_type&0xF*/response[index+1]&0xF)
                {
                case 0x0:
                    {
                        this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00);
                       // this->DEV->channel_mas[counter]->channel_type=response[index];
                        this->DEV->channel_mas[counter]->state_byte1=response[index+4];
                        this->DEV->channel_mas[counter]->state_byte2=response[index+5];
                        index+=6;
                         qDebug("ADC_0x0");
                    }
                    break;

                case 0x1:
                    {
                        this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00);
                       // this->DEV->channel_mas[counter]->channel_type=response[index];
                        this->DEV->channel_mas[counter]->state_byte1=response[index+4];
                        this->DEV->channel_mas[counter]->state_byte2=response[index+5];
                        index+=6;
                         qDebug("ADC_0x1");
                    }
                    break;

                case 0x2:
                    {
                        this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00)|((quint32)response[index+4]<<16&0xFF0000);
                       // this->DEV->channel_mas[counter]->channel_type=response[index];
                        this->DEV->channel_mas[counter]->state_byte1=response[index+5];
                        this->DEV->channel_mas[counter]->state_byte2=response[index+6];
                        index+=7;
                         qDebug("ADC_0x2");
                    }
                    break;

                case 0x3:
                    {
                        this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00)|((quint32)response[index+4]<<16&0xFF0000);
                       // this->DEV->channel_mas[counter]->channel_type=response[index];
                        this->DEV->channel_mas[counter]->state_byte1=response[index+5];
                        this->DEV->channel_mas[counter]->state_byte2=response[index+6];
                        index+=7;
                         qDebug("ADC_0x3");
                    }
                    break;
                }
            }
            break;

            case CHN_DOL:
            {
                this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|(((quint32)response[index+3]<<8)&0xFF00)|(((quint32)response[index+4]<<16)&0xFF0000)|(((quint32)response[index+5]<<24)&0xFF000000);
                //this->DEV->channel_mas[counter]->channel_type=response[index];
                this->DEV->channel_mas[counter]->state_byte1=response[index+6];

                index+=7;
                 qDebug("DOL");
            }
            break;

            case CHN_COUNT:
            {
                this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00);
                //this->DEV->channel_mas[counter]->channel_type=response[index];
                this->DEV->channel_mas[counter]->state_byte1=response[index+4];

                index+=5;
                 qDebug("COUNT");
            }
            break;

            default :
            {
                    qDebug("UNREC DATA!!!");
            }
            break;
        }
        counter++;
    }
    qDebug("DATA ACCEPTED!!!");
    emit GET_ALL_DATA_RESPONSED();
    return;
}
//-----------------------------------------------
void proto_uso::CHANNEL_SET_DISCRET_OUT_REQ(qint8 dev_addr,quint8 port_val_1,quint8 port_val_2)//установить значение дискретного порта
{
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_SET_DISCRET_OUT_REQ_);
    request.append(0x5);//длина

    request.append(0x9);//адрес 1 дискр канала
    request.append(port_val_1);//значение 1 канала

    request.append(0xA);//адрес 2 дискр канала
    request.append(port_val_2);//значение 2 канала


    CRC=CRC8(request,request.length());
    request.append(CRC);
    timer->start(500);
    Send_Frame(request);

    return;
}
//-----------------------------------------------
void proto_uso::TIMER_GET_TIME_REQ(qint8 dev_addr)//запросить значение часов-календаря i2c
{
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(TIMER_GET_TIME_REQ_);
    current_request=TIMER_GET_TIME_REQ_;
    request.append(0x1);//длина

    CRC=CRC8(request,request.length());
    request.append(CRC);
    //this->in_thread->ba.clear();
    timer->start(500);

    Send_Frame(request);

    return;
}
//-----------------------------------------------
void proto_uso::TIMER_GET_TIME_RESP(QByteArray response)//ответ ГЕО-5-выдача времени
{
    timer->stop();
    tTime Time;
    Time.Flags=response[6];
    Time.Calibr=response[7];
    Time.Second=response[8];
    Time.Minute=response[9];
    Time.Hour=response[10];
    Time.WeekDay=response[11];
    Time.Day=response[12];
    Time.Month=response[13];
    Time.Year=response[14];


    emit TIMER_GET_TIME_RESPONSED(Time);
}
//-----------------------------------------------
void proto_uso::TIMER_SET_TIME_REQ(qint8 dev_addr, tTime Time)//установить регистры часов-календаря
{
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(TIMER_SET_TIME_REQ_);
    current_request=TIMER_SET_TIME_REQ_;
    request.append(0xA);//длина

    request.append(Time.Flags);
    request.append(Time.Calibr);
    request.append(Time.Second);
    request.append(Time.Minute);
    request.append(Time.Hour);
    request.append(Time.WeekDay);
    request.append(Time.Day);
    request.append(Time.Month);
    request.append(Time.Year);

    //this->in_thread->ba.clear();
    CRC=CRC8(request,request.length());
    request.append(CRC);
    timer->start(500);
    Send_Frame(request);

    return;

}
//-----------------------------------------------
void proto_uso::TIMER_SET_TIME_RESP(QByteArray response)//ответ ГЕО-5 -установка времени
{
    timer->stop();
//ок или ошибка i2c
}
//-----------------------------------------------
void proto_uso::MEMORY_READ_BUF_REQ(qint8 dev_addr,quint16 addr,quint8 length)//чтение памяти с адреса addr длиной length
{
qDebug("MEM READ REQUEST");
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(MEMORY_READ_BUF_REQ_);
    current_request=MEMORY_READ_BUF_REQ_;
    request.append(0x4);//длина оставшейся части

    request.append((quint8)((addr>>8)&0xFF));
    request.append((quint8)(addr&0xFF));
    request.append(length);

    CRC=CRC8(request,request.length());
    request.append(CRC);



    //this->in_thread->ba.clear();
    timer->start(500);
    Send_Frame(request);

    return;
}
//-----------------------------------------------
void proto_uso::MEMORY_READ_BUF_RESP(QByteArray response)//ответ -прочитанный буфер или ошибка устройства
{
    QByteArray buf;
    timer->stop();
    buf.append(response.mid(7,response.length()-8));
    qDebug()<<" MEM READ RESPONSE";
    emit this->MEMORY_READ_BUF_RESPONSED(buf);
}
//-----------------------------------------------
void proto_uso::MEMORY_WRITE_BUF_REQ(qint8 dev_addr,quint16 addr,quint8 length,QByteArray buf)//запись памяти с адреса addr длиной length
{
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(MEMORY_WRITE_BUF_REQ_);
    current_request=MEMORY_WRITE_BUF_REQ_;
    request.append(buf.length()+4);//длина оставшейся части

    request.append((quint8)((addr>>8)&0xFF));
    request.append((quint8)(addr&0xFF));
    request.append(buf.length());
    request.append(buf);

    CRC=CRC8(request,request.length());
    request.append(CRC);
    //this->in_thread->ba.clear();
    timer->start(500);
    Send_Frame(request);

    return;
}
//-----------------------------------------------
void proto_uso::MEMORY_WRITE_BUF_RESP(QByteArray response)//ответ -запись прошла или ошибка устройства
{
    //ок или ошибка i2c
    timer->stop();
}
//-----------------------------------------------
void proto_uso::REQUEST_ERROR(QByteArray response)//общий обработчик ошибок, возникших при передаче данных, работе и т.д.
{
    timer->stop();
    if((quint8)response[response.length()-2]==FR_SUCCESFUL)//пришло подтверждение
    {
        qDebug("OK!");
        return;
    }

    qDebug("ERROR  REQ!!!");

    qDebug() <<response.toHex();

    switch((quint8)response[response.length()-3])
    {
        case TIMER_GET_TIME_REQ_:
        {
            emit I2C_ERROR();
        }
        break;

        case TIMER_SET_TIME_REQ_:
        {
            emit I2C_ERROR();
        }
        break;

        case MEMORY_WRITE_BUF_REQ_:
        {
            emit I2C_ERROR();
        }
        break;

        case MEMORY_READ_BUF_REQ_:
        {
            emit I2C_ERROR();
            emit MEMORY_READ_BUF_TIMEOUT();
        }
        break;
    }

    return;
}
//-----------------------------------------------
void proto_uso::ResponseHandling(QByteArray response)
{
    quint8 CRC,trueCRC;
    timer->stop();

    CRC=response[response.size()-1];

    //------проверка црц
    trueCRC=CRC8(response,response.length()-1);
    CRC=response[response.length()-1];

    qDebug("RESPONSED!!!");

    if(trueCRC!=CRC){
        qDebug()<<"RESPONSE CRC ERROR";
        Device_Not_Response();//обработка повторного запроса
        emit CRC_ERROR();
        return;//прерываем, если произоша ошибка передачи данных
    }
    //------------------

    switch((quint8)response[4])
    {
        case GET_DEV_INFO_RESP_:
        {
            GET_DEV_INFO_RESP(response);
        }
        break;

        case CHANNEL_ALL_GET_DATA_RESP_:
        {
            CHANNEL_ALL_GET_DATA_RESP(response);
        }
        break;

        case REQUEST_ERROR_:
        {
            REQUEST_ERROR(response);
       //     qDebug("ERROR !!!");
        }
        break;

        case TIMER_GET_TIME_RESP_:
        {
             TIMER_GET_TIME_RESP(response);
        }
        break;

        case MEMORY_READ_BUF_RESP_:
        {
             MEMORY_READ_BUF_RESP(response);
        }
        break;
    }

    return;
}
//----------------------------------------------------
void proto_uso::Device_Not_Response(void)//слот -таймаут устройства, устройство не ответило
{
    timer->stop();

    switch((quint8)current_request)
    {
        case GET_DEV_INFO_REQ_:
        {
            emit DEV_INFO_TIMEOUT();
        }
        break;

        case CHANNEL_ALL_GET_DATA_REQ_:
        {
            emit GET_ALL_DATA_TIMEOUT();
        }
        break;

        case TIMER_GET_TIME_REQ_:
        {
            emit TIMER_GET_TIME_TIMEOUT();
        }
        break;

        case TIMER_SET_TIME_REQ_:
        {
            emit TIMER_SET_TIME_TIMEOUT();
        }
        break;

        case MEMORY_READ_BUF_REQ_:
        {
            emit MEMORY_READ_BUF_TIMEOUT();
        }
        break;

        case MEMORY_WRITE_BUF_REQ_:
        {
            emit MEMORY_WRITE_BUF_TIMEOUT();
        }
        break;
    }
    ba.clear();//очищаем буфер
}
//----------------------------------------------------
quint8 proto_uso::CRC8(QByteArray data,quint8 len)//CRC8 для протокола
{
    quint8   CRC = 0;
    quint8   data_pntr=0;
        while(len)
        {
            CRC = CRC ^ (data[data_pntr]);//Spool[i];
            data_pntr++;
            CRC = ((CRC & 0x01) ? (unsigned char)0x80: (unsigned char)0x00) | (unsigned char)(CRC >> 1);

        if (CRC & (unsigned char)0x80) CRC = CRC ^ (unsigned char)0x3C;
                len--;
        }
    return CRC;
}
//--------------------------------------------------------------
void DEVICE::Init_Channels(quint8 num_chn)//создаем память для каналов
{
    for(quint8 i=0;i<num_chn;i++)
        channel_mas.append(new CHANNEL());

    return;
}
//--------------------------------------------------------------
void proto_uso::Send_Frame(QByteArray out_data)//передать кадр
{
    //реализовать добавление 0 после D7 в теле протокола
    qint8 i,j=3;
    ba.clear();
    //---------------------------------------------------
    while((i=out_data.indexOf((char)0xD7,j))!=-1)
    {
        //i=out_data.indexOf((char)0xD7,j);
        out_data.insert(i+1,(char)0x0);
        j=i+1;
//         qDebug() << "D7 DETECTED";
    }
    //---------------------------------------------------

    if(port->isOpen())
    {
        //data=out_data;
        qint64 snd=port->write(out_data.data(),out_data.size());
        qDebug() << "Write is : " << out_data.size() << " bytes";
        qDebug() <<out_data.toHex();
        if(snd==out_data.size())
        {
            emit Send_OK(true);//передан весь буфер
        }
        else
        {
           emit Send_OK(false);//передан не весь буфер
        }
    }
    else
    {
        emit Send_OK(false);//порт был закрыт
    }
}
//-------------------------------------------------------
void proto_uso::Recieve_Frame(void)//принять кадр
{
    QByteArray head;
    qint8 i,j=3;

    head.append((char)0xD7);
    head.append((char)0x00);

           qDebug() <<"bytesAvaible";
            ba.append(port->read(256));
           if(ba.length()>=6)//если длина до значения длины содержимого
           {
               if((ba.length()-6)==ba[5])//
               {
                    qDebug() << "Readed is : " << ba.size() << " bytes";
                    qDebug() <<ba.toHex();
                    ResponseHandling(ba);
                    ba.clear();
               }
               else
               {
                   if((ba.length()-6)>ba[5])
                   {
                          i=0;
                          j=3;
                         // qDebug() <<"before handle";
                         // qDebug() <<ba.toHex();
                          while((i=ba.indexOf(head,j))!=(-1))//обрабатываем массив
                          {
                               ba.remove(i+1,1);
                               j=i+1;
                          }
                        //  qDebug() <<"after handle";
                         // qDebug() <<ba.toHex();

                           if((ba.length()-6)!=ba[5])//все равно больше или меньше? ошибка
                           {
                              qDebug() <<"LEN ERR!";
                              ba.clear();
                           }
                           else
                           {
                               qDebug() << "Readed is : " << ba.size() << " bytes with handle";
                               qDebug() <<ba.toHex();
                               ResponseHandling(ba);
                               ba.clear();
                           }
                    }
                }
           }
}

