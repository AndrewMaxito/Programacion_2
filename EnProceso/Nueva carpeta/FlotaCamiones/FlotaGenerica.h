
/* 
 * File:   FlotaGenerica.h
 * Author: andre
 *
 * Created on 10 de octubre de 2024, 20:29
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <fstream>
using namespace std;

void cargaCamiones(void *&flota,int numCamiones, double pesoMaximo,
        void *(*leeNumero)(ifstream &), double (*calculaNumero)(void *), 
        const  char *nomArch);
void construirPila(void *&pila);


#endif /* FLOTAGENERICA_H */
