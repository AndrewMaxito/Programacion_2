#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "FuncionesAuxiliares.h"

#define INCREMENTO 5

void leerDatosPorIncrementos(int *&datos, const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "El archivo " << nombArch << " no se abrio" << endl;
        exit(1);
    }
    int nd = 0, cap = 0, dato;

    datos = nullptr;
    while (true) {
        arch>>dato;
        if (arch.eof())break;
        if (nd == cap)
            aumentarEspacios(datos, nd, cap);
        datos[nd - 1] = dato;
        nd++;
    }
}

void aumentarEspacios(int *&datos, int &nd, int &cap) {
    int *aux;

    cap += INCREMENTO;
    if (datos == nullptr) {
        datos = new int[cap] {
        }; // No olvidar las {}
        nd = 1;
    } else {
        aux = new int [cap] {
        };
        for (int i = 0; i < nd; i++)
            aux[i] = datos[i];
        delete datos;
        datos = aux;
    }
}

void ordenar(int *datos) {
    int numDat = 0;
    while (datos[numDat])numDat++;
    qSort(datos, 0, numDat - 1);
}

void qSort(int *datos, int izq, int der) {
    int limite, pos;
    if (izq >= der)return;
    pos = (izq + der) / 2;
    cambiar(datos[izq], datos[pos]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (datos[i] < datos[izq]) {
            limite++;
            cambiar(datos[limite], datos[i]);
        }
    cambiar(datos[limite], datos[izq]);
    qSort(datos, izq, limite - 1);
    qSort(datos, limite + 1, der);
}

void cambiar(int &datoI, int &datoK) {
    int aux;
    aux = datoI;
    datoI = datoK;
    datoK = aux;
}

void imprimirDatos(int *datos) {
    for (int i = 0; datos[i]; i++)
        cout << setw(8) << datos[i] << endl;
}