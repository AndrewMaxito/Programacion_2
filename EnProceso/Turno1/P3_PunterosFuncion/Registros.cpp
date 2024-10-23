/* 
 * File:   Registros.cpp
 * Author: andre
 * 
 * Created on 22 de octubre de 2024, 16:59
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Registros.h"



void *creaRegistro(void *venta){
    void **datos = (void **)venta;
    
    void **registroDat = new void *[5];
    registroDat[0] = datos[0];
    registroDat[1] = datos[1];
    registroDat[2] = datos[2];
    registroDat[3] = datos[7];
    registroDat[4] = datos[3];
    return registroDat;
}

void imprimeRegistro(ofstream &arch,void *reg){
    void **datos = (void **)reg;
    char *codigo = (char *)(datos[0]);
    char *nombre = (char *)(datos[1]);
    char *autor = (char *)(datos[2]);
    int  *ranking = (int *)(datos[3]);
    void **regDnis = (void **)(datos[4]);
    
    
    arch << left << setw(15) <<"Codigo "<< setw(15)<<codigo <<setw(60) <<nombre << autor << endl;
    arch << "DNI personas vendidas"<<endl;
    for (int i = 0; regDnis !=nullptr and regDnis[i]; i++) {
        int *dni = (int *)(regDnis[i]);
        arch << setw (15) << ' '<<*dni<<endl;
    }
}