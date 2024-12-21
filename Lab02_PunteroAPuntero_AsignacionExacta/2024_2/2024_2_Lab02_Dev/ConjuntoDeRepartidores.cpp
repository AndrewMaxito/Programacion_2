/* 
 * Archivo: ConjuntoDeRepartidores.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:44
 */

#include <iostream>
#include <fstream>
#include "ConjuntoDeRepartidores.hpp"
#include "Comunes.hpp"

using namespace std;

void cargar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *nombre_de_archivo){
    ifstream archivo_de_repartidores(nombre_de_archivo,ios::in);
    if (!archivo_de_repartidores)
    {
        cout << "No se pudo abrir el archivo " << nombre_de_archivo << endl;
        exit(1);
    }
    archivo_de_repartidores >> conjuntoDeRepartidores;
    archivo_de_repartidores.close();
}

void operator>>(istream &archivo_de_repartidores, ConjuntoDeRepartidores &conjuntoDeRepartidores){   
    //JNV387,Justino Norabuena Virginia Karina,Motocicleta
    Repartidor buffRepartidores[100];
    int cantRep = 0;
    char *codigo,c;

    while (true) {
        codigo = leerCadenaExacata(archivo_de_repartidores, ',');
        if (codigo == nullptr)break;
        buffRepartidores[cantRep].codigo = codigo;
        buffRepartidores[cantRep].nombre = leerCadenaExacata(archivo_de_repartidores, ',');
        buffRepartidores[cantRep].vehiculo = leerCadenaExacata(archivo_de_repartidores, '\n');
        cantRep++;
    }

    conjuntoDeRepartidores.conjunto_de_datos = new Repartidor[cantRep];
    conjuntoDeRepartidores.cantidad = cantRep;
    for (int i = 0; i < cantRep; i++)
    {
        conjuntoDeRepartidores.conjunto_de_datos[i] = buffRepartidores[i];
    }

}



void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    
}