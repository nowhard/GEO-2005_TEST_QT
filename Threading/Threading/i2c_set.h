#ifndef I2C_SET_H
#define I2C_SET_H

#include <QDialog>
#include "proto_uso.h"
#include<QByteArray>
#include<QDate>
#include<QTime>
#include<QString>
#include <QTimer>

#define MEM_PAGE_LEN 16
#define MEM_LEN 32768
#define MAX_TIMEOUT 5

namespace Ui {
class I2C_Set;
}

class I2C_Set : public QDialog
{
    Q_OBJECT
    
public:
    explicit I2C_Set(QWidget *parent = 0, proto_uso *uso=NULL);
    ~I2C_Set();
public slots:
    void on_MEMORY_READ_BUF(QByteArray buf);//���� �������� ������
    void on_MEMORY_READ_TIMEOUT(void);//������� ������ ������, ����������
    void on_TimerGetTime_responsed(tTime Time);//���� ��������� �������� �������
    void Time_Request(void);//��������� �����
    void on_I2C_ERROR(void);//��������� ������ ����
private slots:
//    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();

    void on_checkBox_17_clicked();//��������� ���� �������



private:
    Ui::I2C_Set *ui;
    proto_uso *p_uso;
    quint8 DEV_ADDR;
    quint8 I2C_ERROR;
    quint16 MEM_COUNTER;
    QTimer *Timer;

    QWidget *parent;

    quint8 timeout_count;//������� ��������� ��� �������� ����������
protected:
    void closeEvent(QCloseEvent *);//������������� ������� ��������


};

#endif // I2C_SET_H
