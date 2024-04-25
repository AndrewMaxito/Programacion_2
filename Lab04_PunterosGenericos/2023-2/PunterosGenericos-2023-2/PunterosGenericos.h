
/* 
 * File:   PunterosGenericos.h
 * Author: andre
 *
 * Created on 25 de abril de 2024, 11:57
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
//pregunta 1
void cargarProductos(void *&productos);
void *leerDatosProducto(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char deli);
void cargarClientes(void *&clientes);
void *leerDatosCliente(ifstream &arch);


//Pregunta 2
void cargarPedidos(void *productos, void *clientes);
void *leerDatosPedido(ifstream &arch,void *productos,void *clientes, int &posCliente);



int buscaraProducta(void *productos,char *codigo);
bool iguales(void *registroProductos,char *codigo);

int buscaraCliente(void *clientes, int  dni);
bool iguales(void *registroClientes,int dni);

#endif /* PUNTEROSGENERICOS_H */

