
/* 
 * File:   funiconesaux.cpp
 * Author: andre
 * 
 * Created on 10 de septiembre de 2024, 10:26 PM
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "funiconesaux.h"

void cargarDatos(int **&datos) {
    int arrDatos[8]{1, 2, 3, 4, 5, 6, 7, 8};
    int *buff[8];
    for (int i = 0; i < 8; i++) {
        buff[i] = new int [2] {
        };
        buff[i][0] = arrDatos[i];
    }
    datos = new int *[8];
    for (int i = 0; i < 8; i++) {
        datos[i] = buff[i];
    }
}

void imprimirDatos(int **datos) {
    for (int i = 0; i < 8; i++) {
        int *auxDatos=datos[i];
        cout << auxDatos[0] << " " <<auxDatos[1]<<endl;
    }
    cout << endl;
}

void modificarDatos(int **datos) {
    int *aux = datos[2];
    aux[1] = 70;
//    cout<<"numero: "<<aux[0]<<endl;




}


