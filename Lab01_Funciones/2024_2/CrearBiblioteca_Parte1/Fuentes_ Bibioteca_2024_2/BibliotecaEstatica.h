

/* 
 * File:   BibliotecaEstatica.h
 * Author: andre
 *
 * Created on 16 de diciembre de 2024, 13:05
 */

#ifndef BIBLIOTECAESTATICA_H
#define BIBLIOTECAESTATICA_H
#include <fstream>

#include "Estructuras.h"
using namespace std;
void operator >>(ifstream& arch, Plato& plato);
void operator >>(ifstream& arch,Repartidor& repartidor);
void operator >>(ifstream& arch,Pedido& pedido);
bool operator <=(Pedido &pedido,Plato *arrPlato);
void operator <=(Repartidor *arrRepartidores, const Pedido &ped);
void operator ! ( OrdenDeCompra &ordenCompra);
void operator ! (Repartidor &repartidor);
void operator << (ofstream &arch, const Plato &plato);
void operator << (ofstream &arch, const Repartidor &repartidor);

void cargaDatosOrdenCompraNueva(OrdenDeCompra &ordenesDeCompra, const Pedido &ped);
void ingresarOrdenCompra(OrdenDeCompra &ordenesDeCompra, const Pedido &ped);
void imprimirPlatosSolicitados(ofstream &arch, const OrdenDeCompra &ordenes) ;


char *leerCadenaExacta(ifstream arch,char del);
int buscarPlato(const char *codigoDelPlato, const Plato *arrPlato);
int buscarPlatoSoli(const char* codigoDelPlato, const PlatoSolicitado *platosSolicitados, int cantPlatos);
int buscarRepartidor(const char*codigoDelRepartidor, const Repartidor *arrRepartidores);
int buscarOrdenRep(const int dniDelCliente, const OrdenDeCompra *arrOrdenesDeCompra, const int cantidadOrdenes);

#endif /* BIBLIOTECAESTATICA_H */
