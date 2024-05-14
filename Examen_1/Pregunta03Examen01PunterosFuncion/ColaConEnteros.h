
/* 
 * File:   ColaConEnteros.h
 * Author: andre
 *
 * Created on 13 de mayo de 2024, 20:35
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

#include <fstream>

void cargaEnteros(void *&cola,void *(*leenumero)(ifstream &),const char *nomArch);
void *leenumero(ifstream &arch);
void mostrarEneteros(void *cola, void (*imprimenumero)(ofstream &,void *),const char *nomArch) ;
void imprimenumero(ofstream &arch,void *registro);


#endif /* COLACONENTEROS_H */

