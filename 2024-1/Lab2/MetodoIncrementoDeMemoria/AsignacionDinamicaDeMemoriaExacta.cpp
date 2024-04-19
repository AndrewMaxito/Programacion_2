#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#include "AsignacionDinamicaDeMemoriaExacta.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1

void lecturaDeLibros(const char *nomArch, char ***& libros, int **& stock) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    int cantLib = 0, cap = 0;
    int buffStock;
    char *codigo, *descrip, *autor, c;
    double buffPrecio;


    libros = nullptr;
    stock = nullptr;

    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    while (true) {
        codigo = leerCadenaExacta(arch, ',');
        if (codigo == nullptr) break;
        descrip = leerCadenaExacta(arch, ',');
        autor = leerCadenaExacta(arch, ',');
        arch >> buffStock >> c>>buffPrecio;
        arch.get();

        if (cantLib == cap)aumentarEspacios(libros, stock, cantLib, cap);
        libros[cantLib - 1] = new char *[3];
        stock[cantLib - 1] = new int [2];
        libros[cantLib - 1][0] = codigo;
        libros[cantLib - 1][1] = descrip;
        libros[cantLib - 1][2] = autor;
        stock[cantLib - 1][0] = buffStock;
        stock[cantLib - 1][1] = 0;
        cantLib++;
    }
}

char *leerCadenaExacta(ifstream &arch, char del) {
    char *ptr, buff[500];
    arch.getline(buff, 500, del);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void aumentarEspacios(char ***& libros, int **& stock, int &cantLib, int &cap) {
    int **auxInt;
    char ***auxChar;
    cap += INCREMENTO;
    if (libros == nullptr) {
        libros = new char **[cap] {
        };
        stock = new int *[cap] {
        };
        cantLib = 1;
    } else {
        auxChar = new char **[cap] {
        };
        auxInt = new int *[cap] {
        };
        for (int i = 0; libros[i]; i++) {
            auxChar[i] = libros[i];
            auxInt[i] = stock[i];
        }
        delete[] libros;
        delete[] stock;
        libros = auxChar;
        stock = auxInt;
    }
}

void pruebaDeLecturaDeLibros(const char *nomArch, char ***libros, int ** stock) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << setw(60) << "Reporte Libros" << endl;
    for (int i = 0; libros[i]; i++) {
        arch << left << setw(10) << libros[i][0] << setw(50) << libros[i][1] << setw(30) <<
                libros[i][2] << setw(10) << stock[i][0] << setw(10) << stock[i][1] << endl;
    }

}

void atencionDePedidos(const char *nomArch, char ***libros, int ** stock, int **& pedidosClientes,
        char ***&pedidosLibros, bool **&pedidosAtendidos) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    int numPedido, numDni;
    int cap = 0, cantPedidos = 0, capClientes = 0, cantClientes = 0;
    int arrCantLibros[500]{}, arrCapLibros[600]{};
    char c, codigoPed[8], *buffCodigos[10];
    bool buffPedAten[10];
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    pedidosAtendidos = nullptr;

    // 000132,69200503   CPE5718     KGO1734     IUG2294      ILG7766

    while (true) {
        int cantLibros = 0;
        arch>>numPedido;
        if (arch.eof()) break;
        arch >> c>>numDni;
        if (cantPedidos == cap)aumentarEspacios(pedidosLibros, pedidosAtendidos, cantPedidos, cap);



        while (arch.get() != '\n') {
            arch>>codigoPed;
            codigoPed[7] = 0; //creo ;v
            buffCodigos[cantLibros] = new char[strlen(codigoPed) + 1]; //si falla ver aqui
            strcpy(buffCodigos[cantLibros], codigoPed);
            int posLibro = buscarPosLibro(libros, codigoPed);
            if (posLibro == NO_ENCONTRADO)cout << codigoPed << endl;
            if (stock[posLibro][0] > 0) {
                buffPedAten[cantLibros] = true;
                stock[posLibro][0]--;
            } else {
                buffPedAten[cantLibros] = false;
                stock[posLibro][0]++;
            }
            cantLibros++;
        }

        pedidosLibros[cantPedidos - 1] = new char*[cantLibros + 1];
        pedidosAtendidos[cantPedidos - 1] = new bool[cantLibros + 1];

        for (int i = 0; i < cantLibros; i++) {
            pedidosLibros[cantPedidos - 1][i] = buffCodigos[i];
            pedidosAtendidos[cantPedidos - 1][i] = buffPedAten[i];
        }
        pedidosLibros[cantPedidos - 1][cantLibros] = 0;
        pedidosAtendidos[cantPedidos - 1][cantLibros] = 0;
        cantPedidos++;
    }
}

void aumentarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, int &cantPedidos,
        int &cap) {
    char ***auxChar;
    bool **auxBool;
    cap += INCREMENTO;

    if (pedidosLibros == nullptr) {
        pedidosLibros = new char **[cap] {
        };
        pedidosAtendidos = new bool *[cap] {
        };
        cantPedidos = 1;
    } else {
        auxChar = new char **[cap] {
        };
        auxBool = new bool *[cap] {
        };
        for (int i = 0; pedidosLibros[i]; i++) {
            auxChar[i] = pedidosLibros[i];
            auxBool[i] = pedidosAtendidos[i];
        }
        delete[] pedidosLibros;
        delete[] pedidosAtendidos;
        pedidosLibros = auxChar;
        pedidosAtendidos = auxBool;
    }
}

int buscarPosLibro(char ***libros, char *codigoPed) {
    for (int i = 0; libros[i]; i++)
        if (strcmp(libros[i][0], codigoPed) == 0)return i;
    cout << "no se encontro " << endl;
    return NO_ENCONTRADO;
}

void aumentarEspacios(int **&pedidosClientes, int &cantClientes, int &capClientes) {
    int **aux;
    capClientes += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int *[capClientes] {
        };
        cantClientes = 1;
    } else {
        aux = new int *[cantClientes] {
        };
        for (int i = 0; pedidosClientes[i]; i++) pedidosClientes[i] = aux[i];
        delete[] pedidosClientes;
        pedidosClientes = aux;
    }
}

int buscarCliente(int **pedidosClientes, int numDni) {
    for (int i = 0; pedidosClientes != nullptr and pedidosClientes[i]; i++)
        if (pedidosClientes[i][0] == numDni)return i;
    return NO_ENCONTRADO;
}

void aumentarEspacio(int *pedidosClientes, int &arrCantLibros, int &arrCapLibros) {
    int *aux;
    arrCapLibros += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int[arrCapLibros] {
        };
        arrCantLibros = 1;
    } else {
        aux = new int[arrCapLibros] {
        };
        for (int i = 0; pedidosClientes[i]; i++)aux[i] = pedidosClientes[i];
        delete[] pedidosClientes;
        pedidosClientes = aux;
    }
}
