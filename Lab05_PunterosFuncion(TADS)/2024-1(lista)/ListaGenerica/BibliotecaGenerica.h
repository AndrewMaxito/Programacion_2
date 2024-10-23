

/* 
 * File:   BibliotecaGenerica.h
 * Author: andre
 *
 * Created on 9 de octubre de 2024, 12:06
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H
#include <fstream>
using namespace std;


void crearLista(void *&pedidos1,void* (*leeDatos)(ifstream &), const char *nomArch);
void cosntruirLista(void *&pedidos1);
void insertarLista(void *pedidos,void *datos);
bool listaVacia(void *pedidos);

//
void imprimeLista(void *pedidos1,void (*imprimeDatos)(ofstream &,void *), const char *nombArch);
void combinarLista(void *pedidos1,void *pedidos2,void *&pedidosFinal,int (*cmp)(void *,void*));
void *quitaLista(void *lista);
#endif /* BIBLIOTECAGENERICA_H */
