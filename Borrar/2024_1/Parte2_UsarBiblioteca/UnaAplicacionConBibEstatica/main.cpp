
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#include "bibliotecaEstatica.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"


#include "funcionesAux.h"

int main(int argc, char** argv) {
    
    ifstream archLibro, archCliente,archPedido;
    AperturaDeUnArchivoDeTextosParaLeer(archLibro, "Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archCliente, "Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedido, "Pedidos.txt");
    
    struct Libro arrLibro[300];
    struct Cliente arrClientes[100];
    
    
    struct LibroSolicitado libroSol;


    int cantLibros = 0;
    while (archLibro >> arrLibro[cantLibros]) cantLibros++;
    strcpy(arrLibro[cantLibros].codigo, "FIN");

    int cantClientes = 0;
    while (archCliente >> arrClientes[cantClientes]) cantClientes++;
    arrClientes[cantClientes].dni = 0;
    
    cargarPedido(archPedido,arrLibro,arrClientes);
    
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    
    
    archReporte << setw(50)<<"Reporte de Libros"<<endl;
    for (int i = 0; strcmp(arrLibro[i].codigo,"FIN")!=0; i++) {
        archReporte << arrLibro[i];
    }
    archReporte << setw(50)<<"Reporte de Clientes"<<endl;
    for (int i = 0; arrClientes[i].dni != 0; i++) {
        archReporte << arrClientes[i];
    }
    
    return 0;
}

