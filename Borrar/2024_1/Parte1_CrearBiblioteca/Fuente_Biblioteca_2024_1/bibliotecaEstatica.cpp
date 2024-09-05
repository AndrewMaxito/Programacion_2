
/* 
 * File:   bibliotecaEstatica.cpp
 * Author: andre
 * 
 * Created on 5 de septiembre de 2024, 01:05 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "bibliotecaEstatica.h"
#include "Estructuras.h"

bool operator>>(ifstream &arch, struct Libro &lib) {
    //    IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    //YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
    //ZOY6470,El viejo y el mar,Hernest Hemingway,25,68.01
    char codigo[8], c;
    arch.getline(codigo, 8, ',');
    if (arch.eof()) return false;
    strcpy(lib.codigo, codigo);
    arch.getline(lib.tiltulo, 80, ',');
    arch.getline(lib.autor, 60, ',');
    arch >> lib.stock >> c >> lib.precio;
    arch.get(); //salto de linea
    return true;
}

bool operator>>(ifstream &arch, struct Cliente &cli) {
    //    54393647,Reyes Tang Edward 
    //67066631,Arca Amezquita Edric Ronald
    //32231860,Cerna Hijar Jose Rolando
    int codigo;
    char c;
    arch >> codigo;
    if (arch.eof()) return false;
    cli.dni = codigo;
    arch.get();
    arch.getline(cli.nombre, 60, '\n');
    cli.cantDeLibros = 0;
    cli.pagoTotal = 0;
    return true;
}

bool operator>>(struct LibroSolicitado &lib, struct Libro *arrLibros) {
    int posLibro = -1;
    for (int i = 0; strcmp(arrLibros[i].codigo, "FIN") != 0 and arrLibros[i].codigo[0] != '\0'; i++) {
        if (strcmp(arrLibros[i].codigo, lib.codigoDelLibro) == 0) {
            posLibro = i;
            break;
        }
    }
    if (posLibro != -1) {
        if (arrLibros[posLibro].stock > 0) {
            arrLibros[posLibro].stock--;
            lib.precio = arrLibros[posLibro].precio;
            lib.atendido = true;
            return true;
        }
        lib.atendido = false;
        return false;
    }
    cout << "No se encontro el libro" << endl;
    return false;
}

bool operator>>(struct Cliente &cli, struct LibroSolicitado &libSol) {
    if (cli.cantDeLibros < 30) {
        cli.librosSolicitados[cli.cantDeLibros] = libSol;
        cli.cantDeLibros++;
        return true;
    }
    return false;
}

void operator++(struct Cliente &cli) {
    double precioTotal = 0;
    for (int i = 0; i < cli.cantDeLibros; i++) {
        cli.pagoTotal += cli.librosSolicitados[i].precio;
    }
}

void operator<<(ofstream &arch, struct Libro &lib) {
    arch << left << setw(10) << lib.codigo << setw(60) << lib.tiltulo << setw(50) << lib.autor << right <<
            setw(10) << lib.stock << setw(10) << lib.precio << endl;
}

void operator<<(ofstream &arch, struct Cliente &cli) {
    arch << left << setw(10) << cli.dni << cli.nombre << endl;
    arch << "Libros entregados: " << endl;
    arch << left << setw(10) << ' ' << setw(20) << "Pedido No." << setw(20) <<
            "Codigo" << "Precio" << endl;
    for (int i = 0; i < cli.cantDeLibros; i++) {
        arch << left << setw(10) << ' ' << setw(20) <<
                cli.librosSolicitados[i].numeroDePedido << setw(20) <<
                cli.librosSolicitados[i].codigoDelLibro << right << setw(4) << 
                cli.librosSolicitados[i].precio << endl;
    }
    arch << "Pago Total:   "<<right<<setw(10)<<cli.pagoTotal<<endl;
}