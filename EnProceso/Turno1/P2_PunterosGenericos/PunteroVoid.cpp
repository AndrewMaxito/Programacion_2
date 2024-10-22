

/* 
 * File:   PunteroVoid.cpp
 * Author: andre
 * 
 * Created on 21 de octubre de 2024, 22:33
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunteroVoid.h"
#include "AperturaDeArchivos.h"
#define NO_ENCONTRADO -1

void cargaVentas(char ***libro,void *&ventas){
    void *buffVentas[300];
    int cantVentas=0;
    for (int i = 0; libro[i] ; i++) {
        char **datosLibro = libro[i];
        buffVentas[cantVentas] = new void *[8];
        void **datosVenta = (void **)(buffVentas[cantVentas]);
        datosVenta[0] = datosLibro[0];
        datosVenta[1] = datosLibro[1];
        datosVenta[2] = datosLibro[2];
        
        datosVenta[3] = nullptr;
        datosVenta[4] = new int (0);
        datosVenta[5] = new int (0);
        datosVenta[6] = new double (0);
        datosVenta[7] = new int (0);
        cantVentas++;
    }
    buffVentas[cantVentas]= nullptr;
    cantVentas++;
    void **registroVentas = new void *[cantVentas];
    for (int i = 0; buffVentas[i]; i++) {
        registroVentas[i] = buffVentas[i];
    }
    registroVentas[cantVentas-1] = nullptr;
    ventas = registroVentas;
    
}

void actulizarVentas(int **ventasDniFechaPuntaje,char **ventaLibroCodigo,void *ventas){
    
    
    for (int i = 0; ventaLibroCodigo[i]; i++) {
        int posLibro = buscarLibro(ventas,ventaLibroCodigo[i]);
        

    }

    
    
    
}

int buscarLibro(void *ventas,char *codigoLibVen){
    void **regVentas = (void **)(ventas);
    
    for (int i = 0; regVentas[i]; i++) {
        void **datosVentas = (void **)(regVentas[i]);
        char *codigoLib = (char *)(datosVentas[0]);
        if (strcmp(codigoLib,codigoLibVen)==0) return i;
    }
    cout <<"NO se encontro el libro "<<codigoLibVen<<endl;
    exit(1);
    return NO_ENCONTRADO;
}