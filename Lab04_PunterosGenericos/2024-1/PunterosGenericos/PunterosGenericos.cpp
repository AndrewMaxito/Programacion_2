#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"
#define NO_ENCONTRADO -1


//Pregunta 1

void cargarclientes(void *&clientes) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Clientes.csv");

    void **registroClientes[150], *datosCliente, **registro;
    int cant = 0;
    while (true) {
        datosCliente = leerDatosCliente(arch);
        if (datosCliente == nullptr) break;
        registroClientes[cant] = (void **) datosCliente;
        cant++;
    }
    registroClientes[cant] = nullptr;
    cant++;
    registro = new void *[cant];
    for (int i = 0; i < cant; i++)registro[i] = registroClientes[i];
    clientes = registro;
    muestraclientes(clientes);
}

void *leerDatosCliente(ifstream &arch) {
    int *dni, numeroDni;
    char *nombreCliente;
    void **datosCliente;
    arch>>numeroDni;
    if (arch.eof()) return nullptr;
    arch.get(); //lee la coma
    nombreCliente = leerCadenaExacta(arch, '\n');
    dni = new int;
    *dni = numeroDni;
    datosCliente = new void *[2];
    datosCliente[0] = dni;
    datosCliente[1] = nombreCliente;
    return datosCliente;
}

char *leerCadenaExacta(ifstream &arch, char del) {
    char buff[100], *ptr;
    arch.getline(buff, 100, del);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}


//Pregunta 2 

void creareserva(void *&reserva) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Libros.csv");
    void **buffRegistro[300], *datosRegistro, **registroLibros;
    int cantLibros = 0;
    while (true) {
        datosRegistro = leerDatosLibros(arch);
        if (datosRegistro == nullptr) break;
        buffRegistro[cantLibros] = (void **) datosRegistro;
        cantLibros++;
    }
    buffRegistro[cantLibros] = nullptr;
    cantLibros++;
    registroLibros = new void *[cantLibros];
    for (int i = 0; i < cantLibros; i++) registroLibros[i] = buffRegistro[i];
    reserva = registroLibros;
    muestrareservas(reserva);
}

void *leerDatosLibros(ifstream &arch) {
    char *codigo, *nomLibro, *autor, c;
    int *stock;
    double precio;
    void **datos;

    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    codigo = leerCadenaExacta(arch, ',');
    if (codigo == nullptr) return nullptr;
    nomLibro = leerCadenaExacta(arch, ',');
    autor = leerCadenaExacta(arch, ',');
    stock = new int;
    arch >> *stock >> c >> precio;
    arch.get();
    datos = new void *[5];
    datos[0] = codigo;
    datos[1] = nomLibro;
    datos[2] = autor;
    datos[3] = new void *[*stock] {
    };
    datos[4] = stock;
    return datos;
}

//Pregunta 3 

void cargareservar(void *clientes, void *reserva) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos2.csv");
    int dni, cantLibros[400]{};

    void **registroReserva = (void **) reserva;
    void **datosReserva;
    void **pedidosCliente;
    int *stockRegistro;
    char codigo[8];

    //69200503,ZQY9966
    while (true) {
        arch >> dni;
        if (arch.eof())break;
        arch.get();
        arch >> codigo;
        int posLibro = buscarLibro(reserva, codigo); //asumiendo que siempre el libro estará
        datosReserva = (void **) (registroReserva[posLibro]);
        stockRegistro = (int *) (datosReserva[4]);
        if (cantLibros[posLibro] < *stockRegistro) {
            int cantStock = cantLibros[posLibro];
            int posCliente = buscarCliente(clientes, dni);
            pedidosCliente = (void **) (datosReserva[3]);
            pedidosCliente[cantStock] = cargarDatosPedidos(clientes, posCliente);
            cantLibros[posLibro]++;
        }
    }
}

int buscarLibro(void *reserva, char *codigo) {
    void **registro = (void **) reserva;
    for (int i = 0; registro[i]; i++)
        if (iguales(registro[i], codigo))return i;
    cout << "No se encontro el libro" << endl;
    return NO_ENCONTRADO;
}

bool iguales(void *registro, char *codigo) {
    void **datos = (void **) registro;
    char *codigoRegistro = (char *) (datos[0]);
    return (strcmp(codigoRegistro, codigo) == 0);
}

int buscarCliente(void *clientes, int dni) {
    void **registro = (void **) clientes;
    void **datos;
    int *dniCliente;
    for (int i = 0; registro[i]; i++) {
        datos = (void **) (registro[i]);
        dniCliente = (int *) (datos[0]);
        if (*dniCliente == dni)return i;
    }
    cout << "No se encontro el Cliente" << endl;
    return NO_ENCONTRADO;
}

void *cargarDatosPedidos(void *clientes, int posCliente) {
    void **registro = (void **) clientes;
    void **datos = (void **) (registro[posCliente]);
    int *dniCliente = (int *) (datos[0]), *dni;
    char *nombreCliente = (char *) (datos[1]), *nombre;
    void **pedidos = new void *[2];
    dni = new int;
    nombre = new char[(strlen(nombreCliente) + 1)];
    *dni = *dniCliente;
    strcpy(nombre, nombreCliente);
    pedidos[0] = dni;
    pedidos[1] = nombre;
    return pedidos;
}
