/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 9 de mayo de 2024, 13:03
 */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"

int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidoAtendidos;

    //Pregunta 1
    lecturaDeLibros("Libros.csv", libros, stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros, stock);

    //Pregunta 2
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros, pedidoAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros, stock);

    //    for (int i = 0; pedidosClientes[i]; i++) {
    //        cout << i << ") " << pedidosClientes[i][0] << endl;
    //        for (int j = 2; pedidosClientes[i][j]; j++) {
    //            cout << pedidosClientes[i][j] << " ";
    //        }
    //        cout << endl << endl;
    //    }

    //    for (int i = 1; pedidosLibros[i] ; i++) {
    //        cout << i << ")" << endl;
    //
    //        if (strcmp(pedidosLibros[i][0],"XXXXXX")==0){
    //            cout<<"No tiene ningun pedido";
    //        }else{
    //            for (int j=0;strcmp(pedidosLibros[i][j],"XXXXXX")!=0;j++){
    //                cout<<pedidosLibros[i][j]<<"  ";
    //            }
    //        }
    //        cout << endl;
    //    }

    //pregunta 3 
    ordenarPedidosClientes(pedidosClientes);
    //    cout << "Ordenado----------------------------------------" << endl;
    //    for (int i = 0; pedidosClientes[i]; i++) {
    //        cout << i << ") " << pedidosClientes[i][0] << endl;
    //        for (int j = 2; pedidosClientes[i][j]; j++) {
    //            cout << pedidosClientes[i][j] << " ";
    //        }
    //        cout << endl << endl;
    //    }

    //Pregunta 4
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt", pedidosClientes, pedidosLibros,
            pedidoAtendidos);
    return 0;
}

