
#include<QtCore>
#include "hilopedidos.h"

hiloPedidos::hiloPedidos()
{

}


void hiloPedidos::__init__(){
    this->running=true;
    this->valor = 1;
}

void hiloPedidos::run(){
    QMutex mutex;
    while(this->running)
    {
        qDebug()<<valor<<" \n";
        sleep(1);
        mutex.lock();
        valor++;
        mutex.unlock();
    }
    sleep(1);
}

void hiloPedidos::detener(){
    this->running = false;
}


void hiloPedidos::continuar(){
    this->running = true;
}
