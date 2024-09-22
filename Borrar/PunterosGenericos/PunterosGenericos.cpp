

/* 
 * File:   PunterosGenericos.cpp
 * Author: andre
 * 
 * Created on 21 de setiembre de 2024, 23:29
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "PunterosGenericos.h"
#define INCREMENTAR 5
#define NO_ENCONTRADO -1

void cargarProductos(void *&productos) {
    ifstream arch("Productos2.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo Productos2.csv " << endl;
        exit(1);
    }

    //    BIT-434,Campana Extractora modelo Glass,375.09,S
    //SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,S
    void **buffProductos[300], *ptrProducto, **regProductos;
    int cant = 0;

    while (true) {
        ptrProducto = procesarDatosProductos(arch);
        if (ptrProducto == nullptr) break;
        buffProductos[cant] = (void **) (ptrProducto);
        cant++;
    }
    buffProductos[cant] = nullptr;
    cant++;
    regProductos = new void *[cant];
    for (int i = 0; buffProductos[i]; i++) {
        regProductos[i] = buffProductos[i];
    }
    regProductos[cant - 1] = nullptr;
    productos = regProductos;
}

void *procesarDatosProductos(ifstream &arch) {
    char *codigoPro, *nombrePro, buffTipoLinea;
    double buffPrecio;
    codigoPro = leerCadenaExacta(arch, ',');
    if (codigoPro == nullptr)return nullptr;
    nombrePro = leerCadenaExacta(arch, ',');
    arch >> buffPrecio;
    arch.get();
    arch >> buffTipoLinea;
    arch.get();
    double *precio = new double (buffPrecio);
    char *tipo = new char (buffTipoLinea);
    void *datosProducto = new void *[4] {
        codigoPro, nombrePro, precio, tipo
    };
    return datosProducto;
}

char *leerCadenaExacta(ifstream &arch, char del) {
    char buff[100], *ptr;
    arch.getline(buff, 100, del);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void cargarClientes(void *&clientes) {
    ifstream arch("Clientes2.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo Clientes2.csv " << endl;
        exit(1);
    }
    void **regClientes = nullptr;
    void *ptrCliente;
    int cant = 0, cap = 0;
    //79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
    //16552775,YALLICO PAREDES LOURDES CARMELA,960176666,20000
    while (true) {
        ptrCliente = procesarDatosClientes(arch);
        if (ptrCliente == nullptr) break;

        if (cant == cap)
            aumentarEspacios(regClientes, cant, cap);
        regClientes[cant - 1] = ptrCliente;
        cant++;
    }
    clientes = regClientes;
}

void *procesarDatosClientes(ifstream &arch) {
    int buDni, buTele;
    char *nombre, c;
    double buLine;

    arch >> buDni;
    if (arch.eof())return nullptr;
    int *dni = new int (buDni);
    arch.get();
    nombre = leerCadenaExacta(arch, ',');
    arch >> buTele >> c >> buLine;
    int *telefono = new int (buTele);
    double *linea = new double (buLine);
    void **regCliente = new void *[4] {
    };
    regCliente[0] = dni;
    regCliente[1] = nombre;
    regCliente[3] = linea;
    return regCliente;
}

void aumentarEspacios(void **&regClientes, int &cant, int &cap) {
    cap += INCREMENTAR;
    if (regClientes == nullptr) {
        regClientes = new void*[cap] {
        };
        cant = 1;
    } else {
        void **auxRegCli = new void*[cap] {
        };
        for (int i = 0; regClientes[i]; i++) {
            auxRegCli[i] = regClientes[i];
        }
        delete regClientes;
        regClientes = auxRegCli;
    }
}


//Pregunta 2 

void cargaPedidos(const void *productos, void *clientes) {
    ifstream arch("Pedidos2.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo Pedidos2.csv " << endl;
        exit(1);
    }

    //JXD-139,50375303,6
    //CRU-009,50375303,5
    //YYK-309,22777006,3
    char bufCodigo[8], c;
    int cantProPed, dniCliPed;
    while (true) {
        arch.getline(bufCodigo, 8, ',');
        if (arch.eof())break;
        arch >> dniCliPed >> c >> cantProPed;
        arch.get(); //salto de linea
        int posProd = buscarProducto(productos, bufCodigo);
        void **regProd = (void **) productos;
        void **datosProd = (void **) (regProd[posProd]);
        char *tipo = (char *) (datosProd[3]);
        double *precioPro = (double *) (datosProd[2]);
        double total_Pagar = *precioPro * (cantProPed);
        if (*tipo == 'S') {
            int posCliente = buscarCliente(clientes, dniCliPed);
            void **regClie = (void **) clientes;
            void **datosClie = (void **) (regClie[posCliente]);
            //Aqui me quede





        }




    }



}

int buscarProducto(const void *productos, const char *bufCodigo) {
    void **regProd = (void **) productos;


    for (int i = 0; regProd[i]; i++) {
        void **datosProd = (void **) (regProd[i]);
        char *codigoPro = (char *) (datosProd[0]);
        if (strcmp(codigoPro, bufCodigo) == 0)return i;
    }
    cout << "No se encontro el producto " << endl;
    exit(1);
    return NO_ENCONTRADO;
}

int buscarCliente(const void *clientes, const int dniCliPed) {
    void **regClie = (void **) clientes;
    for (int i = 0; regClie[i]; i++) {
        void **datosClie = (void **) (regClie[i]);
        int *dni = (int *) (datosClie[0]);
        if (*dni == dniCliPed)return i;
    }
    cout << "No se encontro el cliente " << endl;
    exit(1);
    return NO_ENCONTRADO;
}