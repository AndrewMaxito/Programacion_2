#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "alumno.h"
#include "alumnonota.h"

void operator>>(ifstream &arch, class alumno &alu) {
    int codAl;
    char nombre[100], buff[200];
    arch >> codAl;
    if (arch.eof())return;
    arch.get();
    arch.getline(nombre, 100, ',');
    
    arch.getline(buff, 200, '\n');

    //
    alu.SetCodigo(codAl);
    alu.SetNombre(nombre);
}

void operator>>(ifstream &arch, class alumnonota &notAlu) {
    int codigoAlu, ciclo, nota;
    char codCurso[7], c;
    arch >> codigoAlu;
    if (arch.eof()) return;
    arch.get();
    arch.getline(codCurso, 7, ',');
    arch >> ciclo >> c >> nota;
    
    //
    notAlu.SetCodigo(codigoAlu);
    notAlu.SetCodcurso(codCurso);
    notAlu.SetCliclo(ciclo);
    notAlu.SetNota(nota);
}

void operator<<(ofstream &arch, const class alumno &alu) {
    char nombreAlu[100];
    alu.GetNombre(nombreAlu);
    arch << right << "Codigo del alumno:     " << alu.GetCodigo() << endl;
    arch << "Nombre del alumno:    " << nombreAlu << endl;
    arch << "Detalles del curso:    " << endl;
    arch << left << setw(10) << "Cursados" << setw(10) << "Aprobados" << setw(10) << "1era vez" <<
            setw(10) << "2era vez" << setw(10) << "3era vez" << endl;
    arch << setw(5) << ' ' << setw(10) << alu.GetNumcurso() << setw(10) << alu.GetNumaprobados() <<
            setw(10) << alu.GetNumprimera() << setw(10) << alu.GetNumsegunda() << setw(10) <<
            alu.GetNumtercera() << endl<<endl;
}

