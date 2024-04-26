#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "MuestraPunteros.h"

enum {
    CODIGO, DESCRIP, PRECIO, TIPO
};

enum {
    DNI, NOMBRE, LISTAPED, LINEAC
};

void imprimeProductos(void *productos) {
    ofstream arch("ReporteProductos.txt", ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo ReporteProductos" << endl;
        exit(1);
    }
    void **registroProd = (void **) productos;

    arch << right << setw(60) << "Lista de Productos" << endl;
    for (int i = 0; registroProd[i]; i++) {
        leerProducto(arch, registroProd[i]);
    }
}

void leerProducto(ofstream &arch, void *registroProd) {
    void **registroDatosProducto = (void **) registroProd;
    char *codigo = (char *) (registroDatosProducto[CODIGO]),
            *descripcion = (char *) (registroDatosProducto[DESCRIP]),
            *tipo = (char *) (registroDatosProducto[TIPO]);
    double *precio = (double *) (registroDatosProducto[PRECIO]);
    arch << left << setw(10) << codigo << setw(60) << descripcion << right << setw(10) << *precio <<
            setw(5) << *tipo << endl;
}

void imprimeClientes(void *clientes) {
    ofstream arch("ReporteCliente.txt", ios::out);
    if (not arch.is_open()) {
        cout << "No se puedo abrir el archivo reporte cliente" << endl;
        exit(1);
    }


    void **registroClientes = (void **) clientes;
    arch << right << setw(60) << "Datos cliente" << endl;
    for (int i = 0; registroClientes[i]; i++) {
        leerCliente(arch, registroClientes[i]);
    }

}

void leerCliente(ofstream &arch, void *registroClientes) {
    void **datosCliente = (void **) registroClientes;
    int *dni = (int *) (datosCliente[DNI]), *linea = (int *) (datosCliente[LINEAC]);
    char *nombre = (char *) (datosCliente[NOMBRE]);
    arch << left << setw(15) << *dni << setw(50) << nombre << right << setw(10) << *linea << endl;
}