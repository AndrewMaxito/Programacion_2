
/* 
 * File:   BibliotecaEstatica.cpp
 * Author: andre
 * 
 * Created on 16 de diciembre de 2024, 13:05
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Estructuras.h"
#include "BibliotecaEstatica.h"
using namespace std;
#define NO_ENCONTRADO -1

void operator>>(ifstream &arch, Plato &plato) {
    char basura[200];
    arch.getline(plato.codigo, 7, ',');
    if (arch.eof()) {
        strcpy(plato.codigo, "FIN"); //le pone un delimitador
        return;
    }
    arch.getline(plato.nombre, 60, ',');
    arch >> plato.precio;
    arch.getline(basura, 100); //lee hasta el salto de linea
    //inciializacion de los otros campos
    plato.totalDePedidos = 0;
    plato.totalRecaudado = 0;
}

void operator>>(ifstream& arch, Repartidor& repartidor) {
    arch.getline(repartidor.codigo, 7, ',');
    if (arch.eof()) {
        strcpy(repartidor.codigo, "FIN");
        return;
    }
    arch.getline(repartidor.nombre, 60, ',');
    arch.getline(repartidor.tipoDeVehiculo, 15);
    repartidor.cantidadDeOrdenes = 0;
    repartidor.pagoPorEntregas = 0;
}

void operator>>(ifstream& arch, Pedido& pedido) {
    int c;
    arch >> pedido.dniDelCliente;
    if (arch.eof())return;
    arch >> pedido.codigoDelPlato >> pedido.cantidad >>
            pedido.codigoDelRepartidor >> pedido.distanciaARecorrer;
    pedido.precio = 0;
}

bool operator<=(Pedido &pedido, Plato *arrPlato) {
    int posPlato = buscarPlato(pedido.codigoDelPlato, arrPlato);
    if (posPlato != NO_ENCONTRADO) {
        pedido.precio = arrPlato[posPlato].precio;
        arrPlato[posPlato].totalDePedidos++;
        arrPlato[posPlato].totalRecaudado += pedido.precio;
        return true;
    } else {
        return false;
    }
}

void operator<=(Repartidor *arrRepartidores, const Pedido &ped) {
    int posRepartidor = buscarRepartidor(ped.codigoDelRepartidor, arrRepartidores);
    //asumiendo que siempre encontrara al repartidor 

    int cantidadOrdenes = arrRepartidores[posRepartidor].cantidadDeOrdenes;
    int posOrdenCompra = buscarOrdenRep(ped.dniDelCliente, arrRepartidores[posRepartidor].ordenesDeCompra, cantidadOrdenes);

    if (posOrdenCompra == NO_ENCONTRADO) {
        posOrdenCompra = cantidadOrdenes;
        cargaDatosOrdenCompraNueva(arrRepartidores[posRepartidor].ordenesDeCompra[posOrdenCompra], ped);
        arrRepartidores[posRepartidor].cantidadDeOrdenes++;
    }

    ingresarOrdenCompra(arrRepartidores[posRepartidor].ordenesDeCompra[posOrdenCompra], ped);
}

void ingresarOrdenCompra(OrdenDeCompra &ordenesDeCompra, const Pedido &ped) {
    int cantPlatos = ordenesDeCompra.cantidadDePlatos;
    int posPlato = buscarPlatoSoli(ped.codigoDelPlato, ordenesDeCompra.platosSolicitados, cantPlatos);

    if (posPlato == NO_ENCONTRADO) {
        posPlato = ordenesDeCompra.cantidadDePlatos;
        strcpy(ordenesDeCompra.platosSolicitados[posPlato].codigo, ped.codigoDelPlato);
        ordenesDeCompra.platosSolicitados[posPlato].precio = ped.precio;
        ordenesDeCompra.cantidadDePlatos++;
    }
    
    ordenesDeCompra.platosSolicitados[posPlato].cantidad += ped.cantidad;
}

void operator!(OrdenDeCompra &ordenCompra) {
    for (int i = 0; i < ordenCompra.cantidadDePlatos; i++) {
        ordenCompra.montoPorCobrar += ordenCompra.platosSolicitados[i].precio*ordenCompra.platosSolicitados[i].cantidad;
    }
    if (ordenCompra.distancia < 8)ordenCompra.pagoPorEnvio = 10.50;
    else if (ordenCompra.distancia < 12)ordenCompra.pagoPorEnvio = 14.8;
    else if (ordenCompra.distancia < 20) ordenCompra.pagoPorEnvio = 23.6;
    else ordenCompra.pagoPorEnvio = 31.7;

}

void operator!(Repartidor &repartidor) {
    for (int i = 0; i < repartidor.cantidadDeOrdenes; i++) {
        repartidor.pagoPorEntregas += repartidor.ordenesDeCompra[i].pagoPorEnvio;
    }
}

void operator<<(ofstream &arch, const Plato &plato) {
    arch << left << setw(18) << plato.codigo << setw(60) << plato.nombre <<
            right << setw(20) << plato.precio << setw(20) <<
            plato.totalDePedidos << setw(15) << plato.totalRecaudado << endl;
}

void operator<<(ofstream &arch, const Repartidor &repartidor) {
    arch << left << setw(15) << repartidor.codigo << setw(60) << repartidor.nombre <<
            setw(20) << repartidor.tipoDeVehiculo << repartidor.pagoPorEntregas << endl;
    arch << "ORDDENES ENTREGADAS: " << endl;
    if (repartidor.cantidadDeOrdenes == 0) {
        arch << "No cuenta con envios" << endl;
    } else {
        
        for (int i = 0; i < repartidor.cantidadDeOrdenes; i++) {
            arch << left << setw(6) << ' ' << setw(15) << repartidor.ordenesDeCompra[i].dniDelCliente <<
                    right << setw(15) << repartidor.ordenesDeCompra[i].distancia <<
                    setw(15) << repartidor.ordenesDeCompra[i].montoPorCobrar << setw(15) <<
                    repartidor.ordenesDeCompra[i].pagoPorEnvio << endl;
            imprimirPlatosSolicitados(arch, repartidor.ordenesDeCompra[i]);
        }
    }
}

void imprimirPlatosSolicitados(ofstream &arch, const OrdenDeCompra &ordenes) {
    arch << left << setw(6) << ' ' << "Platos soliciotados: " << endl;
    for (int i = 0; i < ordenes.cantidadDePlatos; i++) {
        arch << left << setw(6) << ' ' << setw(2) << "-" << setw(15) <<
                ordenes.platosSolicitados[i].codigo << right << setw(15) <<
                ordenes.platosSolicitados[i].precio << setw(15) << ordenes.platosSolicitados[i].cantidad <<
                setw(15)<<ordenes.platosSolicitados[i].precio*ordenes.platosSolicitados[i].cantidad<<endl;
    }
}

int buscarPlatoSoli(const char* codigoDelPlato, const PlatoSolicitado *platosSolicitados, int cantPlatos) {
    for (int i = 0; i < cantPlatos; i++) {
        if (strcmp(platosSolicitados[i].codigo, codigoDelPlato) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void cargaDatosOrdenCompraNueva(OrdenDeCompra &ordenesDeCompra, const Pedido &ped) {
    ordenesDeCompra.dniDelCliente = ped.dniDelCliente;
    ordenesDeCompra.distancia = ped.distanciaARecorrer;
    ordenesDeCompra.cantidadDePlatos = 0;
    ordenesDeCompra.montoPorCobrar = 0;
    ordenesDeCompra.pagoPorEnvio = 0;
}

int buscarOrdenRep(const int dniDelCliente, const OrdenDeCompra *arrOrdenesDeCompra, const int cantidadOrdenes) {
    for (int i = 0; i < cantidadOrdenes; i++) {
        if (arrOrdenesDeCompra[i].dniDelCliente == dniDelCliente)return i;
    }
    return NO_ENCONTRADO;
}

int buscarRepartidor(const char *codigoDelRepartidor, const Repartidor *arrRepartidores) {
    for (int i = 0; strcmp(arrRepartidores[i].codigo, "FIN") != 0; i++) {
        if (strcmp(arrRepartidores[i].codigo, codigoDelRepartidor) == 0)return i;
    }
    cout << "No se encontro el Repartidor" << codigoDelRepartidor << endl;
    return NO_ENCONTRADO;

}

int buscarPlato(const char *codigoDelPlato, const Plato *arrPlato) {
    for (int i = 0; strcmp(arrPlato[i].codigo, "FIN") != 0; i++) {
        if (strcmp(arrPlato[i].codigo, codigoDelPlato) == 0)return i;
    }
    cout << "No se encontro el plato" << endl;
    return NO_ENCONTRADO;
}

char *leerCadenaExacta(ifstream arch, char del) {
    char buff[100], *ptr;
    arch.getline(buff, 100, del);
    if (arch.eof())return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}



