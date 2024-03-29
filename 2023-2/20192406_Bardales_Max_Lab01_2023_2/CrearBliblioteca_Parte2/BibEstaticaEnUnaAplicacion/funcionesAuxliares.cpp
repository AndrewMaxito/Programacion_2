#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Estructuras.h"
#include "sobreCargaOpera.h"
#include "AperturaDeArchivos.h"



void leerClientes(struct Cliente *clientes,const char *nombArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    
    int cant = 0;
    while (arch >> clientes[cant]) cant++;
    clientes[cant].dni = 0; //delimitador
    
 /*Otra forma (no se aprovecha el bool )*/
 //   int cant = 0;    
//    struct Cliente cliIng;     
//    while(true){
//        arch >> cliIng;
//        if(arch.eof())break;
//        clientes[cant] = cliIng; // añado al arreglo      
//        cant ++;
//    }
//    clientes[cant].dni = 0;  //delimitador
//    cout << cant;
}

void leerProductos(struct Producto *productos,const char *nombArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
 
    int cant = 0;
    while (arch >> productos[cant]) cant++;
    strcpy(productos[cant].codigo,"XXXXXXX"); //delimitador
        
/*Otra forma (no se aprovecha el bool )*/    
//    struct Producto prodIng;
//    while(true){
//        arch >> prodIng;
//        
//        if(arch.eof())break;
//        productos[cant] = prodIng;
//        
//        cant ++;
//    }
//    strcpy(productos[cant].codigo,"XXXXXXX"); //delimitador
}

void completarClientesProductos(struct Cliente *clientes,struct Producto *productos,
        const char *nombArch){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    
    struct Pedido pedido;
    while(arch >> pedido){
//        arch >> pedido;
//        if(arch.eof())break;
        productos+=pedido; //primero los productos para que se le asigne el precio
        clientes+=pedido;
    } 
}

void elaborarReporte(struct Cliente *clientes,struct Producto *productos,const char *nombArch){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    for(int i=0;clientes[i].dni !=0 ;i++){
        arch <<  clientes[i] ;
    }
    arch << endl;
    
    for(int i=0;strcmp(productos[i].codigo,"XXXXXXX")!=0 ;i++){
        arch <<  productos[i] ;
    }
    
}