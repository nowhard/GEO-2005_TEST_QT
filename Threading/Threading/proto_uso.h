#ifndef PROTO_USO_H
#define PROTO_USO_H

#include <QObject>
#include <QVector>
#include <QByteArray>
#include <abstractserial.h>
#include <QTimer>
//#include "input_thread.h"


class tTime//класс таймера
{
public:
    unsigned char Flags; 			//флаги таймера
    unsigned char Calibr;			//регистр калибровки
    unsigned char Second;			//
    unsigned char Minute;			//
    unsigned char Hour;				//
    unsigned char WeekDay;  		//
    unsigned char Day;		    	//
    unsigned char Month;			//
    unsigned char Year;				//
};

class proto_uso : public QObject
{
    Q_OBJECT
public:
     proto_uso(QObject *parent,AbstractSerial *port);//конструктор класса
     ~proto_uso();//деструктор

  enum
  {
  GET_DEV_INFO_REQ_ 		=	 0x1, //получить информацию об устройстве	(код запроса)
  GET_DEV_INFO_RESP_		=	 0x2,	//получить информацию об устройстве	(код ответа)

  NODE_FULL_INIT_REQ_		=	 0x3,	//полная инициализация узла
  NODE_FULL_INIT_RESP_		=	 0x4,//полная инициализация узла-нет ответа

  CHANNEL_LIST_INIT_REQ_	        =        0x5, //Инициализация списка каналов узла (без потери данных);
  CHANNEL_LIST_INIT_RESP_	=	 0x6,	//Инициализация списка каналов узла (без потери данных); нет ответа

  CHANNEL_GET_DATA_REQ_          =        0x7,// Выдать данные по каналам, согласно абсолютной нумерации;
  CHANNEL_GET_DATA_RESP_=		 0x8,// Выдать данные по каналам, согласно абсолютной нумерации;

  CHANNEL_SET_PARAMETERS_REQ_=            0x9,	//Установить параметры по каналам, согласно абсолютной нумерации;
  //CHANNEL_SET_PARAMETERS_RESP_=  	//Установить параметры по каналам, согласно абсолютной нумерации; нет ответа

  CHANNEL_SET_ORDER_QUERY_REQ_=   	 0xA,//Задать последовательность опроса;
  CHANNEL_SET_ORDER_QUERY_RESP_= 	 0xB,//Задать последовательность опроса; нет ответа

  CHANNEL_GET_DATA_ORDER_REQ_=		 0xC,	//Выдать данные по каналам, согласно последовательности опроса;
  CHANNEL_GET_DATA_ORDER_RESP_=  	 0xD,	//Выдать данные по каналам, согласно последовательности опроса;

  CHANNEL_SET_STATE_REQ_=		 0xE,//Установить состояния по каналам, согласно абсолютной нумерации;
  CHANNEL_SET_STATE_RESP_=		 0xF,	   //Установить состояния по каналам, согласно абсолютной нумерации; нет ответа

  CHANNEL_GET_DATA_ORDER_M2_REQ_=         0x10, //Выдать данные по каналам, согласно последовательности опроса;
  CHANNEL_GET_DATA_ORDER_M2_RESP_=	 0x11,//Выдать данные по каналам, согласно последовательности опроса;

  CHANNEL_SET_RESET_STATE_FLAGS_REQ_=     0x12,//Установка/Сброс флагов состояния
  CHANNEL_SET_RESET_STATE_FLAGS_RESP_=    0X13,//Установка/Сброс флагов состояния -нет ответа

  CHANNEL_ALL_GET_DATA_REQ_=		 0x14, //Выдать информацию по всем каналам узла (расширенный режим);
  CHANNEL_ALL_GET_DATA_RESP_=		 0x15, //Выдать информацию по всем каналам узла (расширенный режим);

  CHANNEL_SET_ADDRESS_DESC_=		 0xCD, //установить адрес, имя, описание и т.д.
  CHANNEL_SET_CALIBRATE_=                0xCA,//установить калибровку каналов

  CHANNEL_SET_DISCRET_OUT_REQ_=     0x16,//установить дискретные выводы
  CHANNEL_SET_DISCRET_OUT_RESP_=	0x17,

  TIMER_SET_TIME_REQ_=				0x18,//установить время
  TIMER_SET_TIME_RESP_=             0x19,

  TIMER_GET_TIME_REQ_=				0x1A,//получить время
  TIMER_GET_TIME_RESP_=             0x1B,

  MEMORY_WRITE_BUF_REQ_=			0x1C,// записать буфер в память
  MEMORY_WRITE_BUF_RESP_=			0x1D,

  MEMORY_READ_BUF_REQ_=             0x1E,// считать буфер из памяти
  MEMORY_READ_BUF_RESP_=			0x1F,


  REQUEST_ERROR_=			 0xFF//Ошибочный запрос/ответ;
};//перечисление функций протокола

enum
{
    FR_SUCCESFUL 			=			0x0,//Нет ошибки (используется для подтверждения)
    FR_UNATTENDED_CHANNEL 		=			0x1,//В запросе задан канал, не обслуживаемый измерительным модулем;
    FR_SET_UNATTENDED_CHANNEL		=			0x2,//В заданной последовательности опроса задан канал, не обслуживаемый из-мерительным модулем (выдается в ответ на неверную команду 0Ah);
    FR_ORDER_NOT_SET			=			0x3,//Последовательность опроса не задана (выдается в ответ на неверную команду 0Ch);
    FR_CHNL_NOT_IN_ORDER_REQ		=			0x4,//В запросе присутствует канал, не заданный в последовательности опроса (выдается в ответ на неверную команду 0Ch);
    FR_FALSE_TYPE_CHNL_DATA		=			0x5,//Задаваемая информация по каналу к данному типу канала относиться не может (выдается в ответ на неверную команду 09h или 0Eh);
    FR_COMMAND_NOT_EXIST		=			0x6,//Несуществующая команда;
    FR_CHNL_TYPE_NOT_EXIST		=			0x7,//Несуществующий тип/модификация канала;
    FR_COMMAND_NOT_SUPPORT		=			0x8,//Команда не поддерживается;
    FR_COMMAND_STRUCT_ERROR		=			0x9,//Ошибка в структуре команды;
    FR_FRAME_LENGTH_ERROR		=			0xA,//Несоответствие длины кадра и количества каналов;
    FR_CHANNEL_NUM_TOO_MUCH		=			0xC,//слишком много каналов в кадре.
    FR_CHNL_TYPE_ERROR			=			0xD,//Несоответствие типа канала
    FR_CHNL_NOT_EXIST			=			0xF//Отсутствующий канал
};//перечисление кодов сбойных ситуаций

enum
{
    CHN_ADC=0x0,//
    CHN_DOL=0x1,
    CHN_COUNT=0x2
};//перечсление типов каналов




class DEVICE *DEV;

signals:
    //void WriteToOut_Thread(QByteArray request);//сигнал для класса выходного потока
    void DEV_INFO_RESPONSED(void);
    void GET_ALL_DATA_RESPONSED(void);

    void MEMORY_READ_BUF_RESPONSED(QByteArray buf);
    //----таймауты----
    void DEV_INFO_TIMEOUT(void);
    void GET_ALL_DATA_TIMEOUT(void);
    void TIMER_GET_TIME_TIMEOUT(void);
    void TIMER_SET_TIME_TIMEOUT(void);
    void MEMORY_READ_BUF_TIMEOUT(void);
    void MEMORY_WRITE_BUF_TIMEOUT(void);
    void TIMER_GET_TIME_RESPONSED(tTime);

    void CRC_ERROR(void);//случилась ошибка crc
    void TIMEOUT_ERROR(void);//ошибка таймаута
    void I2C_ERROR(void);//ошибка доступа к устройству i2c
        void Send_OK(bool OK);

public slots:

    void GET_DEV_INFO_REQ(quint8 dev_addr);//запрос на получение информации об устройстве
    void GET_DEV_INFO_RESP(QByteArray response);//обработчик полученной информации об устройстве

    void CHANNEL_SET_PARAMETERS_REQ(quint8 dev_addr, class CHANNEL *chnl[]);//установить параметры каналов

    void CHANNEL_ALL_GET_DATA_REQ(qint8 dev_addr);//выдать информацию по всем каналам
    void CHANNEL_ALL_GET_DATA_RESP(QByteArray response);//ответ на запрос выдачи информации по всем каналам

    void REQUEST_ERROR(QByteArray response);//общий обработчик ошибок, возникших при передаче данных, работе и т.д.

    void CHANNEL_SET_DISCRET_OUT_REQ(qint8 dev_addr,quint8 port_val_1,quint8 port_val_2);//установить значение дискретного порта

    void TIMER_GET_TIME_REQ(qint8 dev_addr);//запросить значение часов-календаря i2c
    void TIMER_GET_TIME_RESP(QByteArray response);//ответ ГЕО-5-выдача времени

    void TIMER_SET_TIME_REQ(qint8 dev_addr, tTime Time);//установить регистры часов-календаря
    void TIMER_SET_TIME_RESP(QByteArray response);//ответ ГЕО-5 -установка времени

    void MEMORY_READ_BUF_REQ(qint8 dev_addr,quint16 addr,quint8 length);//чтение памяти с адреса addr длиной length
    void MEMORY_READ_BUF_RESP(QByteArray response);//ответ -прочитанный буфер или ошибка устройства

    void MEMORY_WRITE_BUF_REQ(qint8 dev_addr,quint16 addr,quint8 length,QByteArray buf);//запись памяти с адреса addr длиной length
    void MEMORY_WRITE_BUF_RESP(QByteArray response);//ответ -запись прошла или ошибка устройства
    void ResponseHandling(QByteArray response);

private slots:

    void Device_Not_Response(void);//слот -таймаут устройства, устройство не ответило
    void Send_Frame(QByteArray out_data);//передать кадр
    void Recieve_Frame(void);//принять кадр
private:

    quint8 CRC8(QByteArray data,quint8 len);//CRC8 для протокола
    AbstractSerial *port;
   // QByteArray response;

//    Input_Thread *in_thread;//входной поток данных//
    //Output_Thread *out_thread;

    QTimer *timer;
    QTimer *RecieveDelay;
    tTime Time;
    quint8 current_request;//текущий запрос
    QByteArray ba;//буфер, принимающий

};

class CHANNEL
{
public:
    quint8 channel_type;
    quint8 state_byte1;
    quint8 state_byte2;
    quint32 channel_data;
};

class DEVICE
{
public:
    quint8 state_byte;
    QString device_name;
    QByteArray version;
    quint8 channel_num;
    QByteArray channel_type;//?
    QString notice;//примечание



    QVector <CHANNEL *> channel_mas;
    void Init_Channels(quint8 num_chn);//создаем память для каналов

} ;//структура устройства




#endif // PROTO_USO_H
