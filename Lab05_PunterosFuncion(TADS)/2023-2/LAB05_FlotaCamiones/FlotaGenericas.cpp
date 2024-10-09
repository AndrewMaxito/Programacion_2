#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "FlotaGenericas.h"

enum ENodoGenerico {
    SIG, DATO
};

void cargaCamiones(void *&flota, int numcamiones, double pesomaximo, void *(*leeDatosArch)(ifstream &),
        double (*calcula)(void *), const char *nomArch) {

    //Apertura Archivo 
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    void **lflota, *registro, **cabeza;
    double peso, *pesoTotal;
    int indice = 0; // # camion 


    //Inicializacion (se crean los camiones y la pila de informacion que tiene cada uno)
    lflota = new void *[numcamiones] {
    };
    for (int i = 0; i < numcamiones; i++) {
        lflota[i] = crearPila();
    }

    //Leer los datos del archivo

    while (true) {
        registro = leeDatosArch(arch);
        if (registro == nullptr) break;
        peso = calcula(registro);
        // obtener el peso del caminon (pila) donde se encuentra
        cabeza = (void **) (lflota[indice]);
        pesoTotal = (double *) (cabeza[DATO]);
//        cout<<peso<<endl;

        //verificacion del peso maximo en el camion
        if ((peso + *pesoTotal) > pesomaximo) {
            indice++; //si se exede al peso se pasa al siguiente camion
            if (indice == numcamiones) break; //si el numero de camiones se excede termina
        }
        //Agregar dato a la pila
        push(lflota[indice], registro, peso);
    }
    flota = lflota;
}

void *crearPila() {
    void **cabeza = new void *[2] {
    }; //creacion del nodo que inicalimente apunta a 2 nullptr 
    cabeza[DATO] = new double (0);
    return cabeza;
}

void push(void *pila, void *registro, double peso) {
    void **cabeza = (void **) pila;
    void **nuevo = new void *[2] {
    }; //creacion del nodo
    nuevo[DATO] = registro;
    nuevo[SIG] = cabeza[SIG];
    cabeza[SIG] = nuevo;
    double *pesoTotal = (double *) (cabeza[DATO]);
    (*pesoTotal) += peso;
}

void muestraCamiones(void *flota, int numcamiones, void (*imprimenumero)(ofstream &, void *),
        const char *nomArch) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    void **lflota = (void **) flota;
    void **pila, **aux;
    double *peso;

    arch << fixed << setprecision(2);
    for (int i = 0; i < numcamiones; i++) {
        pila = (void **) (lflota[i]);
        peso = (double *) (pila[DATO]);
        arch << "Camion " << setw(2) << i + 1 << setw(7) << ' ';
        arch << "Peso: " << setw(5) << *peso << endl;

        aux = (void **) (pila[SIG]);
        while (aux) {
            imprimenumero(arch, aux[DATO]);
            aux = (void **) (aux[SIG]);
        }
        arch<<endl;
    }
}