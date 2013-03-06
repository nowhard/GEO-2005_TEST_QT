#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "com_thread.h"
#include <abstractserial.h>
#include <QDebug>
#include <QTimer>
#include <QString>
#include "serial_io.h"
#include "proto_uso.h"
#include "i2c_set.h"

#include "dialog_com.h"
#include "ui_dialog_com.h"
#include "delegate.h"
#include <QTextCodec>
#include <QStringList>
#include <QCheckBox>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QIODevice>
#include <QSettings>
#include <QVector>
#include <QPointF>
//#include "input_thread.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:


private:
    class CalibrPoints
    {
    public:
        unsigned long first_point_x;
        unsigned long first_point_y;
        unsigned long second_point_x;
        unsigned long second_point_y;
    };
    Ui::MainWindow *ui;

    //---------------------
    AbstractSerial *port;
    proto_uso *p_uso;
    //---------------------
    //---------------------
    QTimer *timer;
    //---------------------
    Dialog_com com_dlg;
    I2C_Set   *I2C_Dev;

    bool read_flag;
    QStringList strlist, bitlist;
    CHANNEL *chnl[11];

    uint16_t DEV_ADDR;

    quint16 CRC_ERROR;
    quint16 TIMEOUT_ERROR;
   // Input_Thread *in_thread;//входной поток данных//
    //quint8 get_data_flag;//флаг-можно запросить данные


private slots:

  //  void on_pushButton_5_clicked();
  //  void on_pushButton_4_clicked();
 //   void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_action_COM_triggered();


    void on_dev_info_responsed(void);
    void on_dev_get_data_responsed(void);


    void MessageReadOK(bool mess);
    void MessageWriteOK(bool mess);
    void MessageNotConnected(void);



    void Display_Dev_Info(bool OK,quint16 ID, QString Description);

    void Get_All_Data(void);

    void UnactiveInterface(void);
    void ActivateInterface(void);



    void on_menu_load_settings_clicked();
    void on_menu_save_settings_clicked();

    void on_action_2_triggered();
    void on_action_4_triggered();
    void on_action_3_triggered();
    void on_action_5_triggered();
    void on_checkBox_clicked();
    void on_pushButton_clicked();

    //----------------------------
    void on_CRC_ERROR(void);//если ошибка crc
    void on_TIMEOUT_ERROR(void);//если случился таймаут
};




#endif // MAINWINDOW_H
