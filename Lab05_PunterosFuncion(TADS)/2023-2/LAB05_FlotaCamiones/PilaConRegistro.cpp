#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "PilaConRegistro.h"

enum REGISTRO {
    CODIGO, DNI, CANTIDAD, PESO
};

void *leeregistro(ifstream &arch) {
    void **registro;
    char *codigo, c;
    int *dni, *cantidad;
    double *peso;

    codigo = leerCadenaExacta(arch, ',');
    if (arch.eof()) return nullptr;
    dni = new int;
    cantidad = new int;
    peso = new double;
    arch >> *dni >> c >>*cantidad >> c>>*peso;
    arch.get();
    registro = new void *[4];
    registro[0] = codigo;
    registro[1] = dni;
    registro[2] = cantidad;
    registro[3] = peso;

    return registro;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

double calcularegistro(void *reg) {
    void **datos = (void **) reg;
    double *peso = (double *) (datos[PESO]);
    return *peso;
}

int cmpregistro(const void *izq, const void *der) {
    void **registroIzq = (void **) izq, **registroDer = (void **) der;

    void **pilaIzq = (void **) (registroIzq[0]), **pilaDer = (void **) (registroDer[0]);

    double *pesoIzq = (double *) (pilaIzq[1]), *pesoDer = (double *) (pilaDer[1]);
    return (*pesoDer - *pesoIzq);
}

void imprimeregistro(ofstream &arch, void *reg) {
    void **datosRegis = (void **) reg;
    char *codigo = (char *) (datosRegis[CODIGO]);
    int *cantidad = (int *) (datosRegis[CANTIDAD]);
    double *peso = (double *) (datosRegis[PESO]);
    arch << left << setw(10) << ' ' << setw(15) << codigo << setw(5) << *cantidad << right << 
            setw(7) << *peso << endl;
}