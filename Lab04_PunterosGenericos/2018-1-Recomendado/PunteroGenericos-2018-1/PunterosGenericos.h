
/* 
 * File:   PunterosGenericos.h
 * Author: andre
 *
 * Created on 21 de abril de 2024, 15:03
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void leerUsurarios(void *&usuarios);
void *leerUsuario(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char deli);
void imprimirUsuarios(void *usuarios);
void imprimeUsuario(void *registro, ofstream &arch);

//Pregunta 2
void leerPrestamos(void *usuarios);
void leePrestamo(ifstream &arch,int *&codigoUs,char *&codigoLib,int *&fecha);
int buscarUusuario(int codigoUs,void *usuarios);
bool iguales(int codigoUs, void *registro);
void agregarPrestamo(void *registro,int &cap,char *codigoLib,int *fecha);
void incremetarEspacios(void **&prestamos, int *&numP, int&cap);


void imprimirPrestamos(void *usuarios);

#endif /* PUNTEROSGENERICOS_H */

