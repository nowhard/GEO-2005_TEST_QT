#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    port=new AbstractSerial(this);
    port->setTotalReadConstantTimeout(0);

    timer=new QTimer();

    p_uso=new proto_uso(this,port);

    I2C_Dev=new I2C_Set(this,p_uso);
     QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Название канала")));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Тип канала")));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Диапазон")));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Фильтр")));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Значение DEC")));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Значение HEX")));


    //timer->start(300);

     ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);


     connect(p_uso,SIGNAL(DEV_INFO_RESPONSED()),this,SLOT(on_dev_info_responsed()));
     connect(p_uso,SIGNAL(GET_ALL_DATA_RESPONSED()),this,SLOT(on_dev_get_data_responsed()));

     connect(ui->action_LOAD,SIGNAL(triggered()),this,SLOT(on_menu_load_settings_clicked()));
     connect(ui->action_SAVE,SIGNAL(triggered()),this,SLOT(on_menu_save_settings_clicked()));

     connect(timer,SIGNAL(timeout()),this,SLOT(Get_All_Data()));



     connect(p_uso,SIGNAL(CRC_ERROR()),this,SLOT(on_CRC_ERROR()));
     connect(p_uso,SIGNAL(TIMEOUT_ERROR()),this,SLOT(on_TIMEOUT_ERROR()));

     for(quint8 i=0;i<12;i++)
     {
          chnl[i]=new CHANNEL();
     }

     strlist<<tr("0-2.56 В")<<tr("0-1.28 В")<<tr("0-640 мВ")<<tr("0-320 мВ")<<tr("0-160 мВ")<<tr("0-80 мВ")<<tr("0-40 мВ")<<tr("0-20 мВ");
     bitlist<<tr("24")<<tr("16");

     read_flag=false;
     DEV_ADDR=0x1;
     CRC_ERROR=0;
     TIMEOUT_ERROR=0;

     UnactiveInterface();
}
//-----------------------------------------
MainWindow::~MainWindow()
{
    port->close();
    delete port;
    delete ui;
}
//------------------------------------------
void MainWindow::on_action_COM_triggered()
{
    com_dlg.show();
}
//------------------------------------------
void MainWindow::MessageReadOK(bool mess)
{
    if(mess)
    {
       ui->statusBar->showMessage("Device Read OK");
       //Get_All_Data();
    }
    else
    {
       ui->statusBar->showMessage("Device Read Error");
    }
}
//-------------------------------------------
void MainWindow::MessageWriteOK(bool mess)
{
    if(mess)
    {
       ui->statusBar->showMessage("Device Write OK");
    }
    else
    {
       ui->statusBar->showMessage("Device Write Error");
    }
}
//-------------------------------------------
void MainWindow:: MessageNotConnected(void)
{
     ui->statusBar->showMessage("Device Not Connected");
}
//-------------------------------------------
void MainWindow::Display_Dev_Info(bool OK,quint16 ID, QString Description)//отобразить информацию об устройстве
{
    if(OK)
    {

    }
    else
    {
        ui->statusBar->showMessage("Info read ERROR");
    }
}
//-------------------------------------------
void MainWindow::on_pushButton_2_clicked()
{
    p_uso->GET_DEV_INFO_REQ(DEV_ADDR);
}
//--------------------------------------------
void MainWindow::on_dev_info_responsed(void)
{
   QString str;
   quint8 i;
   ui->lineEdit_2->setText(p_uso->DEV->device_name);
   ui->lineEdit_3->setText(p_uso->DEV->notice);
   ui->lineEdit_4->setText(str.append(p_uso->DEV->version));
    qDebug()<<str;

    /*for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        ui->tableWidget->removeRow(i);
        qDebug("%i",i);
    }*/
   ui->tableWidget->setRowCount(0);

   for(i=1;i<=p_uso->DEV->channel_num;i++)
   {
       ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(tr("Канал ")+str.setNum(i)));
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem());
 ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 5, new QTableWidgetItem());
       switch(/*p_uso->DEV->channel_type[i-1]>>4&0xF*/p_uso->DEV->channel_mas[i-1]->channel_type>>4&0xF)
       {
       case 0x0:
           {
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(tr("Аналоговый")));
               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 2,new QComboBox());
               QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 2));
               cmb->addItems(strlist);
               cmb->setCurrentIndex(p_uso->DEV->channel_mas[i-1]->state_byte1&0xF);

               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 3,new QSpinBox());
               QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 3));

               spin->setMaximum(255);
               spin->setMinimum(3);
               spin->setValue(p_uso->DEV->channel_mas[i-1]->state_byte2);


           }
           break;
       case 0x1:
           {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(tr("ДОЛ")));
           }
           break;
       case 0x2:
           {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(tr("Дискретный")));
           }
           break;

       default:
           {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(tr("Неизвестный")));
           }
           break;
       }

      // tableWidget->setItem(0, 1, new QTableWidgetItem(query.value(1).toDateTime().toString()));
      // tableWidget->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
      // tableWidget->setItem(0, 3, new QTableWidgetItem(query.value(3).toString()));
       ui->tableWidget->setRowHeight(ui->tableWidget->rowCount()-1, 20);
   }

    ActivateInterface();
   ui->action_SAVE->setVisible(true);
   ui->action_LOAD->setVisible(true);
    return;
}
//--------------------------------------------
void MainWindow::on_dev_get_data_responsed(void)
{
    QString str;
    for(quint8 i=0;i<p_uso->DEV->channel_num;i++)
    {
        //ui->tableWidget->setItem(i, 4, new QTableWidgetItem(str.setNum(p_uso->DEV->channel_mas[i]->channel_data)));//тормозит
            ui->tableWidget->item(i,4)->setText(str.setNum(p_uso->DEV->channel_mas[i]->channel_data));
            //str.setNum(p_uso->DEV->channel_mas[i]->channel_data, 16);
            str.setNum(p_uso->DEV->channel_mas[i]->channel_data, 16);


        if((p_uso->DEV->channel_mas[i]->channel_type>>4&0xF)==0x0)
        {
           QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 2));
           cmb->setCurrentIndex(p_uso->DEV->channel_mas[i]->state_byte1&0xF);

           QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, 3));
           spin->setValue((quint8)p_uso->DEV->channel_mas[i]->state_byte2);

           ui->tableWidget->item(i,5)->setText(/*QString::number(p_uso->DEV->channel_mas[i]->channel_data, 16)*/str.rightJustified(6,'0').toUpper());

        }
        else//получим информацию по дискретным каналам
        {
            ui->tableWidget->item(i,5)->setText(/*QString::number(p_uso->DEV->channel_mas[i]->channel_data, 16)*/str.rightJustified(2,'0').toUpper());


        }
    }
    //--------------------------------------------------
        ui->checkBox_2->setChecked(p_uso->DEV->channel_mas[8]->channel_data&0b10000000);
        ui->checkBox_3->setChecked(p_uso->DEV->channel_mas[8]->channel_data&0b01000000);
        ui->checkBox_4->setChecked(p_uso->DEV->channel_mas[8]->channel_data&0b00100000);
        ui->checkBox_5->setChecked(p_uso->DEV->channel_mas[8]->channel_data&0b00010000);
        ui->checkBox_6->setChecked(p_uso->DEV->channel_mas[8]->channel_data&0b00001000);
        ui->checkBox_7->setChecked(p_uso->DEV->channel_mas[8]->channel_data&0b00000100);
        ui->checkBox_8->setChecked(p_uso->DEV->channel_mas[8]->channel_data&0b00000010);
        ui->checkBox_9->setChecked(p_uso->DEV->channel_mas[8]->channel_data&0b00000001);
    //--------------------------------------------------
        ui->checkBox_10->setChecked(p_uso->DEV->channel_mas[9]->channel_data&0b10000000);
        ui->checkBox_11->setChecked(p_uso->DEV->channel_mas[9]->channel_data&0b01000000);
        ui->checkBox_12->setChecked(p_uso->DEV->channel_mas[9]->channel_data&0b00100000);
        ui->checkBox_13->setChecked(p_uso->DEV->channel_mas[9]->channel_data&0b00010000);
        ui->checkBox_14->setChecked(p_uso->DEV->channel_mas[9]->channel_data&0b00001000);
        ui->checkBox_15->setChecked(p_uso->DEV->channel_mas[9]->channel_data&0b00000100);
        ui->checkBox_16->setChecked(p_uso->DEV->channel_mas[9]->channel_data&0b00000010);
        ui->checkBox_17->setChecked(p_uso->DEV->channel_mas[9]->channel_data&0b00000001);
        //--------------------------------------------------
        ui->checkBox_18->setChecked(p_uso->DEV->channel_mas[10]->channel_data&0b10000000);
        ui->checkBox_19->setChecked(p_uso->DEV->channel_mas[10]->channel_data&0b01000000);
        ui->checkBox_20->setChecked(p_uso->DEV->channel_mas[10]->channel_data&0b00100000);
        ui->checkBox_21->setChecked(p_uso->DEV->channel_mas[10]->channel_data&0b00010000);
        ui->checkBox_22->setChecked(p_uso->DEV->channel_mas[10]->channel_data&0b00001000);
        ui->checkBox_23->setChecked(p_uso->DEV->channel_mas[10]->channel_data&0b00000100);
        ui->checkBox_24->setChecked(p_uso->DEV->channel_mas[10]->channel_data&0b00000010);
        ui->checkBox_25->setChecked(p_uso->DEV->channel_mas[10]->channel_data&0b00000001);
    return;
}
//-------------------------------------
void MainWindow::Get_All_Data(void)
{

    p_uso->CHANNEL_ALL_GET_DATA_REQ(DEV_ADDR);
    qDebug()<<"DEV_ADDR"<<DEV_ADDR;

 //   timer->stop();
    return;
}
//--------------------------------------
void MainWindow::UnactiveInterface(void)
{
    ui->groupBox->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->action_SAVE->setVisible(false);
    ui->action_LOAD->setVisible(false);
}
//--------------------------------------
void MainWindow::ActivateInterface(void)
{
    ui->groupBox->setEnabled(true);
    ui->groupBox_4->setEnabled(true);
    ui->groupBox_3->setEnabled(true);
}
//--------------------------------------
void MainWindow::on_menu_load_settings_clicked()
{
    QString integer;
    QString s=QFileDialog::getOpenFileName(0,tr("Загрузить настройки"),QString(),tr("Файл настроек (*.uso)") );


    if(s.length()<4)
        return;
    QSettings *settings = new QSettings(/*"settings.conf"*/s,QSettings::IniFormat);
   // settings->clear();

    ui->lineEdit_2->setText(settings->value("device/name","").toString());  //устанавливаем значение
    ui->lineEdit_4->setText(settings->value("device/version","").toString());  //устанавливаем значение
    ui->lineEdit_3->setText(settings->value("device/description","").toString());  //устанавливаем значение

   /* settings->setValue("device/version",ui->lineEdit_4->text());  //устанавливаем значение
    settings->setValue("device/description",ui->lineEdit_3->text());  //устанавливаем значение
    settings->setValue("device/address",ui->spinBox_2->value());  //устанавливаем значение*/

    for(quint8 i=0;i<ui->tableWidget->rowCount();i++)
    {
        if(ui->tableWidget->item(i,1)->text()==tr("Аналоговый")/*i<8*/)
        {
            QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 2));

            cmb->setCurrentIndex(settings->value("channel_"+integer.setNum(i)+"/diapason",0).toInt());

            QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, 3));

            spin->setValue(settings->value("channel_"+integer.setNum(i)+"/filter",3).toInt());
        }
    }
    qDebug() << "SETTINGS LOADED"<< s;
    //settings.close();
}
//---------------------------------------------------
void MainWindow::on_menu_save_settings_clicked()
{
    QString integer;
    QString s=QFileDialog::getSaveFileName(0,tr("Сохранить настройки"),QString(),tr("Файл настроек (*.uso)") );

    if(s.length()<4)
        return;

    QSettings *settings = new QSettings(/*"settings.conf"*/s,QSettings::IniFormat);
    settings->clear();

    settings->setValue("device/name",ui->lineEdit_2->text());  //устанавливаем значение
    settings->setValue("device/version",ui->lineEdit_4->text());  //устанавливаем значение
    settings->setValue("device/description",ui->lineEdit_3->text());  //устанавливаем значение

    for(quint8 i=0;i<ui->tableWidget->rowCount();i++)
    {
        if(ui->tableWidget->item(i,1)->text()==tr("Аналоговый")/*i<8*/)
        {
            QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 2));
            settings->setValue("channel_"+integer.setNum(i)+"/diapason",cmb->currentIndex());
            QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, 3));
            settings->setValue("channel_"+integer.setNum(i)+"/filter",spin->text());
        }
    }

    settings->sync(); //записываем настройки
    qDebug() << "SETTINGS SAVED"<<s;
}
//-----------------------------------------------------
void MainWindow::on_action_2_triggered()//подключить устройство
{
    if(!port->isOpen())
     {
     port->setDeviceName(com_dlg.ui->comboBox->currentText());


     if ( !port->open(AbstractSerial::ReadWrite /*| AbstractSerial::Unbuffered*/) ) {
         qDebug() << "Serial device by default: " << port->deviceName() << " open fail.";
         ui->statusBar->showMessage("Port Open Fail");
         return;
     }
     if (!port->setBaudRate(AbstractSerial::BaudRate57600/*com_dlg.ui->comboBox_2->currentText()*/)) {
         qDebug() << "Set baud rate  error.";
         return;
     };

     if (!port->setDataBits(AbstractSerial::DataBits8)) {
         qDebug() << "Set data bits " <<  AbstractSerial::DataBits8 << " error.";
         return;
     }
     if (!port->setParity(AbstractSerial::ParityNone)) {
         qDebug() << "Set parity " <<  AbstractSerial::ParityNone << " error.";
         return;
     }

    if(com_dlg.ui->radioButton->isChecked())
     {
         if (!port->setStopBits(AbstractSerial::StopBits1)) {
             qDebug() << "Set stop bits " <<  AbstractSerial::StopBits1 << " error.";
             return;
         }
     }
    else
    {
        if (!port->setStopBits(AbstractSerial::StopBits2)) {
            qDebug() << "Set stop bits " <<  AbstractSerial::StopBits2 << " error.";
            return;
        }
    }

     if (!port->setFlowControl(AbstractSerial::FlowControlOff)) {
         qDebug() << "Set flow " <<  AbstractSerial::FlowControlOff << " error.";
         return;
     }

     if (port->openMode() & AbstractSerial::Unbuffered)
         port->setTotalReadConstantTimeout(10);

      //port->setCharIntervalTimeout(int((8*1000000/com_dlg.ui->comboBox_2->currentText().toInt())));

     //ui->pushButton->setText(tr("Отключить"));
     ui->action_2->setText(tr("Отключить"));


      qDebug() << "Serial device : " << port->deviceName() << " opened!!!.";
      qDebug() << "Serial device baudrate : " << port->baudRate() ;
      qDebug() << "Serial device databits : " << port->dataBits() ;
      qDebug() << "Serial device stopbits : " << port->stopBits() ;
      qDebug() << "Serial device flowcontrol : " << port->flowControl() ;

     // ActivateInterface();
      ui->groupBox_4->setEnabled(true);
  }
 else
    {
         port->close();
         ui->action_2->setText(tr("Подключить"));
         UnactiveInterface();
     }
}
//-------------------------------------------------------------------
void MainWindow::on_action_4_triggered()
{

}
//-------------------------------------------------------------------
void MainWindow::on_action_3_triggered()//показать окно настройки i2c
{
    I2C_Dev->show();//
    timer->stop();
    ui->checkBox->setChecked(false);
    //деактивировать окно
}
//-------------------------------------------------------------------
void MainWindow::on_action_5_triggered()//установить параметры каналов
{
    for(quint8 i=0;i<8/*ui->tableWidget->rowCount()p_uso->DEV->channel_num*/;i++)
    {
        if(i<8)//настройки по аналоговым каналам
        {

//            QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 5));
//           if(cmb->currentIndex()==0)
//           {
                chnl[i]->channel_type=0x3;//p_uso->CHN_ADC|0x3;
//           }
//           if(cmb->currentIndex()==1)
//           {
//               chnl[i]->channel_type=0x0;//p_uso->CHN_ADC&0xF0;
//           }

           // chnl[i]->channel_type=p_uso->CHN_ADC;
          QComboBox * cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 2));
            chnl[i]->state_byte1=0x40|cmb->currentIndex();

            QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, 3));
            //spin->setValue((quint8)p_uso->DEV->channel_mas[i]->state_byte2);
            chnl[i]->state_byte2=(quint8)spin->value();
        }
        else//настройки по частотным каналам
        {
           // chnl[i]->channel_type=p_uso->CHN_COUNT;
           // chnl[i]->state_byte1=0x40;//инициализация была
           // chnl[i]->state_byte2=0x0A;//инициализация была
        }

    }
    p_uso->CHANNEL_SET_PARAMETERS_REQ(DEV_ADDR,chnl);
    return;
}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
       timer->start(200);
       ui->groupBox->setEnabled(false);
    }
    else
    {
       timer->stop();
       ui->groupBox->setEnabled(true);
    }

}

void MainWindow::on_pushButton_clicked()//установка дискретных регистров
{
    quint8 port1=0,port2=0;

    port1|=ui->checkBox_17->isChecked();
    port1|=ui->checkBox_16->isChecked()<<1;
    port1|=ui->checkBox_15->isChecked()<<2;
    port1|=ui->checkBox_14->isChecked()<<3;
    port1|=ui->checkBox_13->isChecked()<<4;
    port1|=ui->checkBox_12->isChecked()<<5;
    port1|=ui->checkBox_11->isChecked()<<6;
    port1|=ui->checkBox_10->isChecked()<<7;

    port2|=ui->checkBox_25->isChecked();
    port2|=ui->checkBox_24->isChecked()<<1;
    port2|=ui->checkBox_23->isChecked()<<2;
    port2|=ui->checkBox_22->isChecked()<<3;
    port2|=ui->checkBox_21->isChecked()<<4;
    port2|=ui->checkBox_20->isChecked()<<5;
    port2|=ui->checkBox_19->isChecked()<<6;
    port2|=ui->checkBox_18->isChecked()<<7;

    p_uso->CHANNEL_SET_DISCRET_OUT_REQ(this->DEV_ADDR,port1,port2);

}
//----------------------------------------------
void MainWindow::on_CRC_ERROR(void)//если ошибка crc
{
    QString str;
    CRC_ERROR++;
    ui->label_31->setText(str.setNum(CRC_ERROR));
}

//----------------------------------------------
void MainWindow::on_TIMEOUT_ERROR(void)//если случился таймаут
{
    QString str;
    TIMEOUT_ERROR++;
    ui->label_30->setText(str.setNum(TIMEOUT_ERROR));
}
