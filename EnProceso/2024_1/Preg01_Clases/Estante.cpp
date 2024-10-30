
/* 
 * File:   Estante.cpp
 * Author: andre
 * 
 * Created on 30 de octubre de 2024, 11:30
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define NO_ENCONTRADO -1
#include "Estante.h"

Estante::Estante() {
    codigo = nullptr;
    anchura = 0;
    altura = 0;
    //aqui no se si definir un espacios = new Espacio [10];
    espacios = new class Espacio[20];
    cantidad_libros = 0;
}

Estante::~Estante() {
    if (codigo != nullptr) delete[] codigo;
    if (espacios != nullptr) delete[] espacios; //esto no estoy seguro
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* cad) {
    if (codigo != nullptr)delete[] codigo;
    codigo = new char [strlen(cad) + 1];
    strcpy(codigo, cad);

}

void Estante::GetCodigo(char *cad) const {
    if (codigo == nullptr) cad[0] = 0;
    else strcpy(cad, codigo);
}

void operator>>(ifstream &arch, class Estante &estan) {
    //AAA, 6, 4
    char codigo[10], c;
    int altura, anchura;

    arch.getline(codigo, 10, ',');
    if (arch.eof())return;
    arch >> altura >> c >> altura;
    arch.get(); //salto de linea

    //
    estan.SetCodigo(codigo);
    estan.SetAltura(altura);
    estan.SetAnchura(anchura);

    estan.espaciosEstantes(altura, anchura);

}

void Estante::espaciosEstantes(int filas, int columna) {
    espacios = new class Espacio [altura * anchura];

    //pones las cordinadas a cada una y por defecto estaran disponibles
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columna; j++) {
            espacios[columna * j + i].SetPosx(i);
            espacios[columna * j + i].SetPosy(j);
        }
    }
}

bool Estante::operator+=(class Libro &lib) {

    //primero se verifica que el al menos puede pude entarar al estante

    if (anchura >= lib.GetAncho() and altura >= lib.GetAlto()) { //si es compatible
        //ahora se verifica que hay un espacio disponible con las medidas para el libro
        int posxLibre = metodoEspacioLibreAncho();
        if (posxLibre != NO_ENCONTRADO and (anchura - posxLibre) >= lib.GetAncho()) {
            libros[cantidad_libros] = lib;
            modificarEspacios(posxLibre, lib.GetAncho(), lib.GetAlto());
            cantidad_libros++;
            return true;
        }
    }
    return false;
}

//int Estante::metodoEspacioAnchoDisponible(){
//    return anchura - espacios[cantidad_libros]->GetPosx();
//}

int Estante::metodoEspacioLibreAncho() {
    for (int i = 0; i < anchura; i++) {
        if (espacios[i].GetContenido() == 'D')return i;
    }
    return NO_ENCONTRADO;
}

void Estante::modificarEspacios(int posxLibre, int anchoLib, int altoLib) {

    for (int i = 0; i < anchoLib; i++) {
        for (int j = 0; j < altoLib; j++) {
            espacios[altura * j + (posxLibre + i)].SetContenido('O');
        }
    }
}

void operator<<(ofstream &arch, class Estante &estan) {
    char codigo[10];
    estan.GetCodigo(codigo);

    arch << left << "Codigo Estante:  " << setw(15) << codigo <<
            "Cantidad de Libros: " << estan.GetCantidad_libros() << endl;

    arch << "Anchura del Estante: " << setw(15) << estan.GetAnchura() <<
            "Altura del Estante: " << estan.GetAltura() << endl;

    int fila = estan.GetAltura();
    int columna = estan.GetAnchura();
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            estan.imprimeEstantes(arch, i, j);
        }
    }

}
void Estante::imprimeEstantes(ofstream &arch, int i, int j){
    
    
    
}

