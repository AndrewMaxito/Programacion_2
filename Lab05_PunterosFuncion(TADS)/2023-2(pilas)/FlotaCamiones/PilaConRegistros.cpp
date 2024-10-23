/* 
 * File:   PilaConRegistros.cpp
 * Author: andre
 * 
 * Created on 19 de octubre de 2024, 18:40
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConRegistros.h"

enum NODOESP {
    CABEZA, PESO
};

enum NODO {
    DAT, SIG
};

void *leeRegistro(ifstream &arch) {
    char buffCodigo[8], c;

    arch.getline(buffCodigo, 8, ',');
    if (arch.eof()) return nullptr;
    char *codigo = new char [strlen(buffCodigo) + 1];
    strcpy(codigo, buffCodigo);
    int *dniCliente = new int;
    int *cantidad = new int;
    double *pesoPedido = new double;

    arch >> *dniCliente >> c >> *cantidad >> c >> *pesoPedido;
    arch.get(); //salto de liena

    void *datos = new void *[4] {
        codigo, dniCliente, cantidad, pesoPedido
    };
    return datos;
}

double calculaRegistro(void *datos) {
    void **datosReg = (void **) (datos);
    double *pesoPaquete = (double *) (datosReg[3]);
    return *pesoPaquete;
}

int cmpRegistro(const void *valorA, const void *valorB) {
    void **camionA = (void **) valorA;
    void **camionB = (void **) valorB;

    void **nodoEspA = (void **) (*camionA); // equivalente a: void **nodoEspA = (void **)(camionA[0]);
    void **nodoEspB = (void **) (*camionB);

    double *pesoPila_A = (double *) (nodoEspA[PESO]);
    double *pesoPila_B = (double *) (nodoEspB[PESO]);

    return (*pesoPila_B)-(*pesoPila_A);
}

void imprimeRegistro(ofstream &arch, void *pila){
    void **nodoEsp = (void **) (pila);
    double *pesoCami = (double *) (nodoEsp[PESO]);
    arch << left << setw(10) << "Peso: " << right << setw(7) << *pesoCami << endl;

    void **recorrido = (void **) (nodoEsp[CABEZA]);
    arch<<endl;
    while (recorrido != nullptr) {
        void **datosReg = (void **)(recorrido[DAT]);
        char *codigo = (char *)(datosReg[0]);
        int *cantidad = (int *)(datosReg[2]);
        double *pesoPaquete = (double *) (datosReg[3]);
        recorrido = (void **) (recorrido[SIG]);
        arch << left <<setw(10)<<' '<<setw(13) << codigo << right << setw(5)
                << *cantidad <<setw (10) << *pesoPaquete << endl;
    } 
    arch<<endl;
}