#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "Estructuras.h"
#include "BibliotecaEstatica.h"
#include "AperturaDeArchivos.h"


void leerCursos(ifstream &archCurso,struct StCurso *arrCur){
    struct StCurso curso;
    while (archCurso>>curso)arrCur+=curso;
}
void leerAlumnos(ifstream &archAlum,struct StAlumno *arrAlu){
    struct StAlumno alumno;
    while (archAlum>>alumno) arrAlu+=alumno;
//    for(int j=0;arrAlu[j].semestre!=0;j++)cout<<arrAlu[j].codigo<<endl;
}

void cargarMatricula(struct StCurso *arrCur,struct StAlumno *arrAlu,
        const char *nomArchivo ){
    ifstream archMatri;
    AperturaDeUnArchivoDeTextosParaLeer(archMatri,nomArchivo);
    struct StRegistroDeMatricula matricula;
    
    while (archMatri >> matricula){
        arrCur *= matricula;
//        arrAlu *= matricula;   
    }
}