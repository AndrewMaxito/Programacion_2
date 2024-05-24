#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "alumno.h"
#include "alumnonota.h"
#include "funcionesAuxiliares.h"

void cargaralumno(class alumno* lalumnos) {
    ifstream arch("alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout << " No se pudo abri el archivo alumnos " << endl;
        exit(1);
    }
    int cont = 0;
    while (true) {
        arch >> lalumnos[cont];
        if (arch.eof()) break;
        cont++;
    }
}

void carganotas(class alumnonota* lnotas) {
    ifstream arch("notas.csv", ios::in);
    if (not arch.is_open()) {
        cout << " No se pudo abri el archivo notas " << endl;
        exit(1);
    }
    int cont = 0;
    while (true) {
        arch >> lnotas[cont];
        if (arch.eof()) break;
        cont++;
    }
}

void actulizarnotas(class alumno* lalumnos, const class alumnonota* lnotas) {

    //Primero se ingresaran todas las notas del alumno 
    for (int i = 0; lnotas[i].GetCodigo() != 0; i++)
        for (int j = 0; lalumnos[j].GetCodigo() != 0; j++)
            if (lnotas[i].GetCodigo() == lalumnos[j].GetCodigo()) {
                class nota regNota;
                lnotas[i] & regNota;
                lalumnos[j] += regNota;
                break;
            }


    //Como ya se registraron todas sus notas se procedera a analizarlas y incrementar los cursos
    for (int i = 0; lalumnos[i].GetCodigo() != 0; i++)
        lalumnos[i].actulizar();

}

void imprimealumnos(const class alumno* lalumnos) {
    ofstream arch("Reporte.txt", ios::out);
    if (not arch.is_open()) {
        cout << " No se pudo abri el archivo reporte " << endl;
        exit(1);
    }

    for (int i = 0; lalumnos[i].GetCodigo() != 0; i++)
        arch << lalumnos[i];
}