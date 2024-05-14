#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1

void cargaPedidos(int **&fechaClienteCantidad, char **&codigoProducto, const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    //inicializacion 
    int cantRegFecha = 0, capRegFecha = 0, cantRegPro = 0, capRegPro = 0;
    char buff[8], c;
    int dniSoli, cantSoli, fechaSoli, dd, mm, aa;
    fechaClienteCantidad = nullptr;
    codigoProducto = nullptr;


    //CRU-009,50375303,5,3/09/2023


    while (true) {
        arch.getline(buff, 8, ',');
        if (arch.eof()) break;
        arch >> dniSoli >> c >> cantSoli >> c >> dd >> c >> mm >> c>>aa;
        fechaSoli = aa * 10000 + mm * 100 + dd;
        arch.get();

        //Para fecha cliente cantidad

        if (cantRegFecha == capRegFecha)
            incremetarEspacios(fechaClienteCantidad, cantRegFecha, capRegFecha);
        fechaClienteCantidad[cantRegFecha - 1] = new int [3];
        fechaClienteCantidad[cantRegFecha - 1][0] = fechaSoli;

        fechaClienteCantidad[cantRegFecha - 1][1] = dniSoli;
        fechaClienteCantidad[cantRegFecha - 1][2] = cantSoli;

        cantRegFecha++;

        // para los productos
        int posProducto = buscarProducto(codigoProducto, buff);
        if (posProducto == NO_ENCONTRADO) {
            if (cantRegPro == capRegPro)
                incremetarEspaciosPro(codigoProducto, cantRegPro, capRegPro);
            posProducto = cantRegPro - 1;
            codigoProducto[posProducto] = new char [strlen(buff) + 1];
            strcpy(codigoProducto[posProducto], buff);
            cantRegPro++;
        }
    }
    qsort(fechaClienteCantidad, cantRegFecha - 1, sizeof (int **), cmpnumero);

}

void incremetarEspacios(int **&fechaClienteCantidad, int &cantRegFecha, int &capRegFecha) {
    int **aux;
    capRegFecha += INCREMENTO;
    if (fechaClienteCantidad == nullptr) {
        fechaClienteCantidad = new int *[capRegFecha] {
        };
        cantRegFecha = 1;
    } else {
        aux = new int *[capRegFecha] {
        };
        for (int i = 0; fechaClienteCantidad[i]; i++)
            aux[i] = fechaClienteCantidad[i];
        delete [] fechaClienteCantidad;
        fechaClienteCantidad = aux;
    }
}

int buscarProducto(char **codigoProducto, char *codigo) {
    for (int i = 0; codigoProducto != nullptr and codigoProducto[i]; i++)
        if (strcmp(codigoProducto[i], codigo) == 0) return i;
    return NO_ENCONTRADO;
}

void incremetarEspaciosPro(char **&codigoProducto, int &cantRegPro, int &capRegPro) {
    char **aux;
    capRegPro += INCREMENTO;
    if (codigoProducto == nullptr) {
        codigoProducto = new char *[capRegPro] {
        };
        cantRegPro = 1;
    } else {
        aux = new char *[capRegPro] {
        };
        for (int i = 0; codigoProducto[i]; i++)
            aux[i] = codigoProducto[i];
        delete [] codigoProducto;
        codigoProducto = aux;
    }
}

int cmpnumero(const void *regI, const void *regJ) {
    void **registro1 = (void **) regI;
    void **registro2 = (void **) regJ;
    int *numero1 = (int *) (registro1[0]);
    int *numero2 = (int *) (registro2[0]);
    return (*numero2 - *numero1);
}

void pruebaCargaDePedidos(int **fechaClienteCantidad, char **codigoProducto, const char *nomArch) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << setw(60) << "Rgistro de pedidos Fecha" << endl;
    arch << left << setw(15) << "Fecha de pedido" << setw(15) << "DNI cliente " << "Cantidad solicitada" << endl;

    for (int i = 0; fechaClienteCantidad[i]; i++) {
        arch << left <<setw(15) << fechaClienteCantidad[i][0] << setw(20) << 
                fechaClienteCantidad[i][1] <<fechaClienteCantidad[i][2]<< endl;
    }

    arch<<endl<<endl;
    arch << right << setw(60) << "Rgistro de pedidos Libros" << endl;
    arch<< "Codigo Libro"<<endl;;
    for (int i = 0; codigoProducto[i]; i++) {
        arch << left <<setw(15) << codigoProducto[i]<< endl;
    }
}

