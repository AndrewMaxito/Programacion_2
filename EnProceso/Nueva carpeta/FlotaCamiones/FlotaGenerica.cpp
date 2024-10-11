/* 
 * File:   FlotaGenerica.cpp
 * Author: andre
 * 
 * Created on 10 de octubre de 2024, 20:29
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FlotaGenerica.h"
enum NODOESP{CIMA,PESOTOTAL};

void cargaCamiones(void *&flota,int numCamiones, double pesoMaximo,
        void *(*leeNumero)(ifstream &), double (*calculaNumero)(void *), 
        const  char *nomArch){
    
    ifstream arch  (nomArch,ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
   
    flota = new void *[numCamiones];
    void **camiones = (void **)flota;
    
    for (int i = 0; i < numCamiones; i++) 
        construirPila(camiones[i]);
    
    while (true) {
        
        
        

    }

    

    
    
    
    
    
    
    
}


void construirPila(void *&pila){
    void **nodoEspecial = new void *[2];
    nodoEspecial[CIMA]= nullptr;
    double *pesoTotal = new double (0.0);
    nodoEspecial[PESOTOTAL] = pesoTotal;
    pila = nodoEspecial;
}