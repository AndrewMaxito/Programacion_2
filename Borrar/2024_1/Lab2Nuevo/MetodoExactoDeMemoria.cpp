

/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: andre
 * 
 * Created on 8 de septiembre de 2024, 11:04 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "MetodoExactoDeMemoria.h"
#define NO_ENCONTRADO -1
#define LINEAS 69

void lecturaDeLibros(const char *nomArch, char ***&libros, int **&stock) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    char **buffLibros[300], **datosLibros;
    int *buffStock[300], *datosStock, cantLibros = 0;
    while (true) {
        datosLibros = leerDatosLibros(arch);
        if (datosLibros == nullptr) break;
        buffLibros[cantLibros] = datosLibros;
        buffStock[cantLibros] = leerDatosStock(arch);
        cantLibros++;
    }
    buffLibros[cantLibros] = nullptr;
    buffStock[cantLibros] = nullptr;
    cantLibros++;

    libros = new char **[cantLibros];
    stock = new int * [cantLibros];

    for (int i = 0; i < cantLibros; i++) {
        libros[i] = buffLibros[i];
        stock[i] = buffStock[i];
    }
}

int *leerDatosStock(ifstream &arch) {
    int *ptr;
    char c;
    double basura;
    ptr = new int [2] {
    }; //Ambos campos en 0 para empezar
    arch >> ptr[0] >> c >> basura;
    arch.get(); //salto de linea
    return ptr;
}

char **leerDatosLibros(ifstream &arch) {
    char **regLibro, *codigo;
    codigo = leerCadenaExacta(arch, ',');
    if (codigo == nullptr) return nullptr;
    regLibro = new char*[3];
    regLibro[0] = codigo;
    regLibro[1] = leerCadenaExacta(arch, ',');
    regLibro[2] = leerCadenaExacta(arch, ',');
    return regLibro;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof())return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void pruebaDePedidos(const char *nomArch, char ***libros, int **stock) {
    ofstream archRep(nomArch, ios::out);
    if (!archRep.is_open()) {
        cout << "No se pudo abrrir el archivo " << nomArch << endl;
        exit(1);
    }
    for (int i = 0; libros[i] != nullptr; i++) {
        char **auxLib = libros[i];
        int *auxStock = stock[i];
        archRep << left << setw(10) << auxLib[0] << setw(60) << auxLib[1] << setw(40) << auxLib[2] << right << setw(10) << auxStock[0] << setw(10) << auxStock[1];
        archRep << endl;
    }
}

//Pregunta 2

void atencionDepedidos(const char *nomArch, char ***libros, int **&stock,
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos) {
    //000059,34460612   CRY6839    VYG3594
    //000140,42302422   WPU8819    CTW5846

    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrrir el archivo " << nomArch << endl;
        exit(1);
    }

    int *buffPedidosClien[400]{}, *ptrPedidosClientes; //suponiendo que la cantidad de clientes no excede los 300
    char **buffPedidiosLib[400]; //suponiendo que no hay mas de 300 pedidos
    bool *buffPedidosAtend[400];
    //000059,34460612   CRY6839    VYG3594
    //000140,42302422   WPU8819    CTW5846
    int cantClientes = 0, numeroPedido, cantPedidos = 0, arrCantLib[300]{};
    while (true) {
        ingresarDatosArrPedidosCliente(arch, buffPedidosClien,
                numeroPedido, cantClientes);
        if (arch.eof())break;
        buffPedidiosLib[numeroPedido] = new char *[300] {
        };
        buffPedidosAtend[numeroPedido] = new bool [300] {
        };
        ingresarDatosLibros(arch, libros, stock, buffPedidosAtend[numeroPedido],
                buffPedidiosLib[numeroPedido], numeroPedido, arrCantLib[numeroPedido]);
        cantPedidos++;
    }

    cantPedidos++; //ya que el pedido 0000 no existe 
    buffPedidosClien[cantClientes] = nullptr; //no se si va 0
    cantClientes++;
    buffPedidiosLib[cantPedidos] = nullptr;
    buffPedidosAtend[cantPedidos] = nullptr;
    cantPedidos++; //se le agrego uno mas 
    pedidosClientes = new int *[cantClientes];
    pedidosLibros = new char **[cantPedidos];
    pedidosAtendidos = new bool *[cantPedidos];

    for (int i = 0; buffPedidosClien[i]; i++) {
        int cantPedidosCliente = buffPedidosClien[i][1];
        pedidosClientes[i] = new int[cantPedidosCliente + 2];
        for (int j = 0; j < cantPedidosCliente + 2; j++) {
            pedidosClientes[i][j] = buffPedidosClien[i][j];
        }
    }
    pedidosClientes[cantClientes - 1] = nullptr;

    for (int i = 0; buffPedidiosLib[i]; i++) {
        pedidosLibros[i] = new char *[arrCantLib[i] + 1] {
        };
        pedidosAtendidos[i] = new bool [arrCantLib[i] + 1] {
        };
        char **auxpedidosLibros= pedidosLibros[i];
        bool *auxpedidosAtendidos = pedidosAtendidos[i];
        
        
        for (int j = 0; j < arrCantLib[i]; j++) {
            auxpedidosLibros[j] = buffPedidiosLib[i][j];
            auxpedidosAtendidos[j] = buffPedidosAtend[i][j];
        }
    }
    pedidosLibros[cantPedidos - 1] = nullptr;
    pedidosAtendidos[cantPedidos - 1] = nullptr;
}

void ingresarDatosArrPedidosCliente(ifstream &arch, int **buffPedidosClien,
        int &numeroPedido, int &cantClientes) {
    int dniCliente;
    arch >> numeroPedido;
    if (arch.eof())return;
    arch.get();
    arch >> dniCliente;
    int posCliente = buscarPosCliente(dniCliente, buffPedidosClien);
    if (posCliente != NO_ENCONTRADO) {
        //ya existe
        cargarDatos(buffPedidosClien[posCliente], dniCliente, numeroPedido);
    } else {
        //crea los nuevos espacios
        posCliente = cantClientes;
        buffPedidosClien[posCliente] = new int [300] {
        }; //suponiendo que no habran mas de 300 datos
        cargarDatos(buffPedidosClien[posCliente], dniCliente, numeroPedido);
        cantClientes++;
    }
}

int buscarPosCliente(int dniCliente, int **buffPedidosClien) {
    for (int i = 0; buffPedidosClien[i]; i++) {
        int *aux = buffPedidosClien[i];
        if (aux[0] == dniCliente)return i;
    }
    return NO_ENCONTRADO;
}

void cargarDatos(int *datosCliente, int dniCliente, int numeroPedido) {
    if (datosCliente[0] == 0)datosCliente[0] = dniCliente;
    int posVacio = datosCliente[1] + 2;
    datosCliente[posVacio] = numeroPedido;
    datosCliente[1]++;
}

void ingresarDatosLibros(ifstream &arch, char ***libros, int **&stock, bool *registroPedAten,
        char **registroPedLib, int numPedido, int &cantLibros) {
    char codigo[8];
    while (arch.get() != '\n') {
        arch >> codigo;
        int posLibro = buscarPosLibro(codigo, libros);
        //Supuestamnete siempre existe el libro ;V
        int posVacio = 0;
        for (posVacio = 0; registroPedLib[posVacio]; posVacio++);

        registroPedLib[posVacio] = new char [strlen(codigo) + 1];
        strcpy(registroPedLib[posVacio], codigo);
        int *auxStock = stock[posLibro];
        if (auxStock[0] > 0) {
            auxStock[0]--;
            registroPedAten[posVacio] = true;
        } else {
            auxStock[1]++;
            registroPedAten[posVacio] = false;
        }
        cantLibros++;
    }
}

int buscarPosLibro(char *codigo, char ***libros) {
    for (int i = 0; libros[i]; i++) {
        char **auxCodiLib = libros[i];
        if (strcmp(codigo, auxCodiLib[0]) == 0) return i;
    }
    cout << "No se encontro el libro" << endl; //solo por si acaso
    return NO_ENCONTRADO;
}

void reporteDeEntrega(const char *nomArch, int **pedidosClientes, char ***pedidosLibros,
        bool **&pedidosAtendidos) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << right << setw(60) << "Reoirte de atencion de pedidos" << endl;
    imprimirLineas(arch, LINEAS, '=');

    for (int i = 0; pedidosClientes[i]; i++) {
        arch << left << setw(15) << "CLIENTE: " << pedidosClientes[i][0] << endl;
        imprimirLineas(arch, LINEAS, '=');
        for (int j = 2; j < (pedidosClientes[i][1] + 2); j++) {
            arch << left << setw(12) << ' ' << setw(20) << "Pedido No." << setw(20) <<
                    "Codigo del libro" << "Observaciones" << endl;
            imprimirLineas(arch, LINEAS, '-');
            arch << left << setw(14) << ' ' << right << setfill('0') << setw(6) << pedidosClientes[i][j] <<
                    setfill(' ') << left << setw(20) << ' ' << endl;
            int numPedi = pedidosClientes[i][j];


            for (int k = 0; pedidosLibros[numPedi][k]; k++) {
                arch << left << setw(35) << ' ' << setw(23) << pedidosLibros[numPedi][k];
                if (pedidosAtendidos[numPedi][k] == true) {
                    arch << "ATENDIDO" << endl;
                } else arch << "NO ATENDIDO" << endl;

            }
            imprimirLineas(arch, LINEAS, '-');
        }
        imprimirLineas(arch, LINEAS, '=');
    }
}

void imprimirLineas(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++)arch << car;
    arch << endl;
}