

/* 
 * File:   FuncionesRegistro.cpp
 * Author: andre
 * 
 * Created on 9 de octubre de 2024, 12:07
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "FuncionesRegistro.h"

void *leeRegistro(ifstream &arch) {

    /*
        2,14268463,BHD6079
        7,42302422,RWW7975
        9,11750801,VDL9379
     */
    int num;
    char c;
    arch >> num;
    if (arch.eof())return nullptr;
    int *numero = new int(num);
    int *dni = new int;
    char buff[100], *codigoLib;

    arch >> c >> *dni >> c >>buff;
    codigoLib = new char [strlen(buff) + 1];
    strcpy(codigoLib, buff);

    void **datos = new void *[3];
    datos[0] = numero;
    datos[1] = dni;
    datos[2] = codigoLib;
    return datos;
}

void imprimeRegistro(ofstream &arch, void *dato) {
    void **datosReg = (void **) dato;
    int *numPedi = (int *) (datosReg[0]);
    int *dni = (int *) (datosReg[1]);
    char *codigoLib = (char *) (datosReg[2]);

    arch << left << setw(10) << *numPedi << setw(15) << *dni << codigoLib << endl;
}

int cmpRegistro(void *a, void *b) {
    if (a == nullptr) return 1;
    if (b == nullptr) return -1;

    void **nodoA = (void **) a;
    void **nodoB = (void **) b;


    void **datosNodoA = (void **) (nodoA[0]);
    void **datosNodoB = (void **) (nodoB[0]);


    int *valorA = (int *) (datosNodoA[0]);
    int *valorB = (int *) (datosNodoB[0]);

    return (*valorA)-(*valorB);
}