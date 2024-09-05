/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.cpp
 * Author: andre
 * 
 * Created on 5 de septiembre de 2024, 02:20 PM
 */


#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "funcionesAux.h"
#include "bibliotecaEstatica.h"
#include "Estructuras.h"

void cargarPedido(ifstream &archPedido, struct Libro *arrLibro, struct Cliente *arrClientes) {

    int numPedido, dniCliente;
    char c,codigo[8];
    while (true) {
        archPedido >> numPedido;
        if (archPedido.eof())break;
        archPedido.get();
        struct LibroSolicitado lib;
        lib.numeroDePedido = numPedido;
        archPedido >> dniCliente>>c;
        while (archPedido.get() != '\n') {
            archPedido >> lib.codigoDelLibro;
            if (lib >> arrLibro) {
                int posCliente = buscarPosCliente(dniCliente,arrClientes);
                if (posCliente != -1) {
                    if (arrClientes[posCliente] >> lib){
                        ++arrClientes[posCliente];
                    }else cout<<"Ya esta lleno"<<endl;
                }
            }
        }
    }
}

int buscarPosCliente(int dniCliente,struct Cliente *arrClientes){
    
    for (int i = 0; arrClientes[i].dni !=0 ; i++) {
        if (arrClientes[i].dni == dniCliente ) return i;
    }
    return -1;
}