
/* 
 * Proyecto: PunterosGenericos-Registro
 * Archivo: FuncionesPunterosVoid.cpp
 * Autor: J. Miguel Guanira Erazo (Juan Miguel)
 *
 * Creado el 16 de mayo de 2020, 12:16 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "FuncionesPunterosVoid.h"

enum Registro {
    DNI, NOMBRE, SUELDO
};

void leeDatos(void*&per, int &numPer) {
    ifstream arch("personal.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo personal.csv" << endl;
        exit(1);
    }
    void**personas, *buff[100], *p;
    numPer = 0;

    while (1) {
        p = leeRegistro(arch);
        if (p == nullptr) break;
        buff[numPer] = p;
        numPer++;
    }
    personas = new void*[numPer];
    for (int i = 0; i < numPer; i++)
        personas[i] = buff[i];
    per = personas;
}

void *leeRegistro(ifstream&arch) {
    int *dni, d;
    char *nombre, buff[100];
    double *sueldo;
    void**registro;

    arch >> d;
    if (arch.eof()) return nullptr;

    dni = new int;
    *dni = d;
    arch.get(); // Sacar la coma
    arch.getline(buff, 100, ',');
    nombre = new char[strlen(buff) + 1];
    strcpy(nombre, buff);
    sueldo = new double;


    arch>>*sueldo;

    registro = new void*[3];
    registro[DNI] = dni;
    registro[NOMBRE] = nombre;
    registro[SUELDO] = sueldo;

    return registro;
}

void imprimeDatos(void*per, int numPer) {
    void **personas = (void **) per;

    for (int i = 0; i < numPer; i++)
        imprimeRegistro(personas[i]);
}

void ordenar(void *per, int izq, int der) {
    void **personas = (void **) per;
    int limite;
    if (izq >= der) return;
    cambiar(personas[izq], personas[(izq + der) / 2]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (comparar(personas[i], personas[izq]) < 0)
            cambiar(personas[++limite], personas[i]);
    cambiar(personas[izq], personas[limite]);
    ordenar(personas, izq, limite - 1);
    ordenar(personas, limite + 1, der);
}

void cambiar(void*&a, void *&b) {
    void *aux;
    aux = a;
    a = b;
    b = aux;
}

int comparar(void *perI, void *perJ) {
    void **personaI = (void **) perI,
            **personaJ = (void **) perJ;
    // double *sueldoI = (double *)(personaI[SUELDO]),
    // *sueldoJ = (double *)(personaJ[SUELDO]);
    // return *sueldoJ - *sueldoI;
    char*nombreI = (char *) (personaI[NOMBRE]),
            *nombreJ = (char *) (personaJ[NOMBRE]);
    return strcmp(nombreI, nombreJ);
}

void leeRegistro(void *&persona) {
    int *dni, d;
    char *nombre, buff[100];
    double *sueldo;


    void**registro;

    cin >> d;
    if (cin.eof()) {
        persona = nullptr;
        return;
    }

    dni = new int;
    *dni = d;
    cin.get(); // Sacar la coma
    cin.getline(buff, 100, ',');
    nombre = new char[strlen(buff) + 1];
    strcpy(nombre, buff);
    sueldo = new double;
    cin>>*sueldo;

    registro = new void*[3];
    registro[DNI] = dni;
    registro[NOMBRE] = nombre;
    registro[SUELDO] = sueldo;

    persona = registro;
}

void imprimeRegistro(void*persona) {
    int *dni;
    char *nombre;
    double *sueldo;
    void **registro = (void **) persona;

    dni = (int*) (registro[DNI]);
    nombre = (char*) (registro[NOMBRE]);
    sueldo = (double*) (registro[SUELDO]);

    cout.precision(2);
    cout << fixed;
    cout << left << setw(10) << *dni << setw(40) << nombre
            << right << setw(12) << *sueldo << endl;
}

void liberaEspacios(void *persona) {
    int *dni;
    char *nombre;
    double *sueldo;
    void **registro = (void **) persona;

    dni = (int*) (registro[DNI]);
    nombre = (char*) (registro[NOMBRE]);
    sueldo = (double*) (registro[SUELDO]);

    delete dni;
    delete nombre;

    delete sueldo;
    delete registro;
}

void *leeRegistro(void) {
    int *dni, d;
    char *nombre, buff[100];
    double *sueldo;
    void**registro;

    cin >> d;
    if (cin.eof()) return nullptr;

    dni = new int;
    *dni = d;
    cin.get(); // Sacar la coma
    cin.getline(buff, 100, ',');
    nombre = new char[strlen(buff) + 1];
    strcpy(nombre, buff);
    sueldo = new double;
    cin>>*sueldo;

    registro = new void*[3];
    registro[DNI] = dni;
    registro[NOMBRE] = nombre;
    registro[SUELDO] = sueldo;

    return registro;
}

