
/* 
 * File:   PunterosGenericos.h
 * Author: andre
 *
 * Created on 10 de mayo de 2024, 15:45
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
#include <fstream>
using namespace std;

//Pregunta 1
void cargarclientes(void *&clientes);
void *leerDatosCliente(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char del);

//Pregunta 2 
void creareserva(void *&reserva);
void *leerDatosLibros(ifstream &arch);

//Pregunta 3 
void cargareservar(void *clientes,void *reserva);
int buscarLibro(void *reserva,char *codigo);
bool iguales(void *registro,char *codigo);
int buscarCliente(void *clientes, int dni);
void *cargarDatosPedidos(void *clientes, int posCliente);

#endif /* PUNTEROSGENERICOS_H */

