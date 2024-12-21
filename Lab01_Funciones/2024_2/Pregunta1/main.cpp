
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 16 de diciembre de 2024, 13:00
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Estructuras.h"
#include "BibliotecaEstatica.h"
using namespace std;


int main(int argc, char** argv) {
    ifstream archPlatos("PlatosOfrecidos.csv", ios::in);

    if (not archPlatos.is_open())
    {
        cout << "No se pudo abrir el archvo PlatosOfrecidos.csv" << endl;
        exit(1);
    }
    ifstream archRep("RepartidoresContratados.csv", ios::in);
    if (not archRep.is_open())
    {
        cout << "No se pudo abrir el archvo RepartidoresContratados.csv" << endl;
        exit(1);
    }
    ifstream archPed("OrdenesDeCompra.txt",ios::in);
    if (not archPed.is_open())
    {
        cout << "No se pudo abrir el archvo OrdenesDeCompra.tx" << endl;
        exit(1);
    }

    
    //Lectura
    
    Plato arrPlatos[120];
    int cantPlatos=0;
    while (true) {
        archPlatos >> arrPlatos[cantPlatos];
        if (archPlatos.eof())break;
        cantPlatos++;
    }
    
    Repartidor arrRepartidores[100];
    int cantRepartidores=0;
    while (true) {
        archRep >> arrRepartidores[cantRepartidores];
        if (archRep.eof())break;
        cantRepartidores++;
    }
    
    Pedido pedido;
    
    while (true) {
        archPed >> pedido;
        if(archPed.eof())break;
        if(pedido <= arrPlatos){
            arrRepartidores <= pedido;
        }
    }
    
    //Calcula las ordenes de pedido
    
    for (int i = 0; strcmp(arrRepartidores[i].codigo,"FIN")!=0 ; i++) {
        for (int j = 0; j < arrRepartidores[i].cantidadDeOrdenes; j++) {
            !arrRepartidores[i].ordenesDeCompra[j];
        }
        !arrRepartidores[i];
    }
    
    
    //Lectura
    ofstream archRepPlato("ReportePlato.txt");
    if (not archPed.is_open())
    {
        cout << "No se pudo abrir el archvo ReportePlato.txt" << endl;
        exit(1);
    }
    ofstream archRepRepar("ReporteRepartidor.txt");
    if (not archPed.is_open())
    {
        cout << "No se pudo abrir el archvo ReporteRepartidor.txt" << endl;
        exit(1);
    }
    
    archRepPlato << left << setw(20) << "Codigo Plato" <<setw(75)<<"Nombre del Plato"<<
            setw(15)<<"Precio "<<setw(15)<<"Total Pedidos"<<"Monto Recaudado"<<endl;
    archRepRepar<<fixed<<setprecision(2);

    for (int i = 0;strcmp(arrPlatos[i].codigo,"FIN")!=0 ; i++) {
        archRepPlato << arrPlatos[i];
    }
    
    for (int i = 0; strcmp(arrRepartidores[i].codigo,"FIN")!=0; i++) {
        archRepRepar << arrRepartidores[i];
    }

    return 0;
}
