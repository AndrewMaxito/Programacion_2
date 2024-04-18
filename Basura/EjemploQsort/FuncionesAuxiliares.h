
/* 
 * File:   FuncionesAuxiliares.h
 * Author: andre
 *
 * Created on 18 de abril de 2024, 09:23
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerDatosPorIncrementos(int *&datos, const char *nombArch);
void aumentarEspacios(int *&datos, int &nd, int &cap);
void imprimirDatos(int *datos);
void ordenar(int *datos);
void qSort(int *datos, int izq, int der);
void cambiar(int &datoI, int &datoK);


#endif /* FUNCIONESAUXILIARES_H */

