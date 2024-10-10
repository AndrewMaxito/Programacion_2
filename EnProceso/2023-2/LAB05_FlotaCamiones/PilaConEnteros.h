

/* 
 * File:   PilaConEnteros.h
 * Author: andre
 *
 * Created on 30 de abril de 2024, 15:01
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H
#include <fstream>
using namespace std;
void *leenumero(ifstream &arch);
double calculanumero(void *reg);
int cmpnumero(const void *izq, const void *der) ;
void imprimenumero(ofstream &arch,void *reg);
void imprimenumero(ofstream &arch,void *reg);


#endif /* PILACONENTEROS_H */

