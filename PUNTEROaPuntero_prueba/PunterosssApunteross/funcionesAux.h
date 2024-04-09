
/* 
 * File:   funcionesAux.h
 * Author: andre
 *
 * Created on 7 de abril de 2024, 17:07
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

#include <fstream>
using namespace std;

void leerDatos(int **&numeros, int &numDatos, const char *nombArch);
int *leerFilaDelDato(ifstream &archNum);

void ordenar(int **numeros,int izq,int der);

#endif /* FUNCIONESAUX_H */

