/* 
 * File:   FlotaGenerica.cpp
 * Author: andre
 * 
 * Created on 19 de octubre de 2024, 18:40
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "FlotaGenerica.h"

enum NODOESP{CABEZA,PESO};
enum NODO{DAT,SIG};

void cargaCamiones(void *&flota,int numCamiones,int pesoMaximo,
        void *(*leeDatos)(ifstream &), double (*calculaValor)(void *), const char* nomArch){
    
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    //Crea arreglo de camiones (flota)
    void **arrflota = new void *[numCamiones];
    for (int i = 0; i < numCamiones; i++) {
        costruirPila(arrflota[i]);
    }
    
    void *dato;
    int ind=0;
    //Ingreso de datos
    while (true) {
        dato = leeDatos(arch);
        if (dato == nullptr) break;
        double peso = calculaValor(dato);
        void **nodoEsp = (void **)(arrflota[ind]);
        double *pesoCamion = (double *)(nodoEsp[PESO]);
        if (peso + (*pesoCamion) > pesoMaximo ){
            ind++;
            if (ind >= numCamiones) break; //si ya no hay mas camiones termina
        }
        push(arrflota[ind],dato,peso);
    }
    
    flota = arrflota;
}


void costruirPila(void *&camnion){
    void **nodoEsp = new void *[2];
    nodoEsp[CABEZA] = nullptr;
    nodoEsp[PESO] = new int (0);
    //asignacion
    camnion  = nodoEsp;
}

void push(void *pila,void *dato, double peso){
    void **nodoEsp = (void **)(pila);
    void **nuevoNodo = new void *[2]{};
    
    nuevoNodo[DAT] = dato;
    nuevoNodo[SIG] = nodoEsp[CABEZA];
    nodoEsp[CABEZA] = nuevoNodo;
    
    double *pesoTotal = (double *)(nodoEsp[PESO]);
    (*pesoTotal) += peso;
}