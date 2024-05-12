
/* 
 * File:   BibliotecaGenerica.h
 * Author: andre
 *
 * Created on 11 de mayo de 2024, 11:45
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H
#include <fstream>
using namespace std;

void crealista(void *&pedidos1,void *(*leeRegistro)(ifstream &),const char *nomArch);
void insertarlista(void *datos, void **nodoEspecial);
void imprimelista(void *pedidos1,void (*imprimeRegistro)(ofstream &,void *),
        const char *nomArch);

//Pregunta 2
void  combinalista(void *pedidos1,void *pedidos2,void *&pedidiosFinal,
        int (*cmpReg)(void *,void*));
void *quitarlista(void **cabeza);


#endif /* BIBLIOTECAGENERICA_H */

