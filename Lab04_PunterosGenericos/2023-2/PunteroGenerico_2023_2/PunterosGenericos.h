

/* 
 * File:   PunterosGenericos.h
 * Author: andre
 *
 * Created on 26 de setiembre de 2024, 15:16
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

//P1
void cargaProducto(void *&productos);
void *cargaDatosProducto(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char deli);

void cargaClientes(void *&cliente);
void *cargarDatosClinete(ifstream &arch);

//P2
void cargarPedidos(void *productos,void *cliente);
int buscarProducto(void *productos, const char *codProDat);
int buscarCliente(void *cliente, const int dniDat);
void aumnetarEspacios(void *&pedidosAcep,int &cant, int &cap);

//P3
void imprimeReporte(void *cliente);
void imprimirLineas(ofstream &arch,int cant,char car);

#endif /* PUNTEROSGENERICOS_H */
