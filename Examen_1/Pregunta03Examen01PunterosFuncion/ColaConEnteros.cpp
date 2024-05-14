#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ColaConEnteros.h"
#include "ColaGenerica.h"

void cargaEnteros(void *&cola, void *(*leenumero)(ifstream &), const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    cola = generaCola();

    void *dato;
    while (true) {
        dato = leenumero(arch);
        if (dato == nullptr) break;
        encola(cola, dato);
    }
}

void *leenumero(ifstream &arch) {
    void **dato;
    int *numero, num;
    arch >> num;
    if (arch.eof()) return nullptr;
    numero = new int;
    *numero = num;
    dato = new void *;
    *dato = numero;
    return dato;
}

void mostrarEneteros(void *cola, void (*imprimenumero)(ofstream &, void *), const char *nomArch) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No sepudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    while (!colavacia(cola)) {
        void *dato = desencolar(cola);
        imprimenumero(arch, dato);
        delete (int *) dato; //liberamos espacio del dato ya leido
    }

}

void imprimenumero(ofstream &arch, void *registro) {
    void **dato = (void**) registro;
    int *numero = (int *) (*dato);
    arch << *numero << endl;
}

