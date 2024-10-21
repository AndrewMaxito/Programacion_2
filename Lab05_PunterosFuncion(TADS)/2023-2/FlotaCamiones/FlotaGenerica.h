/* 
 * File:   FlotaGenerica.h
 * Author: andre
 *
 * Created on 19 de octubre de 2024, 18:40
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <fstream>





void cargaCamiones(void *&flota,int numCamiones,int pesoMaximo,
        void *(*leeDatos)(ifstream &), double (*calculaValor)(void *), const char* nomArch);
void costruirPila(void *&camnion);
void push(void *pila,void *dato, double peso);

void muestraCamiones(void *flota,int numCamiones,void (*imprimeDatos)(ofstream &,void *),
        const char* nomArch);
#endif /* FLOTAGENERICA_H */
