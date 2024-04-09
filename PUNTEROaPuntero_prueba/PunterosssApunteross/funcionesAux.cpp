#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "funcionesAux.h"

void leerDatos(int **&numeros, int &numDatos, const char *nombArch) {
    int *buff[50], *serieNum;
    numDatos=0;


    ifstream archNum(nombArch, ios::in);
    if (not archNum.is_open()) {
        cout << "No se pudo abrir el archivo : " << nombArch << endl;
        exit(1);
    }
    //TOMANDO QUE SI O SI SON SOLO SON 7 DATOS 

    while (true) {
        serieNum = leerFilaDelDato(archNum);
        if (serieNum == nullptr) break;
        buff[numDatos] = serieNum; //le asigno la direccion de memoria al buff
        numDatos++;
    }
    numeros = new int* [numDatos];
    for (int i =0;i < numDatos; i++)numeros[i]=buff[i];
}

int *leerFilaDelDato(ifstream &archNum) {
    int arr[30], *ptr, cant = 0, valor;

    while (true) {
        archNum >> valor;
        if (archNum.eof()) return nullptr;
        arr[cant] = valor;
        cant++;
        if (archNum.get() == '\n') break;
    }
    ptr = new int [cant];
    for (int i = 0; i < cant; i++) ptr[i] = arr[i];
    return ptr;
}

