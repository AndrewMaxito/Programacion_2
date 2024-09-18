
/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: andre
 * 
 * Created on 18 de septiembre de 2024, 11:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1

void lecturaDeLibros(const char *nomArch, char ***&libros, int **&stock) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);
    //primer paso inicializar los punteros en 0
    libros = nullptr;
    stock = nullptr;
    //cantidad y capacidad actual (al inicio empiezan en 0)
    int cantLibros = 0, capacidad = 0;
    //creamos los punteros DINAMICOS donde se guardaran los datos (cuando es de ms de una dimension)
    char *codigo, *descrip, *autor, c;
    int bffStock;
    double basuPrecio;

    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    //YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
    //ZOY6470,El viejo y el mar,Hernest Hemingway,25,68.01
    while (true) {
        //lectura de los datos
        codigo = leerCadenaExacta(arch, ',');
        if (codigo == nullptr) break;
        descrip = leerCadenaExacta(arch, ',');
        autor = leerCadenaExacta(arch, ',');
        arch >> bffStock >> c >> basuPrecio;
        arch.get(); // salto de linea

        //incremento de memoria (si lo necesitara)
        if (cantLibros == capacidad) aumentarEspacioLib(libros, stock, cantLibros, capacidad);
        libros[cantLibros - 1] = new char *[3];
        stock[cantLibros - 1] = new int [2];
        almacenarDatosLibros(libros[cantLibros - 1], codigo, descrip, autor);
        almacenarDatosStock(stock[cantLibros - 1], bffStock);
        //acá se podria poner que libros[cantLibros] = nullptr pero el registro creado todo se inicializo ya en 0
        cantLibros++;
    }
}

char *leerCadenaExacta(ifstream &arch, char del) {
    char buff[100], *ptr;
    arch.getline(buff, 100, del);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void aumentarEspacioLib(char ***&libros, int **&stock, int &cantLibros, int &capacidad) {


    capacidad += INCREMENTO;

    if (libros == nullptr) { //si entra por primera vez a libros
        libros = new char **[capacidad] {
        }; //se inicializa en 0 para tener un marcador siempre
        stock = new int *[capacidad] {
        };
        cantLibros = 1; // importante ya que se necesita un marcador despues de la ultima posicion llena
    } else {
        //Creacion del aux
        char ***auxChar;
        int **auxInt;
        auxChar = new char **[capacidad] {
        };
        auxInt = new int*[capacidad] {
        };
        for (int i = 0; libros[i]; i++) {
            auxChar[i] = libros[i];
            auxInt[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = auxChar;
        stock = auxInt;
    }
}

void almacenarDatosLibros(char **reglibro, char *codigo, char *descrip, char *autor) {
    reglibro[0] = codigo;
    reglibro[1] = descrip;
    reglibro[2] = autor;
}

void almacenarDatosStock(int *regStock, int bffStock) {
    regStock[0] = bffStock;
    regStock[1] = 0; //inicializado en 0 la cantidad no atebdida   
}

void pruebaDeLecturaDeLibros(const char *nomArch, char ***libros, int **stock) {
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep, nomArch);
    for (int i = 0; libros[i]; i++) {
        char **auxLib = libros[i];
        int *auxStock = stock[i];
        archRep << left << setw(10) << auxLib[0] << setw(60) << auxLib[1] <<
                setw(50) << auxLib[2] << right << setw(10) << auxStock[0] <<
                setw(10) << auxStock[1] << endl;

    }
}

//Pregunta 2

void atencionDePedidos(const char *nomArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    pedidosAtendidos = nullptr;
    //Para clientes
    int cantClien = 0, capClien = 0;
    int arrCantCli[400]{}, arrCapCli[400]{};

    //para libros Ped
    int capPedidos = 0;
    int arrCantPedLib[400]{}, arrCapPedLib[400]{};

    int dni, codigoPedido;
    char c;
    //000059,34460612   CRY6839    VYG3594
    //000140,42302422   WPU8819    
    //000167,34460612   PQZ1316    XCC4070
    while (true) {
        arch >> codigoPedido;
        if (arch.eof()) break;
        arch >> c >> dni;
        //Para Cliente
        int posCliente = buscarCliente(pedidosClientes, dni);

        if (posCliente == NO_ENCONTRADO) {
            if (cantClien == capClien) aumentarEspaciosCli(pedidosClientes, cantClien, capClien);
            posCliente = cantClien - 1;
            pedidosClientes[posCliente] = nullptr;
            cantClien++;
        }
        if (arrCantCli[posCliente] == arrCapCli[posCliente])
            aumentarEspacioRegCli(pedidosClientes[posCliente], arrCantCli[posCliente], arrCapCli[posCliente], dni);
        pedidosClientes[posCliente][arrCantCli[posCliente]] = codigoPedido;
        pedidosClientes[posCliente][1]++;
        arrCantCli[posCliente]++;

        //Para Libros
        if (capPedidos <= codigoPedido + 1)
            aumentarEspaciosPedidos(pedidosAtendidos, pedidosLibros, codigoPedido, capPedidos);
        int posPedi = codigoPedido + 1;
        while (arch.get() != '\n') {
            if (arrCantPedLib[posPedi] == arrCapPedLib[posPedi])
                aumentarEspacioRegLib(pedidosLibros[posPedi], pedidosAtendidos[posPedi], arrCantPedLib[posPedi], arrCapPedLib[posPedi]);
            int posRegLib = arrCantPedLib[posPedi] - 1;
            char codigoLib[8];
            arch >> codigoLib;
            pedidosLibros[posPedi][posRegLib] = new char [strlen(codigoLib) + 1];
            strcpy(pedidosLibros[posPedi][posRegLib], codigoLib);
            int posLib = buscaLibro(libros, codigoLib);
            if (stock[posLib][0] > 0) {
                stock[posLib][0]--;
                pedidosAtendidos[posPedi][posRegLib] = true;
            } else {
                stock[posLib][1]++;
                pedidosAtendidos[posPedi][posRegLib] = false;
            }
            arrCantPedLib[posPedi]++;
        }
    }
}

int buscaLibro(char ***libros, char *codigoLib) {
    for (int i = 0; libros[i]; i++) {
        if (strcmp(libros[i][0], codigoLib) == 0)return i;
    }
    cout << "No encontre el libro" << endl; //solo por si acaso
    return NO_ENCONTRADO;
}

int buscarCliente(int **pedidosClientes, int dni) {
    if (pedidosClientes == nullptr) return NO_ENCONTRADO;
    for (int i = 0; pedidosClientes[i]; i++) {
        int *auxPedCli = pedidosClientes[i];
        if (auxPedCli[0] == dni) return i;
    }
    return NO_ENCONTRADO;
}

void aumentarEspaciosCli(int **&pedidosClientes, int &cantClien, int &capClien) {
    capClien += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int *[capClien] {
        };
        cantClien = 1;
    } else {
        int **auxPedCli = new int *[capClien] {
        };
        for (int i = 0; pedidosClientes[i]; i++) {
            auxPedCli[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxPedCli;
    }
}

void aumentarEspacioRegCli(int *&regCliente, int &cant, int &cap, int dni) {
    cap += INCREMENTO;
    if (regCliente == nullptr) {
        regCliente = new int [cap] {
        };
        regCliente[0] = dni;
        regCliente[1] = 0;
        cant = regCliente[1] + 2;
    } else {
        int *auxRegCli = new int [cap] {
        };
        for (int i = 0; regCliente[i]; i++) {
            auxRegCli[i] = regCliente[i];
        }
        delete regCliente;
        regCliente = auxRegCli;
    }
}

void aumentarEspaciosPedidos(bool **&pedidosAtendidos, char ***&pedidosLibros, int codigoPedido, int capPedidos) {
    capPedidos = (codigoPedido + 1) + INCREMENTO;
    if (pedidosLibros == nullptr) {
        pedidosLibros = new char **[capPedidos] {
        };
        pedidosAtendidos = new bool *[capPedidos] {
        };
    } else {
        char ***auxPedLib = new char **[capPedidos] {
        };
        bool **auxPedAte = new bool *[capPedidos] {
        };
        for (int i = 1; pedidosLibros[i]; i++) {
            auxPedLib[i] = pedidosLibros[i];
            auxPedAte[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxPedLib;
        pedidosAtendidos = auxPedAte;
    }
}

void aumentarEspacioRegLib(char **&regPedLib, bool *&regPedAten, int &cant, int &cap) {
    cap += INCREMENTO;
    if (regPedLib == nullptr) {
        regPedLib = new char *[cap] {
        };
        regPedAten = new bool [cap] {
        };
        cant = 1;
    } else {
        char **auxPedLib = new char *[cap] {
        };
        bool *auxPedAten = new bool [cap] {
        };
        for (int i = 0; regPedLib[i]; i++) {
            auxPedLib[i] = regPedLib[i];
            auxPedAten[i] = regPedAten[i];
        }
        delete regPedLib;
        delete regPedAten;
        regPedLib = auxPedLib;
        regPedAten = auxPedAten;
    }
}



