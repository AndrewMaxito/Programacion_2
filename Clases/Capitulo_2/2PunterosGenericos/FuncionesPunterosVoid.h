/* 
 * Proyecto: PunterosGenericos-Registro
 * Archivo: FuncionesPunterosVoid.h
 * Autor: J. Miguel Guanira Erazo (Juan Miguel)
 *
 * Creado el 16 de mayo de 2020, 12:16 PM
 */

#ifndef FUNCIONESPUNTEROSVOID_H
#define FUNCIONESPUNTEROSVOID_H
#include <fstream>
using namespace std;

void leeDatos(void*&, int &);
void ordenar(void *, int, int);
void imprimeDatos(void*, int);
void * leeRegistro(ifstream&);
void cambiar(void*&, void *&);
int comparar(void *, void *);

void leeRegistro(void *&);
void imprimeRegistro(void*);
void liberaEspacios(void *);
void * leeRegistro(void);

#endif /* FUNCIONESPUNTEROSVOID_H */