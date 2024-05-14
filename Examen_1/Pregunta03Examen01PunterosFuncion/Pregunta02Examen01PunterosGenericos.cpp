
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Pregunta02Examen01PunterosGenericos.h"
#define INCREMENTO 5;   

void cargarProductos(void *&productos, const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << " No se pudo abriri el archivo " << endl;
        exit(1);
    }
    int cantProd = 0, capProd = 0;
    productos = nullptr;

    void *datos;

    while (true) {
        datos = leerRegistroDatos(arch);
        if (datos == nullptr) break;
        if (cantProd == capProd)
            crearEspacios(productos, cantProd, capProd);
        void **registro = new void *[2] {
        };
        registro[0] = datos;
        void **prod = (void **) productos;
        prod[cantProd - 1] = registro;
        //        ((void **)productos)[cantProd-1] = registro;
        cantProd++;
    }
    qsort(productos, cantProd - 1, sizeof (void *), cmpProdcutos);
}

void *leerRegistroDatos(ifstream &arch) {
    void **datos;
    char *codigo, *descrip, c;
    double *precio;
    int *stock;
    //BIT-434,Campana Extractora modelo Glass,375.09,10

    codigo = leerCadenaExacta(arch, ',');
    if (codigo == nullptr) return nullptr;
    precio = new double;
    stock = new int;
    descrip = leerCadenaExacta(arch, ',');
    arch >> *precio >> c >> *stock;
    arch.get();
    datos = new void *[4];
    datos[0] = codigo;
    datos[1] = descrip;
    datos[2] = precio;
    datos[3] = stock;
    return datos;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void crearEspacios(void *&productos, int &cantProd, int &capProd) {
    void **aux;
    capProd += INCREMENTO;

    if (productos == nullptr) {
        productos = new void *[capProd] {
        };
        cantProd = 1;

    } else {
        aux = new void *[capProd] {
        };
        void **registro = (void **) productos;
        for (int i = 0; registro[i]; i++)
            aux[i] = registro[i];
        delete[] registro;
        productos = aux;
    }
}

int cmpProdcutos(const void *reg1, const void *reg2) {
    void **registro1 = (void **) reg1, **registro2 = (void **) reg2;
    void **dupla1 = (void **) (registro1[0]), **dupla2 = (void **) (registro2[0]);
    void **regDatos1 = (void **) (dupla1[0]), **regDatos2 = (void **) (dupla2[0]);
    char *codigo1 = (char *) (regDatos1[0]), *codigo2 = (char *) (regDatos2[0]);
    return (strcmp(codigo1, codigo2));
}

void pruebaDecargarDeProductos(void *productos) {
    ofstream arch("ReporteProductos.txt", ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abriri el archivo de reporte" << endl;
        exit(1);
    }

    arch << setw(60) << "Reporte de Productos " << endl;

    void **registro = (void **) productos;
    void **dupla;
    void **regDatos;
    char *codigo, *descrip;
    double *precio;
    int *stock;
    
    arch << left <<setw(15)<<"codigo"<<setw(63)<<"Descripcion"<<setw(15)<<"Precio"<<"Stock"<<endl;

    for (int i = 0; registro[i]; i++) {
        dupla = (void **) (registro[i]);
        regDatos = (void **) (dupla[0]);
        codigo = (char *) (regDatos[0]);
        descrip = (char *) (regDatos[1]);
        precio = (double *) (regDatos[2]);
        stock = (int *) (regDatos[3]);

        arch << left << setw(15) << codigo << setw(60) << descrip << right << setw(10) << *precio <<
                setw(11) << *stock << endl;

    }



}