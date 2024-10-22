/* 
 * File:   PunterosMultiples.cpp
 * Author: andre
 * 
 * Created on 21 de octubre de 2024, 20:44
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "PunterosMultiples.h"
#define INCREMENTO 5

//CRY6839,34460612,15/10/2023,93
//WPU8819,42302422,9/2/2024,15
//PQZ1316,34460612,2/4/2024,73

void cargaVentas(char **&ventaLibroCodigo, int **&ventasDniFechaPuntaje,
        const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    ventaLibroCodigo = nullptr;
    ventasDniFechaPuntaje = nullptr;

    int cantVentas = 0;
    int capVentas = 0;

    char *codigoLibro, c;
    int dd, mm, aa, fecha, puntaje;


    while (true) {
        codigoLibro = leerCadenaExacta(arch, ',');
        if (codigoLibro == nullptr) break;

        if (cantVentas == capVentas)
            aumentarEspaciosVentas(ventaLibroCodigo, ventasDniFechaPuntaje, cantVentas, capVentas);
        int pos = cantVentas - 1;
        ventaLibroCodigo[pos] = codigoLibro;
        ventasDniFechaPuntaje[pos] = new int [3];
        int *datosDniFecha = ventasDniFechaPuntaje[pos];
        arch >> datosDniFecha[0] >> c >> dd >> c >> mm >> c >> aa >> c >> datosDniFecha[2];
        arch.get(); // salto de linea
        datosDniFecha[1] = aa * 10000 + mm * 100 + dd;
        cantVentas++;
    }
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof())return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void aumentarEspaciosVentas(char **&ventaLibroCodigo, int **&ventasDniFechaPuntaje,
        int &cantVentas, int &capVentas) {
    capVentas += INCREMENTO;
    if (ventaLibroCodigo == nullptr) {
        ventaLibroCodigo = new char *[capVentas] {
        };
        ventasDniFechaPuntaje = new int *[capVentas] {
        };
        cantVentas = 1;
    } else {
        char **auxVenCod = new char *[capVentas] {
        };
        int **auxVenDni = new int *[capVentas] {
        };
        for (int i = 0; ventaLibroCodigo[i]; i++) {
            auxVenCod[i] = ventaLibroCodigo[i];
            auxVenDni[i] = ventasDniFechaPuntaje[i];
        }
        delete ventaLibroCodigo;
        delete ventasDniFechaPuntaje;
        ventaLibroCodigo = auxVenCod;
        ventasDniFechaPuntaje = auxVenDni;
    }
}

void pruebaDeCargaDeVentas(char **ventaLibroCodigo, int **ventasDniFechaPuntaje,
        const char *nomArch) {
    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << " No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    int aa, mm, dd;
    arch << left << setw(20) << "Codigo Libro" << setw(15) << "DNI" <<
            setw(15) << "Fecha" << setw(15) << "Puntaje" << endl;
    for (int i = 0; ventaLibroCodigo[i]; i++) {
        int *datosDniFecha = ventasDniFechaPuntaje[i];
        aa = datosDniFecha[1] / 10000;
        mm = (datosDniFecha[1] - aa * 10000) / 100;
        dd = datosDniFecha[1] % 100;
        arch << left << setw(15) << ventaLibroCodigo[i] << setw(20) << datosDniFecha[0] <<
                right << setw(2) << setfill('0') << dd << '/' << setw(2) <<
                mm << '/' << aa << setfill(' ') << setw(10) << datosDniFecha[2] << endl;
    }
}



//IIM5175,Diamantes y pedernales,Jose Maria Arguedas
//YDK7687,El otonio del patriarca,Gabriel Garcia Marquez

void cargaLibros(char ***&libro, const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    libro = nullptr;
    int cant = 0, cap = 0;
    char *codigo, buffNombre[100];
    while (true) {
        codigo = leerCadenaExacta(arch, ',');
        if (codigo == nullptr) break;

        if (cant == cap)
            aumnetarEspaciosLibros(libro, cant, cap);
        int pos = cant - 1;
        libro[pos] = new char *[3];
        char **datosLibro = libro[pos];
        datosLibro[0] = codigo;
        datosLibro[1] = leerCadenaExacta(arch, ',');
        arch.getline(buffNombre, 100);
        datosLibro[2] = new char [strlen(buffNombre) + 1];
        strcpy(datosLibro[2], buffNombre);
        cant++;
    }
    
    qsort(libro,cant-1,sizeof (char *),cmp);
    
}

void aumnetarEspaciosLibros(char ***&libro, int &cant, int &cap) {
    cap += INCREMENTO;
    if (libro == nullptr) {
        libro = new char **[cap] {
        };
        cant = 1;
    } else {
        char ***auxLibro = new char **[cap] {
        };
        for (int i = 0; libro[i]; i++) {
            auxLibro[i] = libro[i];
        }
        delete libro;
        libro = auxLibro;
    }
}

void pruebaDeCargaDeLibros(char ***libro, const char*nomArch) {

    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << " No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << left << setw(15) << "Codigo Libro" << setw(60) << "Nombre del libro " <<
            setw(50) << "Autor del libro " << endl;

    for (int i = 0; libro[i]; i++) {
        char **datosLibro = libro[i];
        arch << setw(15) << datosLibro[0] << setw(60) << datosLibro[1] << setw(50) <<
                datosLibro[2] << endl;
    }
}


int cmp(const void *valorA, const void *valorB){
    char ***libroA = (char ***)(valorA);
    char ***libroB = (char ***)(valorB);
    
    char **datA = libroA[0]; 
    char **datB = libroB[0];    
    return strcmp(datA[1],datB[1]);
}


