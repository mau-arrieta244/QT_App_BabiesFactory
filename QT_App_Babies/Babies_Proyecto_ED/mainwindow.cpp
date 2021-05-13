#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"estructuraspedido.h"
#include<QFile>
#include <QStringList>
#include<QMessageBox>

#include<fstream>
#include<dirent.h>
#include<cstdio>
#include<sstream>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listaGlobal = new estructurasPedido::ListaPedidosEspeciales;
    colaGlobal = new estructurasPedido::ColaPedidos;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//////////////////////////////////////////////////////////////
//     Funciones "sueltas" (no pertenecen a ningun struct)  //
//////////////////////////////////////////////////////////////


//prueba, para ver como accesar a estas funciones desde botones
// QString algo = this -> easy();
QString MainWindow::easy()
{
    QStringList a = {"a","b","c"};
    return a[0];
}



QString MainWindow::colorPapa(QString nombreArchivo){
        QFile file(nombreArchivo);

        if(file.open(QFile::ReadOnly |QFile::Text)){
            QTextStream in(&file);
            QString contenido = in.readAll();

            //genera una lista donde el caracter separa string
            // colores = { tipoPadre , tipoMadre}
            QStringList colores = contenido.split(';');

            QString tipoPadre = colores[0];
            file.close();
            return tipoPadre;
        }

}

int MainWindow::longitudPapa(QString nombreArchivo){
    QString tipoPadre = MainWindow::colorPapa(nombreArchivo);
    return tipoPadre.length();
}

//ya no ocupa longitudPadre! modificarlo despues...
QString MainWindow::colorMama(QString nombreArchivo,int longitudPadre){
    QFile file(nombreArchivo);

    if(file.open(QFile::ReadOnly |QFile::Text)){
        QTextStream in(&file);
        QString contenido = in.readAll();

        //genera una lista donde el caracter separa string
        // colores = { tipoPadre , tipoMadre}

        //con doble comilla o single comilla???
        QStringList colores = contenido.split(';');


        QString tipoMadre = colores[1];
        file.close();
        return tipoMadre;
    }



}


QString MainWindow::checkPathString(QString path){
    if(path[path.length()-1] == '/'){
            path = path.remove(path.length()-1,1);
        }
    return path;
}

void MainWindow::listdir(QString initStrPath,
         estructurasPedido::ColaPedidos * cola,
         estructurasPedido::ListaPedidosEspeciales * lista)
{
    struct dirent * dir;
        //siguiente linea puede o puede no dar problemas...
        DIR * dp = opendir(initStrPath.toStdString().c_str());

        if(dp){
            while((dir = readdir(dp))!=NULL){
                QString strPath ="";
                if(strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0)continue;

                else{

                    initStrPath = checkPathString(initStrPath);
                    strPath = initStrPath+"/"+dir->d_name;
                    //cout<<strPath<<endl;
                    //cout<<"\n ------ \n"<<endl;
                    QString cP =colorPapa(strPath);
                    int lenPadre = longitudPapa(strPath);
                    QString cM = colorMama(strPath,lenPadre); // recibe len de tipo padre para cortar string a partir de ahi

                    /// !!!!!!!!
                    estructurasPedido::Padres * p1 = new estructurasPedido::Padres(cP,cM);
                    QString colorHijo = p1->probabilidadHijo();
                    //estructurasPedido::Bebe * b1 = new estructurasPedido::Bebe(colorHijo);

                    //cola->encolarBebe(b1);
                    //cola->imprimir();

                    //NodoHistorico * n1 = new NodoHistorico(cM,cP,colorHijo);


                    //!!!!!
                    lista->insertarAlFinal(cM,cP,colorHijo); // crea nuevo nodo y lo mete a la lista


                    listdir(strPath,cola,lista);
                    const int result = remove(strPath.toStdString().c_str());
                    //cout<<"\n ------ \n"<<endl;

                }
            }
            closedir(dp);
        }
}


//////////////////////////////////////////////////////////////////////////////////
//                    Funciones de los botones              //////////////////////
//////////////////////////////////////////////////////////////////////////////////



void MainWindow::on_desplegar_clicked()
{
    QString cantidad = QString::number(listaGlobal->cantidadBebes);

    this->ui->label->setText(cantidad);
}

void MainWindow::on_listdir_clicked()
{
    listdir("C:\\Users\\mauar\\Desktop\\CODE\\Proyecto_ED_BabiesFactory\\pedidosEspeciales",colaGlobal,listaGlobal);
}
