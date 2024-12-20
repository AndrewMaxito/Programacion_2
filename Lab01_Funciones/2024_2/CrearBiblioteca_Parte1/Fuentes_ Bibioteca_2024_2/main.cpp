
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
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "BibliotecaEstatica.h"
using namespace std;


int main(int argc, char** argv) {
    ifstream archPlatos,archRep,archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPlatos,"PlatosOfrecidos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archRep,"RepartidoresContratados.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"OrdenesDeCompra.txt");
    
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
    ofstream archRepPlato,archRepRepar;
    AperturaDeUnArchivoDeTextosParaEscribir(archRepPlato,"ReportePlato.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepRepar,"ReporteRepartidor.txt");
    
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
