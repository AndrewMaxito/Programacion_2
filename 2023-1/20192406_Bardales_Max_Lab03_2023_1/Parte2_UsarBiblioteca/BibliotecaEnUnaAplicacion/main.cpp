/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 29 de marzo de 2024, 22:32
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "funcionesAuxiliares.h"
#include "AperturaDeArchivos.h"
#include "BibliotecaEstatica.h"
#include "Estructuras.h"

int main(int argc, char** argv) {
    struct StCurso arrCur[80];
    struct StAlumno arrAlu[80];
    
    ifstream archCurso;
    AperturaDeUnArchivoDeTextosParaLeer(archCurso,"Cursos.txt");
    ifstream archAlum;
    AperturaDeUnArchivoDeTextosParaLeer(archAlum,"Alumnos.txt");
    
    
    leerCursos(archCurso, arrCur);
    leerAlumnos(archAlum, arrAlu);
    
    cargarMatricula(arrCur,arrAlu,"Matricula.txt");



    return 0;
}

