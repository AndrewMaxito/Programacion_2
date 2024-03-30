#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "Estructuras.h"
#include "BibliotecaEstatica.h"
#include "AperturaDeArchivos.h"
#include "EstructuraEscalas.h"
#include "funcionesAuxiliares.h"

#define NO_ENCONTRADO -1
#define CANT_CAR 100

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
        arrAlu *= matricula;
    }
}

void calcularTotales(struct StCurso *arrCur,struct StAlumno *arrAlu,
        const char *nomArchivo){
    ifstream archEsc;
    AperturaDeUnArchivoDeTextosParaLeer(archEsc,nomArchivo);
    struct Escalas arrEscalas[7];
    char c;
    int cantEscalas=0;
    while (true){
        archEsc >> c;
        if (archEsc.eof()) break;
        archEsc >> arrEscalas[cantEscalas].escala>>arrEscalas[cantEscalas].costo;
        cantEscalas ++;
    }
    
    for (int i = 0; arrAlu[i].semestre !=0; i++) {
        int posEscala = buscarEscala(arrEscalas,arrAlu[i].escala, cantEscalas);
        if (posEscala==NO_ENCONTRADO) break;
        
        for (int j = 0;arrAlu[i].numeroDeCursos > j; j++) {
            int posCurso=buscarCurso(arrCur,arrAlu[i].cursos[j]);
            arrAlu[i].costoTotal +=arrCur[posCurso].creditos*arrEscalas[posEscala].costo;
            
            arrCur[posCurso].ingresos += arrCur[posCurso].creditos*arrEscalas[posEscala].costo;
        }
    }   
}

int buscarEscala(struct Escalas *arrEscalas,int escala, int cant){
    for (int i=0;i<cant;i++)
        if (arrEscalas[i].escala==escala) return i;
    cout<< "No se encontro la escala"<<endl;
    return NO_ENCONTRADO;  
}

int buscarCurso(struct StCurso *arrCur,char *codCurso){ //QUE TIPO ES EL CHAR :(
    for (int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        if (strcmp(arrCur[i].codigoDelCurso,codCurso)==0) return i;
    cout<< "No se encontro el curso"<<endl;
    return NO_ENCONTRADO;
}

void emitirReporte(struct StCurso *arrCur,struct StAlumno *arrAlu,
        const char *nomArchivo){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    
    archReporte<<setw(60)<<"Datos por Cursos"<<endl;
    imprimirLineas('=',CANT_CAR,archReporte);
    for (int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++){
        archReporte<<arrCur[i];
        archReporte<<endl;
    }
    archReporte<<setw(60)<<"Datos por Alumno"<<endl;
    imprimirLineas('=',CANT_CAR,archReporte);
    for (int i = 0; arrAlu[i].semestre !=0; i++) {
        archReporte<<arrAlu[i];
        archReporte<<endl;
    }
    
    
}

void imprimirLineas(char car,int cant,ofstream &archReporte){
    for (int i=0;i<cant;i++) archReporte<<car;
    archReporte<<endl;
}
