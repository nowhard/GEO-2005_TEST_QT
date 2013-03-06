#ifndef PROTO_USO_H
#define PROTO_USO_H

#include <QObject>
#include <QVector>
#include <QByteArray>
#include <abstractserial.h>
#include <QTimer>
//#include "input_thread.h"


class tTime//����� �������
{
public:
    unsigned char Flags; 			//����� �������
    unsigned char Calibr;			//������� ����������
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
     proto_uso(QObject *parent,AbstractSerial *port);//����������� ������
     ~proto_uso();//����������

  enum
  {
  GET_DEV_INFO_REQ_ 		=	 0x1, //�������� ���������� �� ����������	(��� �������)
  GET_DEV_INFO_RESP_		=	 0x2,	//�������� ���������� �� ����������	(��� ������)

  NODE_FULL_INIT_REQ_		=	 0x3,	//������ ������������� ����
  NODE_FULL_INIT_RESP_		=	 0x4,//������ ������������� ����-��� ������

  CHANNEL_LIST_INIT_REQ_	        =        0x5, //������������� ������ ������� ���� (��� ������ ������);
  CHANNEL_LIST_INIT_RESP_	=	 0x6,	//������������� ������ ������� ���� (��� ������ ������); ��� ������

  CHANNEL_GET_DATA_REQ_          =        0x7,// ������ ������ �� �������, �������� ���������� ���������;
  CHANNEL_GET_DATA_RESP_=		 0x8,// ������ ������ �� �������, �������� ���������� ���������;

  CHANNEL_SET_PARAMETERS_REQ_=            0x9,	//���������� ��������� �� �������, �������� ���������� ���������;
  //CHANNEL_SET_PARAMETERS_RESP_=  	//���������� ��������� �� �������, �������� ���������� ���������; ��� ������

  CHANNEL_SET_ORDER_QUERY_REQ_=   	 0xA,//������ ������������������ ������;
  CHANNEL_SET_ORDER_QUERY_RESP_= 	 0xB,//������ ������������������ ������; ��� ������

  CHANNEL_GET_DATA_ORDER_REQ_=		 0xC,	//������ ������ �� �������, �������� ������������������ ������;
  CHANNEL_GET_DATA_ORDER_RESP_=  	 0xD,	//������ ������ �� �������, �������� ������������������ ������;

  CHANNEL_SET_STATE_REQ_=		 0xE,//���������� ��������� �� �������, �������� ���������� ���������;
  CHANNEL_SET_STATE_RESP_=		 0xF,	   //���������� ��������� �� �������, �������� ���������� ���������; ��� ������

  CHANNEL_GET_DATA_ORDER_M2_REQ_=         0x10, //������ ������ �� �������, �������� ������������������ ������;
  CHANNEL_GET_DATA_ORDER_M2_RESP_=	 0x11,//������ ������ �� �������, �������� ������������������ ������;

  CHANNEL_SET_RESET_STATE_FLAGS_REQ_=     0x12,//���������/����� ������ ���������
  CHANNEL_SET_RESET_STATE_FLAGS_RESP_=    0X13,//���������/����� ������ ��������� -��� ������

  CHANNEL_ALL_GET_DATA_REQ_=		 0x14, //������ ���������� �� ���� ������� ���� (����������� �����);
  CHANNEL_ALL_GET_DATA_RESP_=		 0x15, //������ ���������� �� ���� ������� ���� (����������� �����);

  CHANNEL_SET_ADDRESS_DESC_=		 0xCD, //���������� �����, ���, �������� � �.�.
  CHANNEL_SET_CALIBRATE_=                0xCA,//���������� ���������� �������

  CHANNEL_SET_DISCRET_OUT_REQ_=     0x16,//���������� ���������� ������
  CHANNEL_SET_DISCRET_OUT_RESP_=	0x17,

  TIMER_SET_TIME_REQ_=				0x18,//���������� �����
  TIMER_SET_TIME_RESP_=             0x19,

  TIMER_GET_TIME_REQ_=				0x1A,//�������� �����
  TIMER_GET_TIME_RESP_=             0x1B,

  MEMORY_WRITE_BUF_REQ_=			0x1C,// �������� ����� � ������
  MEMORY_WRITE_BUF_RESP_=			0x1D,

  MEMORY_READ_BUF_REQ_=             0x1E,// ������� ����� �� ������
  MEMORY_READ_BUF_RESP_=			0x1F,


  REQUEST_ERROR_=			 0xFF//��������� ������/�����;
};//������������ ������� ���������

enum
{
    FR_SUCCESFUL 			=			0x0,//��� ������ (������������ ��� �������������)
    FR_UNATTENDED_CHANNEL 		=			0x1,//� ������� ����� �����, �� ������������� ������������� �������;
    FR_SET_UNATTENDED_CHANNEL		=			0x2,//� �������� ������������������ ������ ����� �����, �� ������������� ��-����������� ������� (�������� � ����� �� �������� ������� 0Ah);
    FR_ORDER_NOT_SET			=			0x3,//������������������ ������ �� ������ (�������� � ����� �� �������� ������� 0Ch);
    FR_CHNL_NOT_IN_ORDER_REQ		=			0x4,//� ������� ������������ �����, �� �������� � ������������������ ������ (�������� � ����� �� �������� ������� 0Ch);
    FR_FALSE_TYPE_CHNL_DATA		=			0x5,//���������� ���������� �� ������ � ������� ���� ������ ���������� �� ����� (�������� � ����� �� �������� ������� 09h ��� 0Eh);
    FR_COMMAND_NOT_EXIST		=			0x6,//�������������� �������;
    FR_CHNL_TYPE_NOT_EXIST		=			0x7,//�������������� ���/����������� ������;
    FR_COMMAND_NOT_SUPPORT		=			0x8,//������� �� ��������������;
    FR_COMMAND_STRUCT_ERROR		=			0x9,//������ � ��������� �������;
    FR_FRAME_LENGTH_ERROR		=			0xA,//�������������� ����� ����� � ���������� �������;
    FR_CHANNEL_NUM_TOO_MUCH		=			0xC,//������� ����� ������� � �����.
    FR_CHNL_TYPE_ERROR			=			0xD,//�������������� ���� ������
    FR_CHNL_NOT_EXIST			=			0xF//������������� �����
};//������������ ����� ������� ��������

enum
{
    CHN_ADC=0x0,//
    CHN_DOL=0x1,
    CHN_COUNT=0x2
};//����������� ����� �������




class DEVICE *DEV;

signals:
    //void WriteToOut_Thread(QByteArray request);//������ ��� ������ ��������� ������
    void DEV_INFO_RESPONSED(void);
    void GET_ALL_DATA_RESPONSED(void);

    void MEMORY_READ_BUF_RESPONSED(QByteArray buf);
    //----��������----
    void DEV_INFO_TIMEOUT(void);
    void GET_ALL_DATA_TIMEOUT(void);
    void TIMER_GET_TIME_TIMEOUT(void);
    void TIMER_SET_TIME_TIMEOUT(void);
    void MEMORY_READ_BUF_TIMEOUT(void);
    void MEMORY_WRITE_BUF_TIMEOUT(void);
    void TIMER_GET_TIME_RESPONSED(tTime);

    void CRC_ERROR(void);//��������� ������ crc
    void TIMEOUT_ERROR(void);//������ ��������
    void I2C_ERROR(void);//������ ������� � ���������� i2c
        void Send_OK(bool OK);

public slots:

    void GET_DEV_INFO_REQ(quint8 dev_addr);//������ �� ��������� ���������� �� ����������
    void GET_DEV_INFO_RESP(QByteArray response);//���������� ���������� ���������� �� ����������

    void CHANNEL_SET_PARAMETERS_REQ(quint8 dev_addr, class CHANNEL *chnl[]);//���������� ��������� �������

    void CHANNEL_ALL_GET_DATA_REQ(qint8 dev_addr);//������ ���������� �� ���� �������
    void CHANNEL_ALL_GET_DATA_RESP(QByteArray response);//����� �� ������ ������ ���������� �� ���� �������

    void REQUEST_ERROR(QByteArray response);//����� ���������� ������, ��������� ��� �������� ������, ������ � �.�.

    void CHANNEL_SET_DISCRET_OUT_REQ(qint8 dev_addr,quint8 port_val_1,quint8 port_val_2);//���������� �������� ����������� �����

    void TIMER_GET_TIME_REQ(qint8 dev_addr);//��������� �������� �����-��������� i2c
    void TIMER_GET_TIME_RESP(QByteArray response);//����� ���-5-������ �������

    void TIMER_SET_TIME_REQ(qint8 dev_addr, tTime Time);//���������� �������� �����-���������
    void TIMER_SET_TIME_RESP(QByteArray response);//����� ���-5 -��������� �������

    void MEMORY_READ_BUF_REQ(qint8 dev_addr,quint16 addr,quint8 length);//������ ������ � ������ addr ������ length
    void MEMORY_READ_BUF_RESP(QByteArray response);//����� -����������� ����� ��� ������ ����������

    void MEMORY_WRITE_BUF_REQ(qint8 dev_addr,quint16 addr,quint8 length,QByteArray buf);//������ ������ � ������ addr ������ length
    void MEMORY_WRITE_BUF_RESP(QByteArray response);//����� -������ ������ ��� ������ ����������
    void ResponseHandling(QByteArray response);

private slots:

    void Device_Not_Response(void);//���� -������� ����������, ���������� �� ��������
    void Send_Frame(QByteArray out_data);//�������� ����
    void Recieve_Frame(void);//������� ����
private:

    quint8 CRC8(QByteArray data,quint8 len);//CRC8 ��� ���������
    AbstractSerial *port;
   // QByteArray response;

//    Input_Thread *in_thread;//������� ����� ������//
    //Output_Thread *out_thread;

    QTimer *timer;
    QTimer *RecieveDelay;
    tTime Time;
    quint8 current_request;//������� ������
    QByteArray ba;//�����, �����������

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
    QString notice;//����������



    QVector <CHANNEL *> channel_mas;
    void Init_Channels(quint8 num_chn);//������� ������ ��� �������

} ;//��������� ����������




#endif // PROTO_USO_H
