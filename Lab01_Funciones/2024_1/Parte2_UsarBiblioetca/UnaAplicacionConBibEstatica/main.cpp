/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 26 de abril de 2024, 16:05
 */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "AperturaDeArchivos.h"
#include "BibliotecaEstatica.h"
#include "Estructuras.h"

int main(int argc, char** argv) {
    //a)
    ifstream archLib;
    AperturaDeUnArchivoDeTextosParaLeer(archLib, "Libros.csv");
    struct Libro arrLibro[400];
    int i = 0;
    while (archLib >> arrLibro[i])i++;
    strcpy(arrLibro[i].codigo, "FIN");

    //b)
    int cantClie = 0;
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli, "Cientes.csv");
    struct Cliente arrClientes[200];
    while (archCli >> arrClientes[cantClie])cantClie++;

    //c)

    ifstream archPedi;
    AperturaDeUnArchivoDeTextosParaLeer(archPedi, "Pedidos.txt");
    struct LibroSolicitado pedido;
    int numPedido, dniCliente;
    //000001,34460612,  CRY6839    VYG3594
    while (true) {
        archPedi >> numPedido;
        if (archPedi.eof()) break;
        archPedi.get();
        archPedi >> dniCliente;
        archPedi.get();

        int posCliente = -1;
        for (int j = 0; j < cantClie; j++)
            if (arrClientes[j].dni == dniCliente) {
                posCliente = j;
                break;
            }
        if (posCliente == -1) {
            cout << "No se encontro al cliente" << endl;
            break;
        }
        while (archPedi.get() != '\n') {
            archPedi >> pedido.codigoDelLibro;
            pedido.numeroDePedido = numPedido;
            pedido >> arrLibro;
            if (arrClientes[posCliente] << pedido)++arrClientes[posCliente];
        }
    }
    
    //d)
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "ReporteFinal.txt");

    archReporte << setw(50) << "Reporte de Libros " << endl;
    for (int k = 0; strcmp(arrLibro[k].codigo, "FIN") != 0; k++) archReporte << arrLibro[k];
    archReporte << endl << endl;
    ;
    archReporte << setw(50) << "Reporte de Clientes " << endl;
    for (int k = 0; k < cantClie; k++) {
        archReporte << arrClientes[k];
        archReporte << endl;
    }
    return 0;
}

