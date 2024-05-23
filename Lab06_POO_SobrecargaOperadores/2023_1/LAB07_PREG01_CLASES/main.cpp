/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 10:14
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funcionesAuxiliares.h"
#include "alumno.h"
#include "alumnonota.h"
#include "nota.h"

int main(int argc, char** argv) {
    ifstream archA("Alumnos.csv", ios::in);
    if (not archA.is_open()) {
        cout << "no se pudo abrir el archivo alumnos " << endl;
        exit(1);
    }
    ifstream archN("Notas.csv", ios::in);
    if (not archN.is_open()) {
        cout << "no se pudo abrir el archivo Nota " << endl;
        exit(1);
    }
    ofstream archR("AlumnosPrubea.txt", ios::out);
    if (not archN.is_open()) {
        cout << "no se pudo abrir el archivo reporte prueba " << endl;
        exit(1);
    }


    //
    //-Lectura
    class alumno alumnos[100];
    int numAlumnos = 0;

    while (true) {
        archA >> alumnos[numAlumnos];
        if (archA.eof()) break;
        numAlumnos++;
    }


    /* 
    for (int i = 0; i < numAlumnos; i++) {
        char nombreAlu[100];
        alumnos[i].GetNombre(nombreAlu);
        cout<<nombreAlu<<endl;

    }
     */
    class alumnonota aluNotas[200];
    int numNotas = 0;
    while (true) {
        archN >> aluNotas[numNotas];
        if (archN.eof()) break;
        numNotas++;
    }

    /* 
    for (int i = 0; i < numAlumnos; i++) {
        char nombreAlu[100];
        alumnos[i].GetNombre(nombreAlu);
        cout<<nombreAlu<<endl;

    }
     */



    //Cargar Notas
    class nota notas[numNotas + 1]; //si hay 0 numero de notas por si acaso creo una extra

    for (int i = 0; i < numNotas; i++) {
        
        aluNotas[i] & notas[i];
    }

    for (int i = 0; i < numNotas; i++) {
        for (int j = 0; j < numAlumnos; j++) {
            if (aluNotas[i].GetCodigo() == alumnos[j].GetCodigo()){
                
                alumnos[j] += notas[i];
               
            }   
        }
    }
    //se debe actulizar los datos del alumno de acuerdo a las notas que tiene
    for (int i = 0; i < numAlumnos; i++) {
        alumnos[i].actulizar();
    }

    for (int i = 0; i < numAlumnos; i++) {
        archR << alumnos[i];
    }
    return 0;
}

