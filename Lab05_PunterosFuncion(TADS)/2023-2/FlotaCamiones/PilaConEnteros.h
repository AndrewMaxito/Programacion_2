/* 
 * File:   PilaConEnteros.h
 * Author: andre
 *
 * Created on 19 de octubre de 2024, 18:40
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

#include <fstream>
using namespace std;


void *leeNumero(ifstream &arch);
double calculaNumero(void *datos);
int cmpNumero(const void *valorA, const void *valorB);
void imprimeNumero(ofstream &arch,void *pila);

#endif /* PILACONENTEROS_H */
