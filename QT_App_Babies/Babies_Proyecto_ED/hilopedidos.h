#ifndef HILOPEDIDOS_H
#define HILOPEDIDOS_H

#include <QThread>

class hiloPedidos : public QThread
{
public:
    hiloPedidos();

    int valor;

    bool running;

    void __init__();

    void run();
    void detener();
    void continuar();
    //void stop();

};

#endif // HILOPEDIDOS_H
