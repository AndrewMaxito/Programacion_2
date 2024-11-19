

/* 
 * File:   Promociones.cpp
 * Author: andre
 * 
 * Created on 19 de noviembre de 2024, 16:18
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Promociones.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"

void Promociones::leePedidos(){
    ifstream arch("pedidos5.csv",ios::in);
    if (!arch){
        cout << "No se pudo abrir el archivo pedidos5.csv"<<endl;
        exit(1);
    }
    //118050,10,PAPAYA,8,8,79475585,16/12/2019
    int codigo;
    while (true) {
        arch >> codigo;
        if (arch.eof())break;
        arch.get();
        class Pedido *pedido;

        if (codigo < 400000) {
            pedido = new PedidoEspecial;
        } else if(codigo < 600000) {
            pedido = new PedidoUsual;
        }else pedido = new PedidoEventual;
        
        pedido->lee(arch,codigo);
        //Para la lista        
        Lpedidos.insertarOrdenado(pedido);
    }
}