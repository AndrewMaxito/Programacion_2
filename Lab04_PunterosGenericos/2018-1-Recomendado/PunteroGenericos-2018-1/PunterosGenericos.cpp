#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "PunterosGenericos.h"

enum Reg {
    CODIGO, NOMBRE, PRESTAMOS, N_PRESTAMO
};

void leerUsurarios(void *&usuarios) {
    ifstream arch("Usuarios.csv", ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo usuarios.csv" << endl;
        exit(1);
    }

    int numUs = 0;
    void *us, *buffUsuarios[100], **usuar;
    //20000992,Morales Karin

    while (true) {

        us = leerUsuario(arch);
        if (us == nullptr) break;
        buffUsuarios[numUs] = us;
        numUs++;
    }

    //creamos un delimitador
    buffUsuarios[numUs] = nullptr;
    numUs++;

    // Almacena  las direcciones de memoria
    usuar = new void *[numUs];
    for (int i = 0; i < numUs; i++) usuar[i] = buffUsuarios[i];
    usuarios = usuar;
}

void *leerUsuario(ifstream &arch) {
    void **usuarios;
    int *codigo, cod;
    char *nombre;

    arch>>cod;
    if (arch.eof()) return nullptr;
    arch.get(); //descarta la coma
    codigo = new int;
    *codigo = cod;
    nombre = leerCadenaExacta(arch, '\n');

    usuarios = new void *[4];
    usuarios[CODIGO] = codigo;
    usuarios[NOMBRE] = nombre;
    usuarios[PRESTAMOS] = nullptr;
    usuarios[N_PRESTAMO] = nullptr;
    return usuarios;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void imprimirUsuarios(void *usuarios) {
    ofstream arch("ReporteUsuario.txt", ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo ReporteUsuario.txt" << endl;
        exit(1);
    }
    void **registro = (void **) usuarios;

    arch << setw(60) << "Registro de Usuarios" << endl;
    arch << "Codigo" << setw(20) << "Nombre" << endl;

    for (int i = 0; registro[i]; i++) {
        arch << right << setfill('0') << setw(2) << i + 1 << setfill(' ') << ")";
        imprimeUsuario(registro[i], arch);

    }
}

void imprimeUsuario(void *registro, ofstream &arch) {
    void **us = (void **) registro;
    int *codigo = (int *) (us[CODIGO]);
    char *nomre = (char *) (us[NOMBRE]);
    arch << left << setw(14) << *codigo << nomre << endl;
}


//------------------------------------------------------------------------------

void leerPrestamos(void *usuarios){
    ifstream arch("Perstamos.csv",ios::in);
    if (not arch.is_open()){
        cout<<"No se pudo abrir el archivo Perstamos.csv "<<endl;
        exit (1);
    }
    
    int *codigoUs,*fecha;
    char *codigoLib;
    char buffCodigos[7];
    
    //20067828,MT2583,27/04/2018
    
    while (true){
        leePrestamo(arch,codigoUs,codigoLib,fecha);
        if (arch.eof()) break;
        cout<<codigoLib<<endl;
        
        
    }
    
    
    
    
}

void leePrestamo(ifstream &arch,int *&codigoUs,char *&codigoLib,int *&fecha){
    int cod,dd,mm,aa;
    char c;
    
    arch >> cod;
    if (arch.eof()) return;
    arch.get();
    codigoLib = leerCadenaExacta(arch,',');
    arch>>dd>>c>>mm>>c>>aa;
    codigoUs = new int ;
    *codigoUs = cod;
    fecha =new int;
    *fecha=aa*10000+mm*100+dd;
}


void imprimirPrestamos(void *usuarios){
    
    
    
}

