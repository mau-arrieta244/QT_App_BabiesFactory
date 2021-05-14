#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"estructuraspedido.h"
#include"hilopedidos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //globales
    estructurasPedido::ListaPedidosEspeciales * listaGlobal;
    estructurasPedido::ColaPedidos*colaGlobal;

    //Declaracion de funciones "sueltas" (no pertenecen a un struct)
    QString colorPapa(QString nombreArchivo);
    int longitudPapa(QString nombreArchivo);
    QString colorMama(QString nombreArchivo,int longitudPadre);
    QString checkPathString(QString path);
    void listdir(QString initStrPath,
                 estructurasPedido::ColaPedidos * cola,
                 estructurasPedido::ListaPedidosEspeciales * lista);
    QString easy();

    //Hilos
    hiloPedidos hilo1;


private slots:
    void on_desplegar_clicked();

    void on_listdir_clicked();

    void on_botonInicioPedidos_clicked();

    void on_botonDetenerPedidos_clicked();

    void on_botonContinuarPedidos_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
