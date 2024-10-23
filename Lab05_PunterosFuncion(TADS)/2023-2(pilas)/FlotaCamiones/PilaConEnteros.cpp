/* 
 * File:   PilaConEnteros.cpp
 * Author: andre
 * 
 * Created on 19 de octubre de 2024, 18:40
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#include "PilaConEnteros.h"

enum NODOESP {
    CABEZA, PESO
};

enum NODO {
    DAT, SIG
};

void *leeNumero(ifstream &arch) {
    double buffNum;
    arch >> buffNum;
    if (arch.eof()) return nullptr;
    double *numero = new double (buffNum);
    return numero;
}

double calculaNumero(void *datos) {
    double *pesoPaquete = (double *) (datos);
    return *pesoPaquete;
}

int cmpNumero(const void *valorA, const void *valorB) {
    void **camionA = (void **) valorA;
    void **camionB = (void **) valorB;

    void **nodoEspA = (void **) (*camionA); // equivalente a: void **nodoEspA = (void **)(camionA[0]);
    void **nodoEspB = (void **) (*camionB);

    double *pesoPila_A = (double *) (nodoEspA[PESO]);
    double *pesoPila_B = (double *) (nodoEspB[PESO]);

    return (*pesoPila_B)-(*pesoPila_A) ;
}

void imprimeNumero(ofstream &arch, void *pila) {
    void **nodoEsp = (void **) (pila);
    double *pesoCami = (double *) (nodoEsp[PESO]);
    arch << left << setw(10) << "Peso: " << right << setw(7) << *pesoCami << endl;

    void **recorrido = (void **) (nodoEsp[CABEZA]);

    while (recorrido != nullptr) {
        double *pesoPaquete = (double *) (recorrido[DAT]);
        recorrido = (void **) (recorrido[SIG]);
        arch << *pesoPaquete << endl;
    }
}