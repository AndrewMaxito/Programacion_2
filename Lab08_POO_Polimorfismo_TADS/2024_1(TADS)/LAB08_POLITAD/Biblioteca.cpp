

/* 
 * File:   Biblioteca.cpp
 * Author: andre
 * 
 * Created on 17 de noviembre de 2024, 01:50 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
#include "Novela.h"
#include "Enciclopedia.h"
#include "Revista.h"
#define CANT_LIN 80

void Biblioteca::carga() {
    ifstream arch("Estantes2.csv", ios::in);
    if (!arch) {
        cout << "No se pudo abrir el archivo Estantes2.csv" << endl;
        exit(1);
    }

    int cantEst = 0;
    char clase, c;
    int id;
    double capacidad;
    while (true) {
        arch >> clase;
        if (arch.eof())break;
        arch >> c >> id >> c >> capacidad;
        //
        AEstenates[cantEst].SetId(id);
        AEstenates[cantEst].SetClase(clase);
        AEstenates[cantEst].SetCapacidad(capacidad);
        cantEst++;
    }
}
//N,Diamantes y pedernales,120,0.4,Jose Maria Arguedas
//E,ENCICLOPEDIA SALVAT,2000,12,78323,2015
void Biblioteca::llena(){
    ifstream arch("Libros3.csv", ios::in);
    if (!arch) {
        cout << "No se pudo abrir el archivo Libros3.csv" << endl;
        exit(1);
    }
    Libro *libroLeido;
    char tipo;
    while (true) {
        arch >> tipo;
        if (arch.eof())break;
        arch.get();//coma
        switch (tipo){
            case 'N':
                libroLeido = new Novela;
                break;
            case 'E':
                libroLeido = new Enciclopedia;
                break;
            case 'R':
                libroLeido = new Revista;
                break;
        }
        libroLeido->lee(arch);
        double pesoLibro = libroLeido->GetPeso();
        bool flag = false;
        
        for (int i = 0;AEstenates[i].GetId()!=0; i++) {
            double capDispo = AEstenates[i].GetPesoDisponible();
            if (capDispo >= pesoLibro){
                flag = true;
                AEstenates[i].agregarLibro(libroLeido);
                break;
            }
        }
        if (flag == false) delete libroLeido;
    }
    
}

void Biblioteca::baja() {
    for (int i = 0;AEstenates[i].GetId(); i++) {
        AEstenates[i].verificarVigencia();
    }
}

void Biblioteca::muestra() {
    ofstream arch("ReporteEstantes.txt",ios::out);
    if (!arch) {
        cout << "No se pudo abrir el archivo ReporteEstantes.txt"<<endl;
        exit(1);
    }
    
    arch << "Estantes: "<<endl;
    imprimirLineas(arch,CANT_LIN,'=');
    
    for (int i = 0; AEstenates[i].GetId(); i++) {
        AEstenates[i].imprimirDatosEstante(arch);
    }
}

void Biblioteca::imprimirLineas(ofstream& arch, int cant, char car) {
    for (int i = 0; i < cant; i++) arch << car;
    arch << endl;
}


