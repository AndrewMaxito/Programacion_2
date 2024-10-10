

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: andre
 * 
 * Created on 9 de octubre de 2024, 12:06
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistro.h"
enum NODOESP{CABEZA,COLA};
enum NODODAT{DATO,SIG};


void crearLista(void *&pedidos,void* (*leeDatos)(ifstream &), const char *nomArch){
    
    ifstream arch(nomArch,ios::in);
    if (!arch.is_open()){
        cout << "no se pudo abrir el archivo "<<nomArch<<endl;
        exit (1);
    }
    
    cosntruirLista(pedidos);
    void *datos;
    while (true) {
        datos = leeDatos(arch);
        if (datos == nullptr) break;
        insertarLista(pedidos,datos);
    }
}

void cosntruirLista(void *&pedidos1){
    void **nodoEspecial = new void* [2];

    nodoEspecial[CABEZA] = nullptr;
    nodoEspecial[COLA] = nullptr;
    //union
    pedidos1 = nodoEspecial;
}



void insertarLista(void *pedidos,void *datos){
    //para tener acceso el nodo espcial 
    void **nodoEspecial =(void **)pedidos;
    
    //crear Nodo de dato
    void **nuevoNodo= new void*[2]{}; //Inicialixa ambos ne nullptr
    nuevoNodo[DATO] = datos;
    
    
    if (listaVacia(pedidos)) { //verifica si la lista esta vacia o llena
        //cuando la lista esta vacia ambos nodos apuntan al mismo nodoDAto
        nodoEspecial[CABEZA]= nuevoNodo;
    } else {//en caso existan datos
        void **ultimoNodo = (void **)(nodoEspecial[COLA]);
        ultimoNodo[SIG] = nuevoNodo;
    }
    //la cola del nodoEspecial apunta al nuevo dato ingresado
    nodoEspecial[COLA] = nuevoNodo; 
}

bool listaVacia(void *pedidos){
    void **nodoEspecial =(void **)pedidos;
    if (nodoEspecial[CABEZA] == nullptr ) return true;
    return false;
}


void imprimeLista(void *pedidos,void (*imprimeDatos)(ofstream &,void *), const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if (!arch.is_open()) {
        cout<< "No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **nodoEspecial=(void **)(pedidos);
    //recorrido
    void **recorrido = (void **)(nodoEspecial[CABEZA]); //ahi empieza 
    
    while (recorrido) { //cuando sea null se detiene
        imprimeDatos(arch,recorrido[DATO]);
        recorrido = (void **)recorrido[SIG]; 
    }
}


//combinar
void combinarLista(void *pedidos1,void *pedidos2,void *&pedidosFinal,int (*cmp)(void *,void*)){
    cosntruirLista(pedidosFinal);
    while (listaVacia(pedidos1)== false or listaVacia(pedidos2)== false) {
        void **nodEsp1 = (void **)pedidos1;
        void **nodEsp2 = (void **)pedidos2;
        
        int orden = cmp(nodEsp1[CABEZA],nodEsp2[CABEZA]);
        //cout<<orden<<endl;
        if (orden==0){//si son iguales
            insertarLista(pedidosFinal,quitaLista(pedidos1));
            void *basura = quitaLista(pedidos2);
            //se debe liberar el espacio de memoria del numero 
            void **datosBasura = (void **)basura;
            delete datosBasura;
            //cout<<"igual"<<endl;
        }else{
            if (orden>0) {//si 1 es mayor a 2
                insertarLista(pedidosFinal,quitaLista(pedidos2));
                //cout<<"se pone lo de 2 "<<endl;
            } else {//si 2 es mayor que 1 
                insertarLista(pedidosFinal,quitaLista(pedidos1));
                //cout<<"se pone lo de 1 "<<endl;
            }
        }
    }
}

void *quitaLista(void *lista){
    void **nodoEspecial = (void **)(lista);
    void *ptr = nodoEspecial[COLA];
    void **nodoDato=(void **)(nodoEspecial[CABEZA]);
    
    if (nodoEspecial[CABEZA] == nodoEspecial[COLA])
        nodoEspecial[COLA] = nullptr;
    ptr = nodoDato[DATO];
    
    nodoEspecial[CABEZA] = nodoDato[SIG] ;
    delete nodoDato;
    return ptr;
}