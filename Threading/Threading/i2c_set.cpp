#include "i2c_set.h"
#include "ui_i2c_set.h"
#include <QDebug>
#include <QStringList>

I2C_Set::I2C_Set(QWidget *parent, proto_uso *uso) :
    QDialog(parent),
    ui(new Ui::I2C_Set)
{
    ui->setupUi(this);
    p_uso=uso;
    this->parent=parent;
    DEV_ADDR=1;
    timeout_count=0;
    Timer=new QTimer(this);

    connect(p_uso,SIGNAL(MEMORY_READ_BUF_RESPONSED(QByteArray)),this,SLOT(on_MEMORY_READ_BUF(QByteArray)));

    connect(p_uso,SIGNAL(MEMORY_READ_BUF_TIMEOUT()),this,SLOT(on_MEMORY_READ_TIMEOUT()));

    connect(Timer,SIGNAL(timeout()),this,SLOT(Time_Request()));
    connect(p_uso,SIGNAL(I2C_ERROR()),this,SLOT(on_I2C_ERROR()));

    ui->tableWidget->setRowCount(2048);
    ui->tableWidget->setColumnCount(16);

    quint16 i=0;
    QStringList label_list;
    QString temp_str;
    for(i=0;i<16;i++)
    {
        temp_str.setNum(i,16);
        label_list.append(temp_str.toUpper());
    }
    ui->tableWidget->setHorizontalHeaderLabels(label_list);

    label_list.clear();
    for(i=0;i<2048;i++)
    {
        temp_str.setNum((i<<4),16);
        label_list.append(temp_str.rightJustified(4,'0').toUpper());
    }
    ui->tableWidget->setVerticalHeaderLabels(label_list);

    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    I2C_ERROR=0;

    ui->pushButton_4->setEnabled(false);//неактивная кнопка, в этой версии
        connect(p_uso,SIGNAL(TIMER_GET_TIME_RESPONSED(tTime)),this,SLOT(on_TimerGetTime_responsed(tTime)));
}

I2C_Set::~I2C_Set()
{
    delete Timer;
    delete ui;
}

//---------------------------------------------------
void I2C_Set::on_pushButton_3_clicked()//сгрузим память
{
    p_uso->MEMORY_READ_BUF_REQ(DEV_ADDR,0,MEM_PAGE_LEN);
    ui->progressBar->setValue(0);
    MEM_COUNTER=MEM_PAGE_LEN;
    //ui->tableWidget->clear();
    ui->tableWidget->clearContents();
    timeout_count=0;
    ui->groupBox->setEnabled(false);
}

void I2C_Set::on_MEMORY_READ_BUF(QByteArray buf)//слот принятых данных
{
QString str;
qDebug()<<"RESPONSE OK";
timeout_count=0;
    ui->progressBar->setValue((quint8)(100*((float)MEM_COUNTER/MEM_LEN)));
    for(quint16 i=0;i<MEM_PAGE_LEN;i++)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem( str.setNum((quint8)buf[i],16).rightJustified(2,'0').toUpper() );
        ui->tableWidget->setItem( (MEM_COUNTER/MEM_PAGE_LEN-1), i, newItem );
    }

    if(MEM_COUNTER<(MEM_LEN-1))
    {
        p_uso->MEMORY_READ_BUF_REQ(DEV_ADDR,MEM_COUNTER,MEM_PAGE_LEN);

        qDebug()<<"MEM REQUEST "<<MEM_COUNTER;
        MEM_COUNTER+=MEM_PAGE_LEN;
    }
    else
    {
        qDebug()<<"MEM_COUNTER_OVERLOAD";
        ui->groupBox->setEnabled(true);
    }
}
//--------------------------------------------------
void I2C_Set::on_MEMORY_READ_TIMEOUT(void)
{
    if(timeout_count>MAX_TIMEOUT)//превысило количество таймаутов
    {
        ui->groupBox->setEnabled(true);
        return;
    }
     //MEM_COUNTER-= MEM_PAGE_LEN;
     p_uso->MEMORY_READ_BUF_REQ(DEV_ADDR,(MEM_COUNTER-MEM_PAGE_LEN),MEM_PAGE_LEN);
     timeout_count++;
}
//---------------------------------------------------
//void I2C_Set::on_pushButton_clicked()//получим время
//{
//    p_uso->TIMER_GET_TIME_REQ(DEV_ADDR);
//}

void I2C_Set::on_TimerGetTime_responsed(tTime Time)//получили время
{
    QDate date;
    QTime time;
qDebug()<<"TIMER GET RESP";
    time.setHMS(((Time.Hour&0xF)+10*((Time.Hour>>4)&0xF)),((Time.Minute&0xF)+10*((Time.Minute>>4)&0xF)),((Time.Second&0xF)+10*((Time.Second>>4)&0xF)));
    date.setDate(((Time.Year&0xF)+10*((Time.Year>>4)&0xF)+2000),((Time.Month&0xF)+10*((Time.Month>>4)&0xF)),((Time.Day&0xF)+10*((Time.Day>>4)&0xF)));
    qDebug()<<time.toString("hh.mm.ss");
    qDebug()<<date.toString("dd.MM.yyyy");
    ui->dateTimeEdit->setTime(time);
    ui->dateTimeEdit->setDate(date);
    ui->comboBox->setCurrentIndex((Time.WeekDay-1)&0x7);

    //--------------------------------------------------
         ui->checkBox_9->setChecked(Time.Flags&0b10000000);
        ui->checkBox_10->setChecked(Time.Flags&0b01000000);
        ui->checkBox_11->setChecked(Time.Flags&0b00100000);
        ui->checkBox_12->setChecked(Time.Flags&0b00010000);
        ui->checkBox_13->setChecked(Time.Flags&0b00001000);
        ui->checkBox_14->setChecked(Time.Flags&0b00000100);
        ui->checkBox_15->setChecked(Time.Flags&0b00000010);
        ui->checkBox_16->setChecked(Time.Flags&0b00000001);
    //--------------------------------------------------
         ui->checkBox->setChecked(Time.Calibr&0b10000000);
       ui->checkBox_2->setChecked(Time.Calibr&0b01000000);
       ui->checkBox_3->setChecked(Time.Calibr&0b00100000);
       ui->checkBox_4->setChecked(Time.Calibr&0b00010000);
       ui->checkBox_5->setChecked(Time.Calibr&0b00001000);
       ui->checkBox_6->setChecked(Time.Calibr&0b00000100);
       ui->checkBox_7->setChecked(Time.Calibr&0b00000010);
       ui->checkBox_8->setChecked(Time.Calibr&0b00000001);
}
//----------------------------------------------------

void I2C_Set::on_pushButton_2_clicked()//установить время
{
    tTime nTime;
    QDate date;
    QTime time;

    date=ui->dateTimeEdit->date();
    time=ui->dateTimeEdit->time();

    nTime.Second=(time.second()%10)|((time.second()/10)<<4);
    nTime.Minute=(time.minute()%10)|((time.minute()/10)<<4);
    nTime.Hour  =(time.hour()%10)|((time.hour()/10)<<4);

    nTime.Day=(date.day()%10)|((date.day()/10)<<4);
    nTime.Month=(date.month()%10)|((date.month()/10)<<4);

    nTime.WeekDay=ui->comboBox->currentIndex()+1;

    quint16 year=0;
    year=date.year()%100;

    nTime.Year  =(year%10)|((year/10)<<4);

    nTime.Flags|=ui->checkBox_16->isChecked();
    nTime.Flags|=ui->checkBox_15->isChecked()<<1;
    nTime.Flags|=ui->checkBox_14->isChecked()<<2;
    nTime.Flags|=ui->checkBox_13->isChecked()<<3;
    nTime.Flags|=ui->checkBox_12->isChecked()<<4;
    nTime.Flags|=ui->checkBox_11->isChecked()<<5;
    nTime.Flags|=ui->checkBox_10->isChecked()<<6;
    nTime.Flags|=ui->checkBox_9->isChecked()<<7;

    nTime.Calibr|=ui->checkBox_8->isChecked();
    nTime.Calibr|=ui->checkBox_7->isChecked()<<1;
    nTime.Calibr|=ui->checkBox_6->isChecked()<<2;
    nTime.Calibr|=ui->checkBox_5->isChecked()<<3;
    nTime.Calibr|=ui->checkBox_4->isChecked()<<4;
    nTime.Calibr|=ui->checkBox_3->isChecked()<<5;
    nTime.Calibr|=ui->checkBox_2->isChecked()<<6;
    nTime.Calibr|=ui->checkBox->isChecked()<<7;

  //  qDebug()<<nTime.Calibr;
    p_uso->TIMER_SET_TIME_REQ(DEV_ADDR,nTime);
}
//----------------------------------------------
void I2C_Set::Time_Request(void)//запросить время
{
    p_uso->TIMER_GET_TIME_REQ(DEV_ADDR);
}
//----------------------------------------------
void I2C_Set::on_checkBox_17_clicked()//включить опрос времени
{
    if(ui->checkBox_17->isChecked())
    {
        ui->groupBox_4->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        Timer->start(200);

    }
    else
    {
        Timer->stop();
        ui->groupBox_4->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
    }
}
//------------------------------------------------
void I2C_Set::closeEvent(QCloseEvent *)
{
        Timer->stop();

        MEM_COUNTER=MEM_LEN;
        ui->groupBox_4->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->checkBox_17->setChecked(false);
}
//-------------------------------------------------
void I2C_Set::on_I2C_ERROR(void)
{
    QString str;
    I2C_ERROR++;
    ui->label_18->setText(str.setNum(I2C_ERROR));
}

