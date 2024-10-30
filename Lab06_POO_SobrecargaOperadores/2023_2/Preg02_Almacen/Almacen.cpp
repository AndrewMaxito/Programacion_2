/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.cpp
 * Author: alulab14
 * 
 * Created on 25 de octubre de 2024, 05:12 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Almacen.h"
#include "Cliente.h"
#include "Producto.h"
#include "Pedido.h"
#define NO_ENCONTRADO -1

Almacen::Almacen() {
    cantidad_clientes = 0;
    cantidad_productos = 0;
}

Almacen::~Almacen() {


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
    ifstream archCli("Clientes.csv", ios::in);
    if (!archCli.is_open()) {
        cout << "no se pudo abrir el archivo cliente" << endl;
        exit(1);
    }
    while (archCli >> arreglo_clientes[cantidad_clientes]) cantidad_clientes++;
}

void Almacen::cargar_productos() {
    ifstream archProd("Productos.csv", ios::in);
    if (!archProd.is_open()) {
        cout << "no se pudo abrir el archivo Producto" << endl;
        exit(1);
    }
    while (archProd >> arreglo_productos[cantidad_productos]) cantidad_productos++;
}

void Almacen::cargar_pedidos() {
    ifstream archPed("Pedidos.csv", ios::in);
    if (!archPed.is_open()) {
        cout << "no se pudo abrir el archivo Pedido" << endl;
        exit(1);
    }
    class Pedido ped;
    while (archPed >> ped) {
        char codProdPed[10];
        ped.GetCodigo(codProdPed);
        int posProd = buscarPosProducto(arreglo_productos, codProdPed);
        int posCli = buscarPosCliente(arreglo_clientes, ped.GetDni_cliente());
        arreglo_productos[posProd] += ped;
        arreglo_clientes[posCli] += ped;
    }
}

int Almacen::buscarPosProducto(const class Producto *arrProd, char *codProdPed) {
    for (int i = 0; i < cantidad_productos; i++) {
        char codProd[10];
        arrProd[i].GetCodigo(codProd);
        if (strcmp(codProd, codProdPed) == 0) return i;
    }
    cout << "No se encontro al producto " << codProdPed << endl;
    exit(1); //solo prueba
    return NO_ENCONTRADO;
}

int Almacen::buscarPosCliente(const class Cliente *arrClie, int dniPed) {
    for (int i = 0; i < cantidad_clientes; i++) {
        if (arrClie[i].GetDni() == dniPed) return i;
    }
    cout << "No se encontro al cliente " << dniPed << endl;
    exit(1); //solo prueba
    return NO_ENCONTRADO;
}

void Almacen::mostrar_datos() {
    ofstream arch("ReporteAlmacen.txt", ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo ReporteAlmacen" << endl;
        exit(1);
    }
    
    //Primero los clientes
    arch << left << setw(50) << ' ' << "Reporte Clientes " << endl;
    imprimirLineas(arch, 175, '=');
    arch << setw(30) << "Dni Cliente" << setw(45) << "Nombre Cliente" << setw(15) <<
            "Total gastado" << "Productos" << endl;
    imprimirLineas(arch, 175, '-');
    for (int i = 0; i < cantidad_clientes; i++) {
        arch << arreglo_clientes[i];
    }
    
    //Ahora los productos
    arch << left << setw(50) << ' ' << "Reporte Prodcutos " << endl;
    imprimirLineas(arch, 100, '=');
    arch << setw(17) << "Cod. Producto" << setw(53) << "Nombre Prodcuto" << setw(10) <<
            "Precio" << "Stock final" << endl;
    imprimirLineas(arch, 100, '-');
    for (int i = 0; i < cantidad_productos; i++) {
        arch << arreglo_productos[i];
        imprimirLineas(arch, 100, '.');
    }









}

void imprimirLineas(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++) arch << car;
    arch << endl;
}