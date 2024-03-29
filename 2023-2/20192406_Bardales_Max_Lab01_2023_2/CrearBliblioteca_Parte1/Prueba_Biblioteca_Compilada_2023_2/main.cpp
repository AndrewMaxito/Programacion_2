
#include <iostream>
#include <iomanip>

using namespace std;
#include <fstream>
#include "sobreCargaOpera.h"
#include "Estructuras.h"

int main(int argc, char** argv) {
    
    //lectura
    ifstream archCli("Clientes.csv",ios::in);
    if (not archCli.is_open()){
        cout<<"Error no se pudo abrir el archivo Clientes.csv"<<endl;
        exit (1);
    }
    struct  Cliente cliente[300];
    int i=0;
    while (archCli >> cliente[i] ){
        i++;  
    }
//    archCli >> cliente[0];
//    archCli >> cliente[1];
//    cout << cliente[0].dni <<" "<< cliente[0].nombre<<" "<<cliente[0].telefono<<endl;
//    cout << cliente[131].dni <<" "<< cliente[132].nombre<<" "<<cliente[132].telefono<<endl;
    
    
    ifstream archPedido("Pedidos.csv",ios::in);
    if (not archPedido.is_open()){
        cout<<"Error no se pudo abrir el archivo Pedidos.csv"<<endl;
        exit (1);
    }
    struct Pedido pedido;
    archPedido >> pedido;
//    archPedido >> pedido[1];
//    archPedido >> pedido[2];
//    cout << pedido[0].CodigoProducto <<" "<< pedido[0].dniCliente<< endl;
//    cout << pedido[1].CodigoProducto <<" "<< pedido[1].dniCliente<< endl;
//    cout << pedido[2].CodigoProducto <<" "<< pedido[2].dniCliente<< endl;

    
    ifstream archProd("Productos.csv",ios::in);
    if (not archProd.is_open()){
        cout<<"Error no se pudo abrir el archivo Productos.csv"<<endl;
        exit (1);
    }
    struct Producto producto[300],ProdIngre;
    archProd >> producto[0];
    archProd >> producto[1];
    archProd >> producto[2];
//    cout << producto[0].codigo << " " << producto[0].descripcion << producto[0].precio << producto[0].stock << endl;
//    cout << producto[1].codigo << " " << producto[1].descripcion << producto[1].precio << producto[1].stock << endl;
//    cout << producto[2].codigo << " " << producto[2].descripcion << producto[2].precio << producto[2].stock << endl;

    
    /*agregacion*/
    
    cliente += pedido;
    producto += pedido;
    
    /*Impresion*/ //--------------------------------------------------------------
    
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

//    for (int j=0;i>j;j++){
//        repCliente << cliente[j];
//        
//    }
    
        repCliente << cliente[0]; 
        repProdu << producto[0];
    return 0;
}

