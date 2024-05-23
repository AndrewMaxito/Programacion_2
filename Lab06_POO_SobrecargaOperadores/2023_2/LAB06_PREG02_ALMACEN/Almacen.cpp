
/* 
 * File:   Almacen.cpp
 * Author: andre
 * 
 * Created on 22 de mayo de 2024, 19:07
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#define CANT_LIN 180

#include "Almacen.h"
#include "Pedido.h"

Almacen::Almacen() {
    cantidad_clientes = 0;
    cantidad_productos = 0;
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::cargar_clientes() {
    ifstream arch("Clientes.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudoo abrir el archivo Clientes" << endl;
        exit(1);
    }

    while (arch >> arreglo_clientes[cantidad_clientes]) {
        char cadena[100];
        arreglo_clientes[cantidad_clientes].GetNombre(cadena);

        cantidad_clientes++;
    }

}

void Almacen::cargar_producto() {
    ifstream arch("Productos.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudoo abrir el archivo Productos" << endl;
        exit(1);
    }


    while (arch >> arreglo_producto[cantidad_productos])cantidad_productos++;
}

void Almacen::cargar_pedidos() {
    ifstream arch("Pedidos.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudoo abrir el archivo Pedidos" << endl;
        exit(1);
    }
    Pedido pedididos;
    while (true) {
        int posP = 0, posC = 0;
        if (!(arch >> pedididos))break;

        //buscar pos producto para añadirle el precio
        for (int i = 0; i < cantidad_productos; i++) {
            char codigoA[8], codigoPed[8];
            arreglo_producto[i].GetCodigo(codigoA);
            pedididos.GetCodigo(codigoPed);
            if (strcmp(codigoA, codigoPed) == 0)posP = i;
        }
        //
        for (int i = 0; i < cantidad_clientes; i++) {
            if (arreglo_clientes[i].GetDni() == pedididos.GetDni_cliente())posC = i;
        }
        pedididos.SetPrecio_producto(arreglo_producto[posP].GetPrecio());
        arreglo_clientes[posC] += pedididos;
        arreglo_producto[posP] += pedididos;
    }
}

void Almacen::mostrar_datos() {
    ofstream archRe("ReporteInicial.txt", ios::out);
    if (!archRe.is_open()) {
        cout << "No se pudoo abrir el archivo Reporte" << endl;
        exit(1);
    }
    archRe << setw(70)<< "Reporte de CLIENTES" << endl;
    imprimirLineas(archRe, CANT_LIN, '=');

    for (int i = 0; i < cantidad_clientes; i++) {
        archRe << arreglo_clientes[i];
        imprimirLineas(archRe, CANT_LIN, '-');
    }
    archRe<<endl<<endl<<endl;
    archRe << setw(70)<<"Reporte de Productos" << endl;
    imprimirLineas(archRe, CANT_LIN, '=');
    for (int i = 0; i < cantidad_productos; i++) {
        archRe << arreglo_producto[i];
        imprimirLineas(archRe, CANT_LIN, '-');
    }
}

void imprimirLineas(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++)arch << car;
    arch << endl;
}
