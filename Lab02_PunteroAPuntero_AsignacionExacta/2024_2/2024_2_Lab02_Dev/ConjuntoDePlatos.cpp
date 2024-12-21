/* 
 * Archivo: ConjuntoDePlatos.cpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 22:50
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "ConjuntoDePlatos.hpp"
#include "Comunes.hpp"
using namespace std;

void cargar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos, const char *nombre_de_archivo) {
    ifstream archivo_de_platos(nombre_de_archivo,ios::in);
    
    if (not archivo_de_platos.is_open())
    {
        cout << "No se pudo abrir el archivo " << nombre_de_archivo << endl;
        exit(1);
    }
    //COmpletar Codigo (Parte de la pregunta)
    archivo_de_platos >> conjuntoDePlatos;

    archivo_de_platos.close();
}

void operator>>(istream &archivo_de_platos, ConjuntoDePlatos &conjuntoDePlatos) {
    Plato buffPlato[150];
    int cantidad = 0;

    char * codigo, c;
    //AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
    while (true) {
        codigo = leerCadenaExacata(archivo_de_platos,',');
        if (codigo == nullptr)break;
        buffPlato[cantidad].codigo = codigo;
        buffPlato[cantidad].nombre= leerCadenaExacata(archivo_de_platos, ',');
        archivo_de_platos >> buffPlato[cantidad].precio >> c;
        buffPlato[cantidad].tipo= leerCadenaExacata(archivo_de_platos,'\n');
        cantidad++;
    }
    conjuntoDePlatos.conjunto_de_datos = new Plato[cantidad];
    conjuntoDePlatos.cantidad = cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        conjuntoDePlatos.conjunto_de_datos[i] = buffPlato[i];
    }
    //No hace falta un delimitador ya que este cuenta con un atributo que guarda las cantidadades
}


void liberar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos) {

}

double operator+=(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {    
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].precio;
    }
}

char* operator==(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].nombre;
    }
    return nullptr;
}