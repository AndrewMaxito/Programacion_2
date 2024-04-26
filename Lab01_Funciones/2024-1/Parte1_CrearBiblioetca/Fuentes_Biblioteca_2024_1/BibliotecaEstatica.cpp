#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "Estructuras.h"
using namespace std;

bool operator>>(ifstream &arch, struct Libro &libro) {
    // IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    char codLibro[8], c;

    arch.getline(codLibro, 8, ',');
    if (arch.eof()) return false;
    arch.getline(libro.tiltulo, 80, ',');
    arch.getline(libro.autor, 80, ',');
    arch >> libro.stock >> c >> libro.precio;
    arch.get(); //descarto salto de linea
    strcpy(libro.codigo, codLibro);
    return true;
}

bool operator>>(ifstream &arch, struct Cliente &cliente) {
    int dni;
    arch >> dni;
    if (arch.eof()) return false;
    arch.get();
    arch.getline(cliente.nombre, 60);
    cliente.dni = dni;
    cliente.cantDeLibros = 0;
    cliente.pagoTotal = 0;
    return true;
}

bool operator>>(struct LibroSolicitado &libroPedido, struct Libro *arrLibro) {
    int i = 0, flag = 0;


    for (i; strcmp(arrLibro[i].codigo, "FIN") != 0 and arrLibro[i].codigo[0] != '\0'; i++)
        if (strcmp(arrLibro[i].codigo, libroPedido.codigoDelLibro) == 0) {
            flag = 1;
            break;
        }

    if (flag == 1) {
        if (arrLibro[i].stock > 0) {
            arrLibro[i].stock--;
            libroPedido.precio = arrLibro[i].precio;
            libroPedido.atendido = true;
            return true;
        } else {
            libroPedido.atendido = false;
            return false;
        }
    } else {
        cout << "No se encontro el libro" << endl;
        libroPedido.atendido = false;
        return false;
    }
}

bool operator<<(struct Cliente &cliente, struct LibroSolicitado &libroPedido) {
    if (cliente.cantDeLibros < 30) {
        cliente.librosSolicitados[cliente.cantDeLibros] = libroPedido;
        cliente.cantDeLibros++;
        return true;
    } else return false;
}

void operator++(struct Cliente &cliente) {
    for (int i = 0; i < cliente.cantDeLibros; i++) {
        cliente.pagoTotal += cliente.librosSolicitados[i].precio;
    }
}

void operator<<(ofstream &archRepLib, struct Libro &libro) {

    archRepLib << left << setw(10) << libro.codigo << setw(60) << libro.tiltulo << setw(30) <<
            libro.autor << setw(15) << right << setw(10) << libro.stock << setw(10) << libro.precio << endl;
}

void operator<<(ofstream &archRepCli, struct Cliente &cliente) {
    archRepCli << left << setw(15) << cliente.dni << cliente.nombre << endl;
    archRepCli << "Libros Entregados: " << endl;
    archRepCli << left << setw(10) << ' ' << setw(15) << "Pedido No." << setw(15) << "codigo" <<
            "Precio" << endl;
    for (int i = 0; i < cliente.cantDeLibros; i++) {
        if (cliente.librosSolicitados[i].atendido) {
            archRepCli << left << setw(10) << ' ' << right << setfill('0') << setw(4) <<
                    cliente.librosSolicitados[i].numeroDePedido << setfill(' ') << left << setw(10) <<
                    ' ' << setw(15) << cliente.librosSolicitados[i].codigoDelLibro << right << setw(7) <<
                    cliente.librosSolicitados[i].precio << endl;
        }
    }
    archRepCli << right << "TOTAL A PAGAR:   " << cliente.pagoTotal << endl;

    archRepCli << "Libros No Entregados: " << endl;
    archRepCli << left << setw(10) << ' ' << setw(15) << "Pedido No." << setw(15) << "codigo" <<
            "Precio" << endl;
    for (int i = 0; i < cliente.cantDeLibros; i++) {
        if (cliente.librosSolicitados[i].atendido == false) {
            archRepCli << left << setw(10) << ' ' << right << setfill('0') << setw(4) <<
                    cliente.librosSolicitados[i].numeroDePedido << setfill(' ') << left << setw(10) <<
                    ' ' << setw(15) << cliente.librosSolicitados[i].codigoDelLibro << right << setw(7) <<
                    cliente.librosSolicitados[i].precio << endl;
        }
    }


}
