/* 
 * File:   main.cpp
 * Author: Max Bardales 20192406
 *
 * Created on 26 de abril de 2024, 13:24
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "BibliotecaEstatica.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"

int main(int argc, char** argv) {

    // Pregunta 1
    /*Lectura*/

    ifstream archLib;
    AperturaDeUnArchivoDeTextosParaLeer(archLib, "Libros.csv");
    struct Libro arrLibro[5];
    archLib >> arrLibro[0];


    ifstream archCliente;
    AperturaDeUnArchivoDeTextosParaLeer(archCliente, "Cientes.csv");
    struct Cliente cliente;
    archCliente >> cliente;

    /*Operaciones*/
    struct LibroSolicitado libroPedido {
        1, "IIM5175"
    };
    libroPedido >> arrLibro;
    cliente << libroPedido;
    ++cliente;

    /*Impresion*/

    ofstream archRepLib;
    AperturaDeUnArchivoDeTextosParaEscribir(archRepLib, "ReportePruebaLibros.txt");
    archRepLib << arrLibro[0];

    ofstream archRepCli;
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCli, "ReportePruebaCliente.txt");
    archRepCli << cliente;
    return 0;
}

