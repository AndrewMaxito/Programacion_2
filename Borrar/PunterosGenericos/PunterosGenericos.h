

/* 
 * File:   PunterosGenericos.h
 * Author: andre
 *
 * Created on 21 de setiembre de 2024, 23:29
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
void cargarProductos(void *&productos);
void *procesarDatosProductos(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char del);
void cargarClientes(void *&clientes);
void *procesarDatosClientes(ifstream &arch);
void aumentarEspacios(void **&regClientes,int &cant,int &cap);

//Pregunta 2 
void cargaPedidos(const void *productos,void *clientes);
int buscarProducto(const void *productos, const char *bufCodigo);
int buscarCliente(const void *clientes, const int dniCliPed);
#endif /* PUNTEROSGENERICOS_H */
