#ifndef ESTRUCTURASPEDIDO_H
#define ESTRUCTURASPEDIDO_H

#include <QObject>
#include<QString>

//contiene declaraciones de todas las estructuras necesarias para Pedidos Especiales...
class estructurasPedido : public QObject
{
    Q_OBJECT
public:
    explicit estructurasPedido(QObject *parent = nullptr);


    struct Padres{

        QString tipoPadre;
        QString tipoMadre;

        Padres(){
            tipoPadre = "";
            tipoMadre = "";
        }
        Padres(QString colorPadre , QString colorMadre){
            tipoPadre = colorPadre;
            tipoMadre = colorMadre;
        }
        QString probabilidadHijo();
    };

    struct Bebe{

        QString amor;
        QString arte;
        QString hate;

        QString colorPiel;
        bool bebeMalo;
        //constructor default
        Bebe(){
            amor = "";
            arte = "";
            hate = "";
            colorPiel = "";
            bebeMalo = false;
        }
        //constructor cuando se ingresan string papá y mamá
        Bebe(QString color){
            amor = "";
            arte = "";
            hate = "";
            bebeMalo = false;
            colorPiel = color;


        }
        //constructor cuando se ingresan tres strings de emociones
        /*
        Bebe(string pAmor,string pArte,string pHate){
            amor = pAmor;
            arte = pArte;
            hate = pHate;
            //no siempre va a ser bebe malo = false cuando se ingresen emociones
            //tenemos que validar si las 3 estan en lista, si no estan, es bebeMalo
            bebeMalo = false;
            //podemos usar strings FULL, EMPTY Y HALF como las medidas
            if(amor == "FULL"&arte == "EMPTY"&hate == "EMPTY"){
                colorPiel = "Rubio";
            }
            else
                colorPiel = "Default";
        }
        */
        void imprimirPiel();

    };


    //Nodos para colaPedidos , los nodos seran bebes que estan a la espera
    //de pasar a la cola de produccion

    struct NodoBebe {
           int dato; // parte de datos
           Bebe * bebe;  //TODO: CHANGE PRIORITY
           NodoBebe* siguiente;// puntero para enlazar nodos
           // constructor

           NodoBebe()
           {
                siguiente = NULL; // sig es null
           }

           //TODO: CHANGE PRIORITY
           NodoBebe(Bebe * bebeIngresado)
           {
                siguiente = NULL; // sig es null
                bebe = bebeIngresado;

           }
          void imprimir();

    };




    struct ColaPedidos {
        // solo con pN es suficiente
        NodoBebe *frente; // ERROR sin ultimo nodo

        ColaPedidos()
        {
            frente = NULL;
        }


        void encolarBebe (Bebe * b);

        NodoBebe * desencolar();

        bool vacia();

        void imprimir();


        NodoBebe* verFrente();

    };


    //Nodo para lista doble del historico de los pedidos especiales
    struct NodoHistorico{
        QString colorMadre;
        QString colorPadre;
        QString tipoBebe;

        NodoHistorico * siguiente;
        NodoHistorico * anterior;

        NodoHistorico(){
            colorMadre = "";
            colorPadre = "";
            tipoBebe = "";
            siguiente = anterior = NULL;
        }

        NodoHistorico(QString mama , QString papa, QString bebe){
            colorMadre = mama;
            colorPadre = papa;
            tipoBebe = bebe;
            siguiente = anterior = NULL;
        }
    };



    //lista doble para guardar historico de los pedidos especiales
    struct ListaPedidosEspeciales{
        NodoHistorico * primerNodo, * ultimoNodo;
        int cantidadBebes;

        ListaPedidosEspeciales(){
            primerNodo = ultimoNodo = NULL;
            cantidadBebes = 0;
        }

        bool isEmpty();

        void insertar (QString infoMama,QString infoPapa,QString infoHijo);

        void insertarAlFinal(QString infoMama,QString infoPapa,QString infoHijo);

        void imprimir(bool inverted);

        //borrar al inicio: si esta vacia retorna null
        NodoHistorico * borrar();

        NodoHistorico * borrarAlFinal();

    };



signals:

};

#endif // ESTRUCTURASPEDIDO_H
