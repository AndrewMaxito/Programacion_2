

/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: andre
 * 
 * Created on 8 de septiembre de 2024, 11:04 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "MetodoExactoDeMemoria.h"

void lecturaDeLibros(const char *nomArch, char ***&libros, int **&stock) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    char **buffLibros[300], **datosLibros;
    int *buffStock[300], cantLibros = 0;
    while (true) {
        datosLibros = leerDatosLibros(arch);
        if (datosLibros == nullptr) break;
        buffLibros[cantLibros] = datosLibros;
        buffStock[cantLibros] = new int [2];
        cargaStock(arch, buffStock[cantLibros]);
        cantLibros++;
    }
    buffLibros[cantLibros] = nullptr;
    buffStock[cantLibros] = nullptr;
    cantLibros++;

    libros = new char **[cantLibros];
    stock = new int * [cantLibros];

    for (int i = 0; i < cantLibros; i++) {
        libros[i] = buffLibros[i];
        stock[i] = buffStock[i];
    }
}

char **leerDatosLibros(ifstream &arch) {
    char **regLibro, *codigo;
    codigo = leerCadenaExacta(arch, ',');
    if (codigo == nullptr) return nullptr;
    regLibro = new char*[3];
    regLibro[0] = codigo;
    regLibro[1] = leerCadenaExacta(arch, ',');
    regLibro[2] = leerCadenaExacta(arch, ',');
    return regLibro;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof())return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void cargaStock(ifstream &arch, int *stock) {
    double basura;
    char c;
    arch >> stock[0] >> c >> basura;
    arch.get(); //salto de linea
    stock[1] = 0;
}

void pruebaDePedidos(const char *nomArch, char ***libros, int **stock) {
    for (int i = 0; libros[i] != nullptr; i++) {
        char **auxLib = libros[i];
        int *auxStock = stock[i];
        cout << auxLib[0] << "   " << auxLib[1] << "   " << auxLib[2] << "   " << auxStock[0] << "  " << auxStock[1];
        cout << endl;
    }
}