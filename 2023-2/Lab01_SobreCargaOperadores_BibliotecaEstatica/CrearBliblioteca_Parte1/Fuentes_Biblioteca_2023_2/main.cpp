/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 28 de marzo de 2024, 12:57
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include <fstream>
#include "sobreCargaOpera.h"
#include "Estructuras.h"

int main(int argc, char** argv) {
    
    /*Lectura*/ //-----------------------------------------------------------
    ifstream archCli("Clientes.csv",ios::in);
    if (not archCli.is_open()){
        cout<<"Error no se pudo abrir el archivo Clientes.csv"<<endl;
        exit (1);
    }
    struct  Cliente cliente[300];
    
    archCli >> cliente[0];
//    archCli >> cliente[1];
//    cout << cliente[0].dni <<" "<< cliente[0].nombre<<" "<<cliente[0].telefono<<endl;

    
    
    ifstream archPedido("Pedidos.csv",ios::in);
    if (not archPedido.is_open()){
        cout<<"Error no se pudo abrir el archivo Pedidos.csv"<<endl;
        exit (1);
    }
    
        struct Pedido pedido {"BIT-434",79464412,10};
//    struct Pedido pedido;
//    archPedido >> pedido; //prueba de lectura


    
    ifstream archProd("Productos.csv",ios::in);
    if (not archProd.is_open()){
        cout<<"Error no se pudo abrir el archivo Productos.csv"<<endl;
        exit (1);
    }
    struct Producto producto[300],ProdIngre;
    archProd >> producto[0];


    
    /*agregacion*/ //=========================================================
    producto += pedido;
    cliente += pedido;
    
    
    /*Impresion*/ //----------------------------------------------------------  
    ofstream repCliente("PruebaCliente.txt",ios::out);
    if (not repCliente.is_open()){
        cout<<"Error no se pudo abrir el archivo PruebaCliente.txt"<<endl;
        exit (1);
    }
    ofstream repProdu("PruebaProducto.txt",ios::out);
    if (not repProdu.is_open()){
        cout<<"Error no se pudo abrir el archivo PruebaProducto.txt"<<endl;
        exit (1);
    }
   
        repCliente << cliente[0]; 
        repProdu << producto[0];
        
    return 0;
}

