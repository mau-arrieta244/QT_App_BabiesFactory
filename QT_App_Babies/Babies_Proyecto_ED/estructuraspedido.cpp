#include "estructuraspedido.h"
#include<QDebug>

#include<fstream>
#include<dirent.h>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
estructurasPedido::estructurasPedido(QObject *parent) : QObject(parent)
{
 // definir los atributos (si tuviera )
}

void estructurasPedido::Bebe::imprimirPiel(){
    qDebug()<<" color de piel: "<<Bebe::colorPiel;
}

//Nodos para colaPedidos , los nodos seran bebes que estan a la espera
//de pasar a la cola de produccion

void estructurasPedido::ColaPedidos::encolarBebe (Bebe * b){
        if (vacia())
           frente = new NodoBebe (b);
        else
            {
            // referencia al primero para recorrer la lista
            NodoBebe* actual = frente;
            // recorre la lista hasta llegar al ultimo nodo
            while (actual->siguiente != NULL){
               actual = actual->siguiente;
             }
               // Crea nuevo nodo, lo apunta con uN
               NodoBebe* nuevo = new NodoBebe (b);
               //le quita el enlace al que era ultimo
               actual->siguiente = nuevo;
            }
       }

estructurasPedido::NodoBebe * estructurasPedido::ColaPedidos::desencolar()
       {
      // si no hay elementos, no borra nada, retorna null
      if (vacia())
      {
         return NULL;
      }
      else
            {
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          NodoBebe* borrado = frente;
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          frente = frente->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          return borrado;
            }
       }

bool estructurasPedido::ColaPedidos::vacia()
    {
     if (frente == NULL)
        return true;
     else
         return false;
    }

void estructurasPedido::ColaPedidos::imprimir()
    {
     qDebug() << "Frente" ;
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     NodoBebe *tmp = frente;

     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           // imprime el dato del nodo en el que esta tmp
           qDebug() << tmp->bebe->colorPiel << "  " ;
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     qDebug() << "Final";
    }


    estructurasPedido::NodoBebe* estructurasPedido::ColaPedidos::verFrente()
        {
            return frente;
        }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////// lista pedidos especiales ////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    //lista doble para guardar historico de los pedidos especiales


        bool estructurasPedido::ListaPedidosEspeciales::isEmpty(){
            return primerNodo == NULL;
        }

        void estructurasPedido::ListaPedidosEspeciales::insertar (QString infoMama,QString infoPapa,QString infoHijo){
            if (isEmpty())
                primerNodo = ultimoNodo = new NodoHistorico(infoMama,infoPapa,infoHijo);
            else{
                primerNodo->anterior = new NodoHistorico(infoMama,infoPapa,infoHijo);
                primerNodo->anterior->siguiente = primerNodo;
                primerNodo = primerNodo->anterior;
            }
            //
            ListaPedidosEspeciales::cantidadBebes++;
        }

        void estructurasPedido::ListaPedidosEspeciales::insertarAlFinal(QString infoMama,QString infoPapa,QString infoHijo){
            if (isEmpty())
                primerNodo = ultimoNodo = new NodoHistorico(infoMama,infoPapa,infoHijo);
            else{
                ultimoNodo->siguiente = new NodoHistorico(infoMama,infoPapa,infoHijo);
                ultimoNodo->siguiente->anterior = ultimoNodo;
                ultimoNodo = ultimoNodo->siguiente;
            }
            ListaPedidosEspeciales::cantidadBebes++;
            //cantidadBebes++;
        }

        void estructurasPedido::ListaPedidosEspeciales::imprimir(bool inverted){
            if (inverted){
                NodoHistorico * tmp = ultimoNodo;
                while(tmp != NULL){
                    qDebug() << tmp->colorPadre<< " "<<tmp ->colorMadre<<" "<< tmp->tipoBebe<< " -> ";
                    tmp = tmp->anterior;
                }
            }
            else{
                NodoHistorico * tmp = primerNodo;
                while(tmp != NULL){
                    qDebug() << tmp->colorPadre<< " "<<tmp ->colorMadre<<" "<< tmp->tipoBebe<< " -> ";
                    tmp = tmp->siguiente;
                }
            }
            qDebug()<< " " ; // originalmente era un endl;
        }

        //borrar al inicio: si esta vacia retorna null
        estructurasPedido::NodoHistorico * estructurasPedido::ListaPedidosEspeciales::borrar(){
            NodoHistorico * borrado = primerNodo;
            if (!isEmpty() && primerNodo == ultimoNodo)
                primerNodo = ultimoNodo = NULL;
            else if (!isEmpty()){
                primerNodo = primerNodo->siguiente;
                primerNodo->anterior = borrado->siguiente = NULL;
            }
            return borrado;
        }

        estructurasPedido::NodoHistorico * estructurasPedido::ListaPedidosEspeciales::borrarAlFinal(){
            NodoHistorico * borrado = ultimoNodo;
            if (!isEmpty() && primerNodo == ultimoNodo)
                primerNodo = ultimoNodo = NULL;
            else if (!isEmpty()){
                ultimoNodo = ultimoNodo->anterior;
                ultimoNodo->siguiente = borrado->anterior = NULL;
            }
            return borrado;
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////          PADRES          ////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        QString estructurasPedido::Padres::probabilidadHijo(){
                srand(time(nullptr));
                int aleatorio = rand() %100+1;
                //cout<<"random : "<<aleatorio<<endl;

                //hay 64 combinaciones... muchos ifs, elifs!

                //preguntarle bien al profe de manera de escribir castano , BadBunny, etc..

                // columna 1 /////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////
                if(tipoPadre == "Moreno" & tipoMadre == "Morena"){
                    return "Moreno";
                }

                else if(tipoPadre == "Afro" & tipoMadre == "Morena"){
                    if(aleatorio<=70){
                        return "Afro";
                    }
                    else{
                        return "Moreno";
                    }
                }

                else if(tipoPadre == "Rubio" & tipoMadre == "Morena"){
                    if(aleatorio<=90){
                        return "Moreno";
                    }
                    else{
                        return "Rubio";
                    }
                }

                else if(tipoPadre == "Castano" & tipoMadre == "Morena"){
                    if(aleatorio<=50){
                        return "Castano";
                    }
                    else{
                        return "Moreno";
                    }
                }

                else if(tipoPadre == "Pelirrojo" & tipoMadre == "Morena"){
                    if(aleatorio<=10){
                        return "Pelirrojo";
                    }
                    else{
                        return "Moreno";
                    }
                }

                else if(tipoPadre == "Pink" & tipoMadre == "Morena"){
                    return "Moreno";
                }

                else if(tipoPadre == "BadBunny" & tipoMadre == "Morena"){
                    if(aleatorio<=10){
                        return "BadBunny";
                    }
                    else{
                        return "Moreno";
                    }
                }

                else if(tipoPadre == "Pitufo" & tipoMadre == "Morena"){
                    if(aleatorio<=10){
                        return "Pitufo";
                    }
                    else{
                        return "Moreno";
                    }
                }

                // columna 2 /////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////

                else if(tipoPadre == "Moreno" & tipoMadre == "Afro"){
                    if(aleatorio<=30){
                        return "Moreno";
                    }
                    else{
                        return "Afro";
                    }
                }

                else if(tipoPadre == "Afro" & tipoMadre == "Afro"){
                    return "Afro";
                }

                else if(tipoPadre == "Rubio" & tipoMadre == "Afro"){
                    return "Afro";
                }

                else if(tipoPadre == "Castano" & tipoMadre == "Afro"){
                    return "Afro";
                }

                else if(tipoPadre == "Pelirrojo" & tipoMadre == "Afro"){
                    return "Afro";
                }

                else if(tipoPadre == "Pink" & tipoMadre == "Afro"){
                    return "Afro";
                }

                else if(tipoPadre == "BadBunny" & tipoMadre == "Afro"){
                    return "Afro";
                }

                else if(tipoPadre == "Pitufo" & tipoMadre == "Afro"){
                    return "Afro";
                }

                // columna 3 /////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////
                else if(tipoPadre == "Moreno" & tipoMadre == "Rubia"){
                    if(aleatorio<=70){
                        return "Moreno";
                    }
                    else{
                        return "Rubia";
                    }
                }

                else if(tipoPadre == "Afro" & tipoMadre == "Rubia"){
                    if(aleatorio<=90){
                        return "Afro";
                    }
                    else{
                        return "Rubia";
                    }
                }

                else if(tipoPadre == "Rubio" & tipoMadre == "Rubia"){
                    return "Rubio";
                }

                else if(tipoPadre == "Castano" & tipoMadre == "Rubia"){
                    if(aleatorio<=90){
                        return "Rubio";
                    }
                    else{
                        return "Castano";
                    }
                }

                else if(tipoPadre == "Pelirrojo" & tipoMadre == "Rubia"){
                    if(aleatorio<=90){
                        return "Rubio";
                    }
                    else{
                        return "Pelirrojo";
                    }
                }

                else if(tipoPadre == "Pink" & tipoMadre == "Rubia"){
                    return "Rubia";
                }

                else if(tipoPadre == "BadBunny" & tipoMadre == "Rubia"){
                    return "Rubia";
                }

                else if(tipoPadre == "Pitufo" & tipoMadre == "Rubia"){
                    return "Rubia";
                }

                // columna 4 /////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////

                else if(tipoPadre == "Moreno" & tipoMadre == "Castana"){
                    if(aleatorio<=50){
                        return "Moreno";
                    }
                    else{
                        return "Castano";
                    }
                }

                else if(tipoPadre == "Afro" & tipoMadre == "Castana"){
                    if(aleatorio<=70){
                        return "Afro";
                    }
                    else{
                        return "Castano";
                    }
                }

                else if(tipoPadre == "Rubio" & tipoMadre == "Castana"){
                    if(aleatorio<=40){
                        return "Rubio";
                    }
                    else{
                        return "Castano";
                    }
                }

                else if(tipoPadre == "Castano" & tipoMadre == "Castana"){
                    return "Castano";
                }

                else if(tipoPadre == "Pelirrojo" & tipoMadre == "Castana"){
                    if(aleatorio<=40){
                        return "Pelirrojo";
                    }
                    else{
                        return "Castano";
                    }
                }

                else if(tipoPadre == "Pink" & tipoMadre == "Castana"){
                    if(aleatorio<=30){
                        return "Pink";
                    }
                    else{
                        return "Castano";
                    }
                }

                else if(tipoPadre == "BadBunny" & tipoMadre == "Castana"){
                    if(aleatorio<=50){
                        return "BadBunny";
                    }
                    else{
                        return "Castano";
                    }
                }

                else if(tipoPadre == "Pitufo" & tipoMadre == "Castana"){
                    if(aleatorio<=30){
                        return "Pitufo";
                    }
                    else{
                        return "Castano";
                    }
                }

                // columna 5 /////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////

                else if(tipoPadre == "Moreno" & tipoMadre == "Pelirroja"){
                    if(aleatorio<=65){
                        return "Moreno";
                    }
                    else{
                        return "Pelirrojo";
                    }
                }

                else if(tipoPadre == "Afro" & tipoMadre == "Pelirroja"){
                    if(aleatorio<=85){
                        return "Afro";
                    }
                    else{
                        return "Pelirrojo";
                    }
                }

                else if(tipoPadre == "Rubio" & tipoMadre == "Pelirroja"){
                    if(aleatorio<=40){
                        return "Rubio";
                    }
                    else{
                        return "Pelirrojo";
                    }
                }

                else if(tipoPadre == "Castano" & tipoMadre == "Pelirroja"){
                    if(aleatorio<=40){
                        return "Castano";
                    }
                    else{
                        return "Pelirrojo";
                    }
                }

                else if(tipoPadre == "Pelirrojo" & tipoMadre == "Pelirroja"){
                    return "Pelirrojo";
                }

                else if(tipoPadre == "Pink" & tipoMadre == "Pelirroja"){
                    if(aleatorio<=25){
                        return "Pink";
                    }
                    else{
                        return "Pelirrojo";
                    }
                }

                else if(tipoPadre == "BadBunny" & tipoMadre == "Pelirroja"){
                    if(aleatorio<=40){
                        return "BadBunny";
                    }
                    else{
                        return "Pelirrojo";
                    }
                }

                else if(tipoPadre == "Pitufo" & tipoMadre == "Pelirroja"){
                    if(aleatorio<=30){
                        return "Pitufo";
                    }
                    else{
                        return "Pelirrojo";
                    }
                }


                // columna 6 /////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////

                else if(tipoPadre == "Moreno" & tipoMadre == "Pink"){
                    if(aleatorio<=90){
                        return "Moreno";
                    }
                    else{
                        return "Pink";
                    }
                }

                else if(tipoPadre == "Afro" & tipoMadre == "Pink"){
                    if(aleatorio<=100){
                        return "Afro";
                    }
                    else{
                        return "Pink";
                    }
                }

                else if(tipoPadre == "Rubio" & tipoMadre == "Pink"){
                    if(aleatorio<=70){
                        return "Rubio";
                    }
                    else{
                        return "Pink";
                    }
                }

                else if(tipoPadre == "Castano" & tipoMadre == "Pink"){
                    if(aleatorio<=40){
                        return "Castano";
                    }
                    else{
                        return "Pink";
                    }
                }

                else if(tipoPadre == "Pelirrojo" & tipoMadre == "Pink"){
                    if(aleatorio<=65){
                        return "Pelirrojo";
                    }
                    else{
                        return "Pink";
                    }
                }

                else if(tipoPadre == "Pink" & tipoMadre == "Pink"){
                    return "Pink";
                }

                else if(tipoPadre == "BadBunny" & tipoMadre == "Pink"){
                    if(aleatorio<=40){
                        return "BadBunny";
                    }
                    else{
                        return "Pink";
                    }
                }

                else if(tipoPadre == "Pitufo" & tipoMadre == "Pink"){
                    if(aleatorio<=45){
                        return "Pitufo";
                    }
                    else{
                        return "Pink";
                    }
                }


                // columna 7 /////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////

                else if(tipoPadre == "Moreno" & tipoMadre == "BadBunny"){
                    if(aleatorio<=70){
                        return "Moreno";
                    }
                    else{
                        return "BadBunny";
                    }
                }

                else if(tipoPadre == "Afro" & tipoMadre == "BadBunny"){
                    if(aleatorio<=70){
                        return "Afro";
                    }
                    else{
                        return "BadBunny";
                    }
                }

                else if(tipoPadre == "Rubio" & tipoMadre == "BadBunny"){
                    if(aleatorio<=45){
                        return "Rubio";
                    }
                    else{
                        return "BadBunny";
                    }
                }

                else if(tipoPadre == "Castano" & tipoMadre == "BadBunny"){
                    if(aleatorio<=55){
                        return "Castano";
                    }
                    else{
                        return "BadBunny";
                    }
                }

                else if(tipoPadre == "Pelirrojo" & tipoMadre == "BadBunny"){
                    if(aleatorio<=70){
                        return "Pelirrojo";
                    }
                    else{
                        return "BadBunny";
                    }
                }

                else if(tipoPadre == "Pink" & tipoMadre == "BadBunny"){
                    if(aleatorio<=50){
                        return "Pink";
                    }
                    else{
                        return "BadBunny";
                    }
                }

                else if(tipoPadre == "BadBunny" & tipoMadre == "BadBunny"){
                    return "BadBunny";
                }

                else if(tipoPadre == "Pitufo" & tipoMadre == "BadBunny"){
                    if(aleatorio<=50){
                        return "Pitufo";
                    }
                    else{
                        return "BadBunny";
                    }
                }


                // columna 8 /////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////

                else if(tipoPadre == "Moreno" & tipoMadre == "Pitufa"){
                    if(aleatorio<=15){
                        return "Moreno";
                    }
                    else{
                        return "Pitufa";
                    }
                }

                else if(tipoPadre == "Afro" & tipoMadre == "Pitufa"){
                    if(aleatorio<=50){
                        return "Afro";
                    }
                    else{
                        return "Pitufa";
                    }
                }

                else if(tipoPadre == "Rubio" & tipoMadre == "Pitufa"){
                    if(aleatorio<=15){
                        return "Rubio";
                    }
                    else{
                        return "Pitufa";
                    }
                }

                else if(tipoPadre == "Castano" & tipoMadre == "Pitufa"){
                    if(aleatorio<=20){
                        return "Castano";
                    }
                    else{
                        return "Pitufa";
                    }
                }

                else if(tipoPadre == "Pelirrojo" & tipoMadre == "Pitufa"){
                    if(aleatorio<=40){
                        return "Pelirrojo";
                    }
                    else{
                        return "Pitufa";
                    }
                }

                else if(tipoPadre == "Pink" & tipoMadre == "Pitufa"){
                    if(aleatorio<=50){
                        return "Pink";
                    }
                    else{
                        return "Pitufa";
                    }
                }

                else if(tipoPadre == "BadBunny" & tipoMadre == "Pitufa"){
                    if(aleatorio<=50){
                        return "BadBunny";
                    }
                    else{
                        return "Pitufa";
                    }
                }

                else if(tipoPadre == "Pitufo" & tipoMadre == "Pitufa"){
                    return "Pitufo";
                }


                return "Default / Fallo";

            }
