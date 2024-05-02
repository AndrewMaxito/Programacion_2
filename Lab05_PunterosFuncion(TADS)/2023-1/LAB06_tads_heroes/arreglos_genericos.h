
/* 
 * File:   arreglos_genericos.h
 * Author: andre
 *
 * Created on 1 de mayo de 2024, 12:06
 */

#ifndef ARREGLOS_GENERICOS_H
#define ARREGLOS_GENERICOS_H
#include <fstream>
using namespace std;
void llenar_arreglo_heroes(void *&arreglo_heroes,int &cantidad_total_heroes,
        const char *nomArch);
void *leerDatosHeroe (ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char deli);
int cmp_multicriterio_void(const void *izq, const void *der);


void imprimirDatos(void *arreglo_heroes,int cantidad_total_heroes);

#endif /* ARREGLOS_GENERICOS_H */

