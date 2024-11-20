

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

void Promociones::imprimePedidos() {
    ofstream arch("ReporteInicial.txt",ios::out);
    if (!arch) {
        cout << "No se pudo abrir el archivo ReporteInicial.txt"<<endl;
        exit(1);
    }
    
    arch << setw(40)<<' '<<"Reporte De Promociones"<<endl;
    imprimeLineas(arch,100,'=');
    arch << fixed <<setprecision(2);
    Lpedidos.imprimirLista(arch);
}

void Promociones::imprimeLineas(ofstream& arch, int cant,char car) {
    for (int i=0;i < cant;i++)arch<< car;
    arch <<endl;
}
//33713901,06/06/2019
//57263719,01/10/2020
void Promociones::actualizarPedidos() {
    ifstream arch("promocion.csv",ios::in);
    if (!arch){
        cout << "No se pudo abrir el archivo promocion.csv"<<endl;
        exit(1);
    }
    int dniPer,aa,mm,dd;
    int fecha;
    char c;
    while (true) {
        arch >> dniPer;
        if (arch.eof())break;
        arch >> c >> dd >> c >> mm >> c >> aa;
        fecha  = aa*10000+mm*100+dd;
        Lpedidos.modificarFlete(dniPer,fecha);
    }
}
