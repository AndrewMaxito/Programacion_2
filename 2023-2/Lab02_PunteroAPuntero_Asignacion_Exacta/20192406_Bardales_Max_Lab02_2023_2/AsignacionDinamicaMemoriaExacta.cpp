#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

void lecturaDeProductos(const char *nomArch, char ***&productos,
        int *&stock, double *&precios) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archico " << nomArch << endl;
        exit(1);
    }

    char **buffProducto[500], **datosProducto, c; //En DatoProducto Se almacena la direccion de memoria que contiene el stock y el precio 
    double arrStock[500], arrPrecio[500];
    int cantProd = 0;
    //Este codigo esta diseñado por si los datos del principio seran los que pertenescan a la cadena doblr
    //Cambiara si los primeros datos son simples ahi solo bastara con acabar la iteracion cuando no exista mas datos que leer ((....).eof())


    while (true) {
        datosProducto = leerProducto(arch);
        //Si el puntero doble es nulo significa que no se encontro nda ya que es el primer dato del archivo
        if (datosProducto == NULL) break;
        buffProducto[cantProd] = datosProducto; //se almacena la informacion de las direcciones de memoria que apuntan al dato        
        arch >> arrPrecio[cantProd] >> c >> arrStock[cantProd]; //El resto de la info 
        arch.get(); //descarto el salto de linea
        cantProd++;
    }
    // Ahora se creara las direcciones de memoria en el heap de los datos para que cuando salga de la funcion no se eliminen (Sea dinamico )
    //Se le asigna un valor mas a la cantidad para poner el dilimitador
    productos = new char** [cantProd + 1];
    stock = new int [cantProd + 1];
    precios = new double [cantProd + 1];

    //Almacenamiento de datos de forma dinamica (solo hasta la cantidad de datos oficiales)

    for (int i = 0; i < cantProd; i++) {
        productos[i] = buffProducto[i];
        stock[i] = arrStock[i];
        precios[i] = arrPrecio[i];
    }
    //ahora si le asignara el valor restante 
    productos[cantProd] = 0; //No se si ponerle null ptr aqui xD
    stock[cantProd] = 0;
    precios[cantProd] = 0;
}

void pruebaDeLecturaDeProductos(const char *nomArch, char ***productos,
        int *stock, double *precios) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error no se pudo abri el archivo " << nomArch << endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);

    arch << setw(60) << "Prueba archivo Productos " << endl;
    arch << left << setw(10) << "Codigo" << setw(62) << "Nombre" << setw(11) << "Precio" <<
            "Stock" << endl;
    for (int i = 0; productos[i] != 0; i++) {
        for (int j = 0; j != 2; j++) 
            if (j == 0) {
                arch << left <<setw(10) << productos[i][j];
            } else arch << setw(60)<<productos[i][j];
        arch  << right <<setw(8)<<precios[i] <<setw(8)<< stock[i] << endl;
    }
}

void lecturaDePedidos(const char *nomArch,int *&fechaPedidos,char ***&CodigoPedidos,
        int ***&dniCantPedidos){
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archico " << nomArch << endl;
        exit(1);
    }
    
    char **buffCodigoPedidos[500],**ptrCodigosPedidos;
    int cantidad=0;
// Se debe implementar en base a la cantidad de fechas, y por fecha poner el codigo del producto
// pero no se conoce la cantidad de fechas y estas se repiten en el archivo
    while (true){
        ptrCodigosPedidos = leerProducto(arch);
        if (ptrCodigosPedidos == NULL) break;
        buffCodigoPedidos[cantidad]=ptrCodigosPedidos;
        
        
        
    }
    
    
    
    
    
}
void pruebaDeLecturaDePedidos(const char *nomArch,int *fechaPedidos,char ***CodigoPedidos,
        int ***dniCantPedidos){
    
    
    
}

char **leerPedido1(ifstream &arch) {
    char *cadena, **dato; //SUSTITUIR DUPLA MUY FEO EL NOMBRE
    cadena = leerCadenaExacta(arch, ',');
    if (cadena == NULL) return nullptr;

    dato = new char *[500]; //se crea espacios en el heap 
    dato[0] = cadena; //dato 0 = dato-Codigo
    dato[1] = leerCadenaExacta(arch, ','); //dato 1 = dato-Descripcion
    return dato;
    
    
}





char **leerProducto(ifstream &arch) {
    char *cadena, **dato; //SUSTITUIR DUPLA MUY FEO EL NOMBRE
    cadena = leerCadenaExacta(arch, ',');
    if (cadena == NULL) return nullptr;

    dato = new char *[2]; //se crea espacios en el heap 
    dato[0] = cadena; //dato 0 = dato-Codigo
    dato[1] = leerCadenaExacta(arch, ','); //dato 1 = dato-Descripcion
    return dato;
}

char *leerCadenaExacta(ifstream &arch, char delimi) {
    char buff[100], *ptr;
    arch.getline(buff, 100, delimi);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}