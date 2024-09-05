

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 5 de septiembre de 2024, 01:01 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>


using namespace std;
#include "bibliotecaEstatica.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"


int main(int argc, char** argv) {
    
    ifstream archLibro,archCliente;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLibro,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archCliente,"Cientes.csv");
    
    
    struct Libro arrLibro[100]; // solo prueba
    struct Cliente arrClientes[100]; //solo prueba
    struct LibroSolicitado libSoli {1,"IIM5175"};
    
    //Lectura
    archLibro >> arrLibro[0]; //solo un libro
    archCliente >> arrClientes[0]; //solo un Cliente
    
    
    //Operaciones
    libSoli >> arrLibro;
    arrClientes[0] >> libSoli;
    ++arrClientes[0];
    
    //impresion
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"ReporteSimple.txt");
    
    archReporte << arrLibro[0];
    archReporte << arrClientes[0];
    return 0;
}

