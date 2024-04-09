#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "FuncionesDePunteros.h"

void leerNombres(char **&nombres, int &numDat, const char *nombArch) {
    char *buff[500], *nomb;
    numDat = 0;
    ifstream archNomb(nombArch, ios::in);
    if (!archNomb) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    while (1) {
        nomb = leeCadena(archNomb);
        if (nomb == nullptr) break;
        buff[numDat] = nomb;
        numDat++;
    }
    nombres = new char*[numDat];
    for (int i = 0; i < numDat; i++) nombres[i] = buff[i];
}

char* leeCadena(ifstream &archNomb) {
    char cadena[500], *cad;
    archNomb.getline(cadena, 500);
    if (archNomb.eof()) return nullptr;
    cad = new char[strlen(cadena) + 1];
    strcpy(cad, cadena);
    return cad;
}

void ordenar(char **nombres, int izq, int der) {
    int limite;
    if (izq >= der) return;
    cambiar(nombres, izq, (izq + der) / 2);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (strcmp(nombres[i], nombres[izq]) < 0) cambiar(nombres, ++limite, i);
    cambiar(nombres, izq, limite);
    ordenar(nombres, izq, limite - 1);
    ordenar(nombres, limite + 1, der);
}

void cambiar(char**nombres, int i, int k) {
    char *aux;
    aux = nombres[i];
    nombres[i] = nombres[k];
    nombres[k] = aux;
}

void imprimir(char **nombres, int numDat, const char *nombArch) {
    ofstream archNomb(nombArch, ios::out);
    if (!archNomb) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    for (int i = 0; i < numDat; i++)
        archNomb << nombres[i] << endl;
}

void ordenarNum(int *arr, int izq, int der) {
    cout << "-----------------" << endl;
    int limite;
    for (int i = 0; i < 6; i++)cout << arr[i] << " ";
    cout << endl;
    if (izq >= der) return;

    cambiarNum(arr, izq, (izq + der) / 2);
    for (int i = 0; i < 6; i++)cout << arr[i] << " ";
    cout << endl;
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (arr[i] < arr[izq]) {
            cambiarNum(arr, ++limite, i);
            for (int j = 0; j < 6; j++)cout << arr[j] << " ";
            cout << "pip"<<endl;
        }
    cout<<"*************************"<<endl;
    cambiarNum(arr, izq, limite);
    for (int i = 0; i < 6; i++)cout << arr[i] << " ";
            cout << endl;
    ordenarNum(arr, izq, limite - 1);
    cout<<"====================="<<endl;
    ordenarNum(arr, limite + 1, der);
}

void cambiarNum(int *arr, int i, int k) {
    int aux;
    aux = arr[i];
    arr[i] = arr[k];
    arr[k] = aux;

}
