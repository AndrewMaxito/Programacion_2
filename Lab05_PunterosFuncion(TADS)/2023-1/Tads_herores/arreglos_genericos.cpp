
/* 
 * File:   arreglos_genericos.cpp
 * Author: andre
 * 
 * Created on 9 de octubre de 2024, 19:56
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "arreglos_genericos.h"

void llenar_arreglo_heroes(void *&arrHeroes, int &cantHerores, const char* nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    void *buffHerore[300], *ptr;
    cantHerores = 0;
    while (true) {
        ptr = leerDatosHeroe(arch);
        if (ptr == nullptr) break;
        buffHerore[cantHerores] = ptr;
        cantHerores++;
    }
    buffHerore[cantHerores] = nullptr;
    
    void **regHero = new void* [cantHerores+1];
    for (int i = 0; buffHerore[i]; i++) {
        regHero[i] = buffHerore[i];
    }
    regHero[cantHerores] = nullptr;
    arrHeroes = regHero; 
}

/*  
    133,Malzahar,MID,A,53.65
    195,Akali,TOP,B,41.14
    15,Tryndamere,TOP,A,48.52
 */

void *leerDatosHeroe(ifstream &arch) {
    int buCod;
    char c;
    arch >> buCod;
    if (arch.eof()) return nullptr;
    char *nombreHer, *rolHer, *catHer;
    double *puntaHer = new double;
    int *codigoHer = new int (buCod);
    arch.get();

    nombreHer = leerCadenaExacta(arch, ',');
    rolHer = leerCadenaExacta(arch, ',');
    catHer = leerCadenaExacta(arch, ',');
    arch >> *puntaHer;


    void **datosHeroe = new void *[5];
    datosHeroe[0] = codigoHer;
    datosHeroe[1] = nombreHer;
    datosHeroe[2] = rolHer;
    datosHeroe[3] = catHer;
    datosHeroe[4] = puntaHer;

    return datosHeroe;
}

char *leerCadenaExacta(ifstream &arch, char del) {
    char buff[100], *ptr;
    arch.getline(buff, 100, del);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}


int cmp_multicriterio_void(const void*A, const void*B){
    void **regA = (void **)A;
    void **regB = (void **)B;
    
    void **datosA = (void **)(*regA);
    void **datosB = (void **)(*regB);
    
    char *nombreA = (char *)(datosA[1]);
    char *nombreB = (char *)(datosB[1]);
    
    int cond1 = strcmp(nombreA,nombreB);
    if (cond1!=0){//nombres Diferentes
        return cond1;
    }else{
        double *puntHerA = (double *)(datosA[4]);
        double *puntHerB = (double *)(datosB[4]);
        return (*puntHerB)-(*puntHerA);
    }
}