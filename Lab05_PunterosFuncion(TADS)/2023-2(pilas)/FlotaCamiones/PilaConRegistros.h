/* 
 * File:   PilaConRegistros.h
 * Author: andre
 *
 * Created on 19 de octubre de 2024, 18:40
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H
void *leeRegistro(ifstream &arch);
double calculaRegistro(void *datos);
int cmpRegistro(const void *valorA, const void *valorB) ;
void imprimeRegistro(ofstream &arch, void *pila);
#endif /* PILACONREGISTROS_H */
