
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "listas_genericas.h"

enum NODO {
    DATO, NEXT
};

enum DATOSHEROE {
    CODIGO, NOMBRE, ROL, CATEGORIA, PUNTAJE
};

void *leer_heroe(void *registroHeroe) {
    void **datoHeroe = (void **) registroHeroe;
    return datoHeroe;
}

void crear_lista_heroes(void *arreglo_heroes, void *&lista_heroes, void *(*leer_heroe)(void *)) {
    void **lista = nullptr; //se inicializa apuntando a nullptr
    // Como no se tiene la cantidad de los datos por heroes como parametro en el ingreso se puso 
    // que el ultimo dato apuntara a nullptr asi acabara la iteracion
    void **registro = (void **) arreglo_heroes;

    void **nodo;
    void **ultimoNodo = nullptr;

    for (int i = 0; registro[i]; i++) {
        nodo = new void*[2] {
        }; //creacion del nodo inicilizado en nullptr por defecto 
        nodo[DATO] = leer_heroe(registro[i]);

        if (lista == nullptr)lista = nodo;
        else ultimoNodo[NEXT] = nodo;

        ultimoNodo = nodo;
    }
    lista_heroes = lista;
}

void imprimir_lista_heroes(void *lista_heroes, void (*imprimir_registro_heroe)(ofstream&, void *)) {
    ofstream arch("Reporte-Heroes.txt", ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo Reporte-Heroes.txt" << endl;
    }

    void **nodo = (void **) lista_heroes;
    void *dato;

    arch << left << setw(15) << "Nombre" << setw(15) << "Rol" << setw(15) << "Categoria " <<
            setw(11) << "Puntaje" << "Codigo" << endl;

    while (nodo != nullptr) {
        dato = nodo[DATO];
        imprimir_registro_heroe(arch, dato);
        nodo = (void **) (nodo[NEXT]);
    }
}

void imprimir_registro_heroe(ofstream &arch, void *dato) {
    void **datosHeroe = (void **) dato;
    int *codigo = (int *) (datosHeroe[CODIGO]);
    char *nombre = (char *) (datosHeroe[NOMBRE]);
    char *rol = (char *) (datosHeroe[ROL]);
    char *categoria = (char *) (datosHeroe[CATEGORIA]);
    double *puntaje = (double *) (datosHeroe[PUNTAJE]);

    arch << left << setw(15) << nombre << setw(17) << rol << setw(13) << categoria << right <<
            setw(5) << *puntaje << setw(10) << *codigo << endl;
}

void eliminar_lista_heroes_repetidos(void *&lista_heroes, void (*eliminar_registro)(void **&, void*)) {
    void **actual = (void **) (lista_heroes); //este hara el recorrido
    void **anterior = nullptr;


    while (actual != nullptr) {
        eliminar_registro(actual, anterior); //si se elimina algo solo se eliminara el registro actual
        if (actual == nullptr) break; // se evalua que al salir del bucle lo que esta siendo apuntado no sea nullptr
        anterior = actual;
        actual = (void **) (actual[NEXT]);
    }
}

void eliminar_registro(void **&actual, void *anterior) {
    void **nodoAct = (void **) actual;
    void **nodoAnt = (void **) anterior;

    if (nodoAnt != nullptr) { //importante para la primera iteracion
        void **datoAct = (void **) (nodoAct[DATO]);
        void **datoAnt = (void **) (nodoAnt[DATO]);
        char *nombreAct = (char *) (datoAct[NOMBRE]);
        char *nombreAnt = (char *) (datoAnt[NOMBRE]);

        void *siguiente = nodoAct[NEXT]; //se guarda el dato siguinte por si se elimina

        // Verificar si los nombres son iguales 
        while (strcmp(nombreAct, nombreAnt) == 0) { //por si existen mas de 2
            // Como esta ordenado el anterior simpre tendra mayor puntaje por eso simpre se elimina el siguiente
            
            delete [] nodoAct;
            nodoAnt[NEXT] = siguiente;
            nodoAct = (void **) siguiente; //Es importante definir la nueva direccion si se libero
            if (siguiente == nullptr) break;
            datoAct = (void **) (nodoAct[DATO]);
            nombreAct = (char *) (datoAct[NOMBRE]);
            siguiente = nodoAct[NEXT]; // se vuelve a guardar el nodo siguiente
        }
        actual = nodoAct; //actuliza la direccion de actual
    }
}