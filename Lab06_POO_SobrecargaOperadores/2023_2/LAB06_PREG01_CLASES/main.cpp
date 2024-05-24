/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 18:51
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Cliente.h"
#include "Producto.h"
#include "Pedido.h"

int main(int argc, char** argv) {
    //Apertura de archivos
    ifstream archCli("Clientes.csv", ios::in);
    if (!archCli.is_open()) {
        cout << "No se pudoo abrir el archivo Clientes" << endl;
        exit(1);
    }

    ifstream archPro("Productos.csv", ios::in);
    if (!archCli.is_open()) {
        cout << "No se pudoo abrir el archivo Producto" << endl;
        exit(1);
    }
    ifstream archPed("Pedidos.csv", ios::in);
    if (!archCli.is_open()) {
        cout << "No se pudoo abrir el archivo Pedidos" << endl;
        exit(1);
    }
    ofstream archRe("ReporteInicial.txt", ios::out);
    if (!archCli.is_open()) {
        cout << "No se pudoo abrir el archivo Reporte" << endl;
        exit(1);
    }


    //Lectura
    Cliente clientes[200];
    int numClientes = 0;
    while (archCli >> clientes[numClientes])numClientes++;

    Producto productos[200];
    int numProductos = 0;
    while (archPro >> productos[numProductos])numProductos++;
    
    Pedido pedididos[600];
    int numPedidos = 0;
    while (archPed >> pedididos[numPedidos])numPedidos++;

    //Agregacion

    clientes[0] += pedididos[35]; //solo para probar que funciona aun no lo he implemnetado
    productos[66] += pedididos[35];
    
    //Impresion
    
    archRe << clientes[0];
    archRe << productos[66];
    









    return 0;
}

