

/* 
 * File:   PunterosGenericos.cpp
 * Author: andre
 * 
 * Created on 26 de setiembre de 2024, 15:16
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#define NO_ENCONTRADO -1
#define INCREMENTO 5
#define CANT_CARAC 100

void cargaProducto(void *&productos) {
    ifstream arch("Productos2.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo Productos2.csv" << endl;
        exit(1);
    }
    //Se usara el metodo de memoria excata (asiganacion exacta)
    void *buffProductos[300], *datoProducto, **prod;
    int cantPro = 0;
    //BIT-434,Campana Extractora modelo Glass,375.09,S
    //SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,S
    while (true) {
        datoProducto = cargaDatosProducto(arch);
        if (datoProducto == nullptr)break;
        buffProductos[cantPro] = datoProducto;
        cantPro++;
    }
    buffProductos[cantPro] = nullptr;
    cantPro++;
    prod = new void* [cantPro];
    for (int i = 0; buffProductos[i]; i++) {
        prod[i] = buffProductos[i];
    }
    prod[cantPro - 1] = nullptr;
    productos = prod;
}

void *cargaDatosProducto(ifstream &arch) {
    char *codPro;
    codPro = leerCadenaExacta(arch, ',');
    if (codPro == nullptr)return nullptr;
    arch.get(); // coma
    char *nombrePro, *tipoPro = new char;
    double *precioPro = new double;

    nombrePro = leerCadenaExacta(arch, ',');
    arch >> *precioPro;
    arch.get(); // coma
    arch >> *tipoPro; //solo es una letra
    arch.get(); //salto de linea
    void *dato = new void* [4] {
        codPro, nombrePro, precioPro, tipoPro
    };
    return dato;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof())return nullptr;
    ptr = new char[strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void cargaClientes(void *&cliente) {
    ifstream arch("Clientes2.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo Clientes2.csv" << endl;
        exit(1);
    }

    //Memoria exacta 
    void *buffCliente[200], *datoCli, **cli;
    int cantCli = 0;

    while (true) {
        datoCli = cargarDatosClinete(arch);
        if (datoCli == nullptr)break;
        buffCliente[cantCli] = datoCli;
        cantCli++;
    }
    buffCliente[cantCli] = nullptr;
    cantCli++;

    cli = new void* [cantCli];
    for (int i = 0; buffCliente[i]; i++) {
        cli[i] = buffCliente[i];
    }
    cli[cantCli - 1] = nullptr;
    cliente = cli;
}

void *cargarDatosClinete(ifstream &arch) {
    //    79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
    //16552775,YALLICO PAREDES LOURDES CARMELA,960176666,20000
    int buDni, basura;
    arch >> buDni;
    if (arch.eof())return nullptr;
    int *dniCli = new int (buDni);
    arch.get(); //coma
    char *nombreCliente = leerCadenaExacta(arch, ',');
    double *lineaCre = new double;
    arch >> basura;
    arch.get(); //coma
    arch >> *lineaCre;

    void **datosCliente = new void*[4];
    datosCliente[0] = dniCli;
    datosCliente[1] = nombreCliente;
    datosCliente[2] = nullptr;
    datosCliente[3] = lineaCre;
    return datosCliente;
}

void cargarPedidos(void *productos, void *cliente) {
    ifstream arch("Pedidos2.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo Pedidos2.csv" << endl;
        exit(1);
    }

    //JXD-139,50375303,6
    //CRU-009,50375303,5
    char codProDat[8], c;
    int dniDat, cantidadDat;

    int arrCantProdCli[200]{}, arrCapProdCli[200]{};
    while (true) {
        arch.getline(codProDat, 8, ',');
        if (arch.eof())break;
        arch >> dniDat >> c >> cantidadDat;
        arch.get(); //salto de linea
        //         cout<<dniDat<<endl;
        int posProducto = buscarProducto(productos, codProDat);
        void **regProductos = (void **) productos;
        void **datosProducto = (void **) (regProductos[posProducto]);
        char *tipo = (char *) (datosProducto[3]);
        double *precioPro = (double *) (datosProducto[2]);

        double precioTotal = (*precioPro) * cantidadDat;
        bool flag = false;

        int posCli = buscarCliente(cliente, dniDat);
        void **regCliente = (void **) cliente;
        void **datosCliente = (void **) (regCliente[posCli]);

        if (*tipo == 'S') {
            double *lineaCred = (double *) (datosCliente[3]);
            if ((*lineaCred) >= precioTotal) {
                *lineaCred -= precioTotal;
                flag = true;
            }
        }
        if (*tipo == 'N' or flag == true) {
            if (arrCantProdCli[posCli] == arrCapProdCli[posCli])
                aumnetarEspacios(datosCliente[2], arrCantProdCli[posCli], arrCapProdCli[posCli]);
            int posLibre = arrCantProdCli[posCli] - 1;
            void **listaPedidosAcep = (void **) (datosCliente[2]);

            //Crea espacios para los datos que ingresaran
            char *codigoProd = new char[strlen(codProDat) + 1];
            int *cantProd = new int (cantidadDat);
            double *totalPrecio = new double (precioTotal);
            strcpy(codigoProd, codProDat);
            listaPedidosAcep[posLibre] = new void*[3] {
                codigoProd, cantProd, totalPrecio
            };
            arrCantProdCli[posCli]++;
        }
    }
}

int buscarProducto(void *productos, const char *codProDat) {
    void **regProductos = (void **) productos;
    for (int i = 0; regProductos[i]; i++) {
        void **datosProducto = (void **) (regProductos[i]);
        char *codigo = (char *) (datosProducto[0]);
        if (strcmp(codigo, codProDat) == 0) return i;
    }
    cout << " No se encontro el producto" << codProDat << endl;
    exit(1); //en teoria siempre deberia econtrar el producto
    return NO_ENCONTRADO;
}

int buscarCliente(void *cliente, const int dniDat) {
    void **regCliente = (void **) cliente;
    for (int i = 0; regCliente[i]; i++) {
        void **datosCliente = (void **) (regCliente[i]);
        int *dni = (int *) (datosCliente[0]);
        if (*dni == dniDat) return i;
    }
    cout << " No se encontro el Cliente" << dniDat << endl;
    exit(1); //en teoria siempre deberia econtrar el producto
    return NO_ENCONTRADO;
}

void aumnetarEspacios(void *&pedidosAcep, int &cant, int &cap) {
    cap += INCREMENTO;
    if (pedidosAcep == nullptr) {
        pedidosAcep = new void*[cap] {
        };
        cant = 1;
    } else {
        void **auxPedido = new void*[cap] {
        };
        void **listaPed = (void **) pedidosAcep;
        for (int i = 0; listaPed[i]; i++) {
            auxPedido[i] = listaPed[i];
        }
        delete listaPed; //creo que aqui estoy bien y mal
        pedidosAcep = auxPedido;
    }
}

void imprimeReporte(void *cliente) {
    ofstream arch("ReporteDePedidos.txt", ios::out);
    if (!arch.is_open()) {
        cout << "Error con la apertura del reporte de la pregunta 3" << endl;
        exit(1);
    }
    void **regCliente = (void **) cliente;
    arch << fixed;
    arch << setprecision(2);
    for (int i = 0; regCliente[i]; i++) {
        void **datosCliente = (void **) (regCliente[i]);
        int *dni = (int *) (datosCliente[0]);
        char *nombre = (char *) (datosCliente[1]);
        double *credito = (double *) (datosCliente[3]);
        imprimirLineas(arch, CANT_CARAC, '=');
        arch << left << setw(20) << "DNI" << setw(50) << "NOMBRE" << "CREDITO" << endl;
        arch << setw(20) << *dni << setw(50) << nombre << *credito << endl;
        imprimirLineas(arch, CANT_CARAC, '-');
        arch << "Pedidos Atendidos: " << endl;
        imprimirLineas(arch, CANT_CARAC, '-');
        arch << setw(10) << "Codigo" << setw(13) << "Cantidad" << "Total" << endl;
        imprimirLineas(arch, CANT_CARAC, '-');

        if (datosCliente[2] != nullptr) {
            void **listaProdAcep = (void **) (datosCliente[2]);
            for (int j = 0; listaProdAcep[j]; j++) {
                void **datosLista = (void **)(listaProdAcep[j]);
                char *codigo = (char *)(datosLista[0]);
                int *cantidad = (int *)(datosLista[1]);
                double *totalPedido = (double *)(datosLista[2]);
                arch << left <<setw(7) << codigo <<right << setw(7) << 
                        *cantidad << setw(14)<<*totalPedido << endl;
            }
            arch<<endl;
        }
    }
}

void imprimirLineas(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++) arch << car;
    arch << endl;
}
