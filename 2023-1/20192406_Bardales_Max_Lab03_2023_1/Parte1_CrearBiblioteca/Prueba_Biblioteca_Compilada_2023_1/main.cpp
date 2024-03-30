/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 29 de marzo de 2024, 16:21
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaEstatica.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"

int main(int argc, char** argv) {
    
    /*Lectura*/
    ifstream archCursos;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos,"Cursos.txt");
    struct StCurso curso[50],cursoIng;
    archCursos >> curso[0];

    ifstream archAlumnos;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos,"Alumnos.txt");
    struct StAlumno alumno[50],aluIng;
    archAlumnos >> alumno[0];
     archAlumnos >> alumno[1];
    
    ifstream archMatricula;
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula,"Matricula.txt");
    struct StRegistroDeMatricula matricula{"INF263" ,20211,1260};
//    archMatricula >> matricula; 
    
    /*Agregacion*/
    
    curso+=cursoIng;
    alumno+=aluIng;
    alumno*=matricula;
    curso *=matricula;
   
    
    /*Impresion*/
    ofstream archRepCur;
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCur,"PruebaCurso.txt");
    archRepCur << curso[0];
    ofstream archRepAlumno;
    AperturaDeUnArchivoDeTextosParaEscribir(archRepAlumno,"PruebaAlumno.txt");
    archRepAlumno << alumno[0];
    archRepAlumno << alumno[1];
    return 0;
}

