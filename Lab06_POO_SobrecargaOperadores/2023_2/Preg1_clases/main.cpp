
/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 25 de octubre de 2024, 04:24 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "Cliente.h"
#include "Producto.h"
#include "Pedido.h"

int main(int argc, char** argv) {
    ifstream archCli("Clientes.csv", ios::in);
    if (!archCli.is_open()) {
        cout << "no se pudo abrir el archivo cliente" << endl;
        exit(1);
    }
    ifstream archProd("Productos.csv", ios::in);
    if (!archProd.is_open()) {
        cout << "no se pudo abrir el archivo Producto" << endl;
        exit(1);
    }
    ifstream archPed("Pedidos.csv", ios::in);
    if (!archPed.is_open()) {
        cout << "no se pudo abrir el archivo Pedido" << endl;
        exit(1);
    }

    class Cliente arrClientes[200];
    class Producto arrProductos[200];
    class Pedido ped;

    //Lesctura
    int cantCli = 0;
    while (archCli >> arrClientes[cantCli]) cantCli++;

    int cantProd = 0;
    while (archProd >> arrProductos[cantProd]) cantProd++;

    archPed >> ped;
    //Agregacion
    //JXD-139,50375303 -> Este es el primer pedido es el prod en la pos 58 y es el cliente en las pos 89(viendo el archivo)
    /*Primero se hace producto += Pedido*/
    
    arrProductos[58] += ped; // este saca el precio y lo pone en el pedido
    arrClientes[89] += ped;
    
    //Impresion 
    
    
    ofstream archRepCli("reporteSimpleClientes.txt",ios::out);
    if (!archRepCli.is_open()){
        cout << "no se pudo abrir el archivo de reportes Clientes" <<endl;
        exit(1);
    }
    ofstream archRepPro("reporteSimpleProductos.txt",ios::out);
    if (!archRepPro.is_open()){
        cout << "no se pudo abrir el archivo de reportes producto" <<endl;
        exit(1);
    }
    
    archRepCli << arrClientes[89];
    archRepPro << arrProductos[58];
    return 0;
}

