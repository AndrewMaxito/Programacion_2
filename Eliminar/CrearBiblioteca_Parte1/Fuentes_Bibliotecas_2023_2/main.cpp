/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 4 de abril de 2024, 20:25
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "BibliotecaEstatica.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"


int main(int argc, char** argv) {
    
    
    //Lectura
    ifstream archCliente;
    AperturaDeUnArchivoDeTextosParaLeer(archCliente,"Clientes.csv");
    struct Cliente cliente[300];
    archCliente >> cliente[0];
    archCliente >> cliente[1];
    archCliente >> cliente[2];
    
    
    ifstream archPro;
    AperturaDeUnArchivoDeTextosParaLeer(archPro,"Productos.csv");
    struct Producto prod[300];
    archPro >> prod[0];
    archPro >> prod[1];
//    cout<<prod[0].codigo<<prod[0].descripcion<<prod[0].precio<<prod[0].stock<<endl;
//    cout<<prod[1].codigo<<prod[1].descripcion<<prod[1].precio<<prod[1].stock<<endl;
    
    ifstream archPedi;
    AperturaDeUnArchivoDeTextosParaLeer(archPedi,"Pedidos.csv");
    struct Pedido pedi{"BIT-434",16552775,5.2};
//     archPedi >> pedi[0];
//     archPedi >> pedi[1];
//    cout<<pedi[0].CodigoProducto<<" "<<pedi[0].dniCliente<<endl;
//    cout<<pedi[1].CodigoProducto<<pedi[1].dniCliente<<endl;
    
    
    //Agregacion
    
    cliente +=pedi;
    prod +=pedi;
    
    
    //Impresion
    ofstream archRepCliente;
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCliente,"PruebaCliente.txt");
    archRepCliente << cliente[0];
    archRepCliente << cliente[1];
    
    
    ofstream archRepProdu;
    AperturaDeUnArchivoDeTextosParaEscribir(archRepProdu,"PruebaProducto.txt");
    
    archRepProdu << prod[0];
    
    return 0;
}

