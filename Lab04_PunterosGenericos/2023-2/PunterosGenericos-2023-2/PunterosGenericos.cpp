#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "PunterosGenericos.h"
#define NO_ENCONTRADO -1

enum {
    CODIGO, DESCRIP, PRECIO, TIPO
};

enum {
    DNI, NOMBRE, LISTAPED, LINEAC
};
enum{
    CODIGOPROD,CANTPRO,TOTALPREPRO
};

void cargarProductos(void *&productos) {

    ifstream arch("Productos2.csv", ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << endl;
        exit(1);
    }
    void *datosProducto, **registroProd, *buffDatosProd[300];
    int cant = 0;

    //BIT-434,Campana Extractora modelo Glass,375.09,S
    while (true) {
        datosProducto = leerDatosProducto(arch);
        if (datosProducto == nullptr) break;
        buffDatosProd[cant] = datosProducto;
        cant++;
    }
    buffDatosProd[cant] = nullptr;
    cant++;
    registroProd = new void *[cant];
    for (int i = 0; i < cant; i++) registroProd[i] = buffDatosProd[i];
    productos = registroProd;
}

void *leerDatosProducto(ifstream &arch) {
    char *codigo, *descripcion, *tipo, letra;
    double *precio, preci;
    void **datosProducto;
    codigo = leerCadenaExacta(arch, ',');
    if (codigo == nullptr) return nullptr;
    descripcion = leerCadenaExacta(arch, ',');
    arch >> preci;
    arch.get();
    arch >>letra;
    arch.get();


    precio = new double;
    *precio = preci;

    tipo = new char;
    *tipo = letra;
    datosProducto = new void *[4];
    datosProducto[CODIGO] = codigo;
    datosProducto[DESCRIP] = descripcion;
    datosProducto[PRECIO] = precio;
    datosProducto[TIPO] = tipo;
    return datosProducto;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void cargarClientes(void *&clientes) {
    ifstream arch("Clientes2.csv", ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << endl;
        exit(1);
    }
    void *cli, *buffCliente[200], **registroCliente;
    int cant = 0;

    //79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000

    while (true) {
        cli = leerDatosCliente(arch);
        if (cli == nullptr) break;
        buffCliente[cant] = cli;
        cant++;
    }
    buffCliente[cant] = nullptr;
    cant++;
    registroCliente = new void *[cant];
    for (int i = 0; i < cant; i++) registroCliente[i] = buffCliente[i];
    clientes = registroCliente;
}

void *leerDatosCliente(ifstream &arch) {
    int *dni, numDni, *tipoLinea, linea, telefono;
    char *nombre, c;
    void **datosCliente;

    arch >> numDni;
    if (arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadenaExacta(arch, ',');
    arch >> telefono >> c >> linea;
    dni = new int;
    tipoLinea = new int;
    *dni = numDni;
    *tipoLinea = linea;

    datosCliente = new void *[4];
    datosCliente[DNI] = dni;
    datosCliente[NOMBRE] = nombre;
    datosCliente[LISTAPED] = nullptr;
    datosCliente[LINEAC] = tipoLinea;

    return datosCliente;
}



//pregunta 2

void cargarPedidos(void *productos, void *clientes) {
    ifstream arch("Pedidos2.csv", ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo Pedidos2.csv" << endl;
        exit(1);
    }
    void *ped, *buffPedidos[500]{}, *pedidos;
    int posCli,cant[300]{};


    //JXD-139,50375303,6
    while (true) {
        ped = leerDatosPedido(arch, productos, clientes,posCli);
        if (ped == nullptr) break;
        void **registroCliente=(void **)clientes;
        añadirPedido(buffPedidos[posCli],ped,registroCliente[posCli]);
        
        
    }
    
}

void *leerDatosPedido(ifstream &arch, void *productos, void *clientes,int &posCliente) {
    char *codigo, c;
    int *dni, dniNum, *cantidadPedi, cantPedi;
    double *precioTotal;
    void **pedido;

    codigo = leerCadenaExacta(arch, ',');
    if (codigo == nullptr) return nullptr;
    arch >> dniNum >> c >> cantPedi;
    arch.get();
    dni = new int;
    cantidadPedi = new int;
    precioTotal = new double;
    *dni = dniNum;
    *cantidadPedi = cantPedi;
    int posProd = buscaraProducta(productos, codigo);
    posCliente = buscaraCliente(clientes, dniNum);

    void **registroCliente = (void **) clientes;
    void **datoCliente = (void **) (registroCliente[posCliente]);
    int *lineaC = (int *) (datoCliente[posCliente]);

    void **registroProd = (void **) productos;
    void **datoProd = (void **) (registroProd[posProd]);
    char *tipo = (char *) (datoProd[TIPO]);
    double *precio = (double *) (datoProd[PRECIO]);


    *precioTotal = (*precio)* (cantPedi);

    if (*tipo == 'S') {
        if (*lineaC > 0 and *lineaC >= *precioTotal) {
            *lineaC -= *precioTotal;
        } else return nullptr;
    }
    
    pedido = new void *[3];
    pedido[CODIGOPROD]=codigo;
    pedido[CANTPRO]=cantidadPedi;
    pedido[TOTALPREPRO]=precioTotal;
    return pedido;
}

int buscaraProducta(void *productos, char *codigo) {
    void **registroProductos = (void **) productos;
    for (int i = 0; registroProductos[i]; i++) {
        if (iguales(registroProductos[i], codigo))return i;
    }
    cout << "no se encontro" << endl;
    return NO_ENCONTRADO;
}

int buscaraCliente(void *clientes, int dni) {
    void **registroClientes = (void **) clientes;
    for (int i = 0; registroClientes[i]; i++) {
        if (iguales(registroClientes[i], dni)) return i;
    }
    return NO_ENCONTRADO;


}

bool iguales(void *registroProductos, char *codigo) {
    void **datosProducto = (void **) registroProductos;
    char *codigoReg = (char *) (datosProducto[CODIGO]);
    return strcmp(codigoReg, codigo) == 0;
}

bool iguales(void *registroClientes, int dni) {
    void **datosCliente = (void **) registroClientes;
    int *dniCliente = (int *) (datosCliente[DNI]);
    return *dniCliente == dni;
}


void añadirPedido(void *buffPedidos,void *ped,void *registroCliente){
    void **datosPedido = (void **)registroCliente;
    if (datosPedido[LISTAPED]==nullptr){
        
        
        
    }else{
        
    }
    
    
    
    
}

