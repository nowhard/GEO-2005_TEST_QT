#ifndef INPUT_THREAD_H
#define INPUT_THREAD_H

#include <QThread>
#include <QByteArray>
#include <abstractserial.h>
#include <QDebug>
#include <QTimer>
#include "proto_uso.h"

class Input_Thread : public QThread
{
    Q_OBJECT
public:
    explicit Input_Thread(QObject *parent,AbstractSerial *port, proto_uso *uso);
    ~Input_Thread();
    void run();
    QByteArray ba;

signals:
    void isRead(QByteArray data);
    void ReadOK(bool ok);

public slots:
private slots:
    void ReadPort(void);

private:
    AbstractSerial *port;
    enum {MIN_PACK_LENGTH=0x5};
    quint8 Recieve_Count;//счетчик принятых
    QTimer *Timeout;
    proto_uso *p_uso;

};

#endif // INPUT_THREAD_H
