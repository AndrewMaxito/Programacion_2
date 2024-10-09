

#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#include "arreglos_genericos.h"

enum DATOSHEROE {
    CODIGO, NOMBRE, ROL, CATEGORIA, PUNTAJE
};

void llenar_arreglo_heroes(void *&arreglo_heroes, int &cantidad_total_heroes, const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    void *datoHeroe, *buffRegistro[500], **registro;


    cantidad_total_heroes = 0;
    while (true) {
        datoHeroe = leerDatosHeroe(arch);
        if (datoHeroe == nullptr) break;
        buffRegistro[cantidad_total_heroes] = datoHeroe;
        cantidad_total_heroes++;
    }
    buffRegistro[cantidad_total_heroes]=nullptr;
    registro = new void *[cantidad_total_heroes+1];
    for (int i = 0; i < cantidad_total_heroes+1; i++) {
        registro[i] = buffRegistro[i];
    }
    arreglo_heroes = registro;
}

void *leerDatosHeroe(ifstream &arch) {
    int cod, *codigoHeroe;
    char *nombre, *rol, *categoria, c;
    double *puntaje;
    void **datos;

    arch >> cod;
    if (arch.eof()) return nullptr;
    codigoHeroe = new int;
    puntaje = new double;
    arch.get(); //lee la coma
    *codigoHeroe = cod;
    nombre = leerCadenaExacta(arch, ',');
    rol = leerCadenaExacta(arch, ',');
    categoria = leerCadenaExacta(arch, ',');
    arch >> *puntaje;
    datos = new void *[5];
    datos[CODIGO] = codigoHeroe;
    datos[NOMBRE] = nombre;
    datos[ROL] = rol;
    datos[CATEGORIA] = categoria;
    datos[PUNTAJE] = puntaje;
    return datos;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[500], *ptr;
    arch.getline(buff, 500, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

int cmp_multicriterio_void(const void *izq, const void *der) {
    void **registroIzq = (void **) izq, **registroDer = (void **) der;
    void **datosIzq = (void **) (*registroIzq), **datosDer = (void **) (*registroDer);
    char *nombreIzq = (char *) (datosIzq[NOMBRE]), *nombreDer = (char *) (datosDer[NOMBRE]);
    double *puntIzq = (double *) (datosIzq[PUNTAJE]), *puntDer = (double *) (datosDer[PUNTAJE]);
    int diferencia;
    // Primero comparar por nombre
    
    if (strcmp(nombreIzq, nombreDer) != 0) // Si los nombres son diferentes, retorna la diferencia
        return strcmp(nombreIzq, nombreDer);
    else return (*puntDer -*puntIzq); //caso contrario evalua sus puntajes
}

void imprimirDatos(void *arreglo_heroes, int cantidad_total_heroes) {
    void **registro = (void **) arreglo_heroes;
    void **datos;
    int *codigo;
    char *nombre, *rol, *catego;
    double *puntaje;


    for (int i = 0; i < cantidad_total_heroes; i++) {
        datos = (void **) (registro[i]);
        codigo = (int *) (datos[CODIGO]);
        nombre = (char *) (datos[NOMBRE]);
        rol = (char *) (datos[ROL]);
        catego = (char *) (datos[CATEGORIA]);
        puntaje = (double *) (datos[PUNTAJE]);
        cout <<*codigo << "  " << nombre << "  " << rol << "  " << catego << "  " << *puntaje << endl;
    }
}


