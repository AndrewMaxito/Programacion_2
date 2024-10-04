
/* 
 * File:   PunterosGenericos.cpp
 * Author: andre
 * 
 * Created on 21 de setiembre de 2024, 19:55
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1


//Pregunta 1
void cargaClientes(void *&clientes) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Clientes.csv");

    void **regClientes, *ptrRegClientes;
    clientes = nullptr;
    //54393647,Reyes Tang Edward 
    //67066631,Arca Amezquita Edric Ronald
    int cantCli = 0, capCli = 0;
    while (true) {
        ptrRegClientes = leerRegistroClientes(arch);
        if (ptrRegClientes == nullptr) break; //esta vacio
        //verificar si hay espacios sufientes
        if (capCli == cantCli)
            incrementarEspaciosParaCliente(clientes, cantCli, capCli);
        regClientes=(void **)clientes;
        regClientes[cantCli - 1] = ptrRegClientes;
        cantCli++;
    }
    muestraclientes(clientes); //prueba
}

void *leerRegistroClientes(ifstream &arch) {
    void **datos;
    int numDni, *dni;
    char *nomCli, buff[100];
    arch >> numDni;
    if (arch.eof()) return nullptr;
    arch.get();
    arch.getline(buff, 100); //ya lee el salto de linea

    nomCli = new char [strlen(buff) + 1];
    strcpy(nomCli, buff);
    dni = new int (numDni);
    datos = new void* [2];
    datos[0]=dni;
    datos[1]=nomCli;
    return datos;
}

void incrementarEspaciosParaCliente(void *&clientes, int &cantCli, int &capCli) {
    capCli += 5;
    void **regClientesCas;
    if (clientes == nullptr) {
        void **regClientesCas = new void *[capCli] {
        }; // inicializados en nullptr
        cantCli = 1;
        clientes = regClientesCas;
    } else {
        void **auxRegCli = new void *[capCli] {
        };
        regClientesCas=(void **)clientes;
        for (int i = 0; regClientesCas[i]; i++) {
            auxRegCli[i] = regClientesCas[i];
        }
        delete regClientesCas;
        clientes = auxRegCli;
    }
}


//Pregunta 2
void creaReserva(void *&reserva) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Libros.csv");
    //Esto lo hare por asignacion exacta
    void **buffRegReservas[300], *ptrReg, **registro;
    int cantReservas = 0;

    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    //YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
    while (true) {
        ptrReg = leerRegistroLibros(arch);
        if (ptrReg == nullptr) break;
        buffRegReservas[cantReservas] = (void **) ptrReg;
        cantReservas++;
    }
    buffRegReservas[cantReservas] = nullptr;
    cantReservas++;
    registro = new void *[cantReservas];
    for (int i = 0; buffRegReservas[i]; i++) {
        registro[i] = buffRegReservas[i];
    }
    registro[cantReservas - 1] = nullptr;
    reserva = registro;
    muestrareservas(reserva);
}

void *leerRegistroLibros(ifstream &arch) {
    void **regLibros;
    char *codigo, *nombre, *autor, c;
    int *stock;
    double basura;
    codigo = leerCadenaExacta(arch, ',');
    if (codigo == nullptr) return nullptr;
    nombre = leerCadenaExacta(arch, ',');
    autor = leerCadenaExacta(arch, ',');
    regLibros = new void *[5]; //todos inicializados en nullptr
    stock = new int;
    arch >> *stock >> c >> basura;
    arch.get(); //salto de linea
    regLibros[0] = codigo;
    regLibros[1] = nombre;
    regLibros[2] = autor;
    regLibros[3] = new void *[*stock] {
    };
    regLibros[4] = stock;
    return regLibros;
}

char *leerCadenaExacta(ifstream &arch, char del) {
    char buff[100], *ptr;
    arch.getline(buff, 100, del);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

//Pregunta 3 

void cargaRerserva(void *clientes, void *reserva) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos2.csv");

    //69200503,ZQY9966
    //14268463,BHD6079
    int dni,cantLibPed[400]{};
    char codigoLib[8], c;

    while (true) {
        arch >> dni;
        if (arch.eof()) break;
        arch.get();
        arch >> codigoLib;
        //se debe buscar el libro en el registro de libros y ver si hay stock suficiente
        int posLibro = buscarLibro(reserva, codigoLib);
        void **registroLibros = (void **) reserva;
        void **datosDelLibro = (void **) (registroLibros[posLibro]);
        int *stockReg = (int *) (datosDelLibro[4]);
        if (*stockReg > cantLibPed[posLibro]) {
            //buscar el espacio libre
            void **pedidosLib = (void **) (datosDelLibro[3]);
            int posVacia = 0;
            for (posVacia; pedidosLib[posVacia]; posVacia++);
            int *dniClienteReg = new int (dni);

            int posCliente = buscarCliente(clientes, dni);
            void **registroClientes = (void **) clientes;
            void **datosDelCliente = (void **) (registroClientes[posCliente]);
            char *nombreCliente = (char *) (datosDelCliente[1]);
            char *nombreClienteReg = new char [strlen(nombreCliente) + 1];
            strcpy(nombreClienteReg,nombreCliente);
            pedidosLib[posVacia] = new void *[2] {dniClienteReg,nombreClienteReg};
            cantLibPed[posLibro]++;
        }
    }
}

int buscarLibro(const void *reserva, const char *codigoLib) {
    void **registroLibros = (void **) reserva;


    for (int i = 0; registroLibros[i]; i++) {//asumiendo que el registro siempre esta lleno sino seria necesario la condicon de registroLibros != nullptr 
        void **datosDelLibro = (void **) (registroLibros[i]);
        char *codigoLibReg = (char *) (datosDelLibro[0]);
        if (strcmp(codigoLibReg, codigoLib) == 0)return i;
    }

    //En teoria nunca deberia entrar aqui pero es buena practica informar sobre el error
    cout << "NO se encontro el libro "<<codigoLib << endl;
    exit(1);
    return NO_ENCONTRADO - 1;
}

int buscarCliente(const void *clientes, const int dni) {

    void **registroClientes = (void **) clientes;


    for (int i = 0; registroClientes[i]; i++) {//asumiendo que el registro siempre esta lleno sino seria necesario la condicon de registroLibros != nullptr 
        void **datosDelCliente = (void **) (registroClientes[i]);
        int *dniCliente = (int *) (datosDelCliente[0]);
        if (*dniCliente == dni)return i;
    }
    //En teoria nunca deberia entrar aqui pero es buena practica informar sobre el error
    cout << "NO se encontro el Cliente" << endl;
    exit(1);
    return NO_ENCONTRADO - 1;
}