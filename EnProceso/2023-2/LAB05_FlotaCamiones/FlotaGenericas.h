
/* 
 * File:   FlotaGenericas.h
 * Author: andre
 *
 * Created on 30 de abril de 2024, 15:08
 */

#ifndef FLOTAGENERICAS_H
#define FLOTAGENERICAS_H

void cargaCamiones(void *&flota,int numcamiones, double pesomaximo, 
        void *(*leeDatosArch)(ifstream &), double (*calcula)(void *),
        const char *nomArch);
void *crearPila();
void push (void *pila,void *registro, double peso);
void muestraCamiones(void *flota, int numcamiones, void (*imprimenumero)(ofstream &, void *),
        const char *nomArch);

#endif /* FLOTAGENERICAS_H */

