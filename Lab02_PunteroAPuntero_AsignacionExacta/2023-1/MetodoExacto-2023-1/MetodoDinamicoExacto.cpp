
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "MetodoDinamicoExacto.h"
#define NO_ENCONTRADO -1

void lecturaAlumnos(const char *nombArch, int *&alumno_Codigo, char** &alumno_Nombre,
        char *&alumno_Modalidad, int *& alumno_Porcentaje, int *&alumno_Escala) {

    ifstream archAlum(nombArch, ios::in);
    if (not archAlum.is_open()) {
        cout << "No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int arrCodigo[200]{}, arrPorce[200]{}, arrEscala[200]{}, codigo, cant = 0;
    char arrModalidad[200]{};
    char *buffNom[200]{}, *nomb;
    char modalidad, c;
    int escala;


    while (true) {
        archAlum >>codigo;

        if (archAlum.eof()) break;
        arrCodigo[cant] = codigo;

        archAlum.get();
        nomb = leerCadenaExacta(archAlum);
        buffNom[cant] = nomb;
        archAlum >> escala;

        if (archAlum.fail()) {
            archAlum.clear();
            archAlum >> modalidad>>c;
            switch (modalidad) {
                case 'V':
                    arrModalidad[cant] = modalidad;
                    arrPorce[cant] = 0;
                    archAlum >> arrEscala[cant];
                    break;
                case 'S':
                    arrModalidad[cant] = modalidad;
                    archAlum >> arrPorce[cant] >> c >> arrEscala[cant];
                    break;
            }

        } else {
            arrModalidad[cant] = 'P';
            arrPorce[cant] = 0;
            arrEscala[cant] = escala;
        }

        // creo que no es necesario poner el else y sacarlo defrente luego de hacer los casos 
        cant++;
    }


    // creaccion de espacios de memoria excacto 
    alumno_Codigo = new int [cant + 1];
    alumno_Nombre = new char * [cant + 1];
    alumno_Modalidad = new char [cant + 1];
    alumno_Porcentaje = new int [cant + 1];
    alumno_Escala = new int [cant + 1];

    for (int i = 0; i < (cant + 1); i++) {
        alumno_Codigo[i] = arrCodigo[i];

        alumno_Nombre[i] = buffNom[i];
        alumno_Modalidad[i] = arrModalidad[i];
        alumno_Porcentaje[i] = arrPorce[i];
        alumno_Escala[i] = arrEscala[i];
    }
}

void pruebaLecturaAlumnos(const char *nombArch, int *alumno_Codigo, char** alumno_Nombre,
        char *alumno_Modalidad, int * alumno_Porcentaje, int *alumno_Escala) {

    ofstream archRep(nombArch, ios::out);
    if (not archRep.is_open()) {
        cout << "No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    archRep << setw(60) << "Verificaccion de datos" << endl;
    archRep << "Codigo" << left << setw(25) << ' ' << setw(35) << "Nombre" << setw(10) << "Modalidad" << setw(12) <<
            "Porcentaje" << "Escala" << endl;

    for (int i = 0; alumno_Nombre[i]; i++) {
        archRep << left << setw(20) << alumno_Codigo[i] << setw(50) << alumno_Nombre[i] <<
                setw(10) << alumno_Modalidad[i] << setw(10) << alumno_Porcentaje[i] <<
                alumno_Escala[i] << endl;
    }
}

void lecturaCursos(const char *nomArch, int *alumno_Codigo, int *alumno_Escala, char **&curso_Nombre,
        double *&curso_Credito, int **& curso_Alumnos) {

    ifstream archCursos(nomArch, ios::in);
    if (not archCursos.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    int codigoAlum, cantCurs = 0;
    char *buffNomCur[200]{}, *nombCur, c;
    double arrCreditos[200]{};
    int *arrCursoAlumnos[200]{}, *ptrCurAlu;
    int *arrCursoAlumnos_2[200]{};

    char arrCurso[100];

    while (true) {
        archCursos >> codigoAlum;
        if (archCursos.eof()) break;
        archCursos.get();
        nombCur = leerCadenaExacta(archCursos);
        buffNomCur[cantCurs] = nombCur;
        archCursos >> arrCreditos[cantCurs];
        strcpy(arrCurso, buffNomCur[cantCurs]);

        int posCurso = buscarCurso(buffNomCur, arrCurso, cantCurs);
        int posAlum = buscarPosAlumno(alumno_Codigo, codigoAlum);
        if (posAlum == NO_ENCONTRADO) {
            cout << "ERROR NO ALUMNO" << endl;
            break;
        }
        if (posCurso != NO_ENCONTRADO) {
            int i = 0;
            cantCurs--; //omito acumularlo
            for (i; arrCursoAlumnos[posCurso][i] != 0; i++);
            arrCursoAlumnos[posCurso][i] = codigoAlum;
            arrCursoAlumnos[posCurso][i + 1] = alumno_Escala[posAlum];

        } else {
            arrCursoAlumnos[cantCurs] = new int [200] {};
            arrCursoAlumnos[cantCurs][0] = codigoAlum;
            arrCursoAlumnos[cantCurs][1] = alumno_Escala[posAlum];
        }
        cantCurs++;
    }
    buffNomCur[cantCurs]=0; //escencial para eliminar el ultimo dato------------------------
    
    
    int loco;
    for (int i=0;i<cantCurs;i++){
        int j=0;
        for ( j;arrCursoAlumnos[i][j];j++);
        arrCursoAlumnos_2[i]=new int [j+1];
        for (int k=0;k<j+1;k++) arrCursoAlumnos_2[i][k]=arrCursoAlumnos[i][k];  
    }
    
    
    curso_Nombre=new char *[cantCurs+1];
    curso_Credito=new double [cantCurs+1];
    curso_Alumnos=new int *[cantCurs+1];
    
    for (int i=0;i<(cantCurs+1);i++){
        curso_Nombre[i]=buffNomCur[i];
        curso_Credito[i]=arrCreditos[i];
        curso_Alumnos[i]=arrCursoAlumnos_2[i];
    }
    
    
}

void pruebaLecturaCursos(const char *nombArch, char **curso_Nombre, double *curso_Credito,
        int ** curso_Alumnos) {
    ofstream arch(nombArch,ios :: out);
    if(not arch.is_open()){
        cout << "ERROR: No se puede abrir el archivo" << nombArch << endl;
        exit(1);
    }
    int *alumnos;
    arch << left << setw(20) << "CODIGO" << setw(50) << "NOMBRE" << setw(5) << "MODALIDAD" << setw(5) << "PORCENTAJE" << "ESCALA" << endl;
    for(int i=0;curso_Nombre[i];i++){
        arch << left << setw(50) << curso_Nombre[i] << curso_Credito[i] << endl;
        for(int j=0;curso_Alumnos[i][j];j++){
            if (j%2 == 0){
                arch << curso_Alumnos[i][j]<< "-";
            }else{
                arch << left << setw(5) << curso_Alumnos[i][j] << "  ";            
            }
            
        }
        arch<<endl;
    }
}

char *leerCadenaExacta(ifstream &archAlum) {
    char buff[100], *ptr;
    archAlum.getline(buff, 100, ',');
    if (archAlum.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

int buscarCurso(char **buffNomCur, char *codCurso, int cantCurs) { //NO ENTIENDO EL DOBLE ASTERISCO AQUI
    for (int i = 0; i < cantCurs; i++)
        if (strcmp(buffNomCur[i], codCurso) == 0) return i; //se repite
    return NO_ENCONTRADO;
}

int buscarPosAlumno(const int *alumno_Codigo, int codigoAlum) {
    for (int i = 0; alumno_Codigo[i] != 0; i++)
        if (alumno_Codigo[i] == codigoAlum)return i;
    cout << "No se encontro al alumno" << endl;
    return NO_ENCONTRADO;
}