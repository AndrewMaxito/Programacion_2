
/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: andre
 * 
 * Created on 18 de septiembre de 2024, 11:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1
#define CANT_FIN 72

void lecturaDeLibros(const char *nomArch, char ***&libros, int **&stock) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);
    //primer paso inicializar los punteros en 0
    libros = nullptr;
    stock = nullptr;
    //cantidad y capacidad actual (al inicio empiezan en 0)
    int cantLibros = 0, capacidad = 0;
    //creamos los punteros DINAMICOS donde se guardaran los datos (cuando es de ms de una dimension)
    char *codigo, *descrip, *autor, c;
    int bffStock;
    double basuPrecio;

    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    //YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
    //ZOY6470,El viejo y el mar,Hernest Hemingway,25,68.01
    while (true) {
        //lectura de los datos
        codigo = leerCadenaExacta(arch, ',');
        if (codigo == nullptr) break;
        descrip = leerCadenaExacta(arch, ',');
        autor = leerCadenaExacta(arch, ',');
        arch >> bffStock >> c >> basuPrecio;
        arch.get(); // salto de linea

        //incremento de memoria (si lo necesitara)
        if (cantLibros == capacidad) aumentarEspacioLib(libros, stock, cantLibros, capacidad);
        libros[cantLibros - 1] = new char *[3];
        stock[cantLibros - 1] = new int [2];
        almacenarDatosLibros(libros[cantLibros - 1], codigo, descrip, autor);
        almacenarDatosStock(stock[cantLibros - 1], bffStock);
        //acá se podria poner que libros[cantLibros] = nullptr pero el registro creado todo se inicializo ya en 0
        cantLibros++;
    }
}

char *leerCadenaExacta(ifstream &arch, char del) {
    char buff[100], *ptr;
    arch.getline(buff, 100, del);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void aumentarEspacioLib(char ***&libros, int **&stock, int &cantLibros, int &capacidad) {


    capacidad += INCREMENTO;

    if (libros == nullptr) { //si entra por primera vez a libros
        libros = new char **[capacidad] {
        }; //se inicializa en 0 para tener un marcador siempre
        stock = new int *[capacidad] {
        };
        cantLibros = 1; // importante ya que se necesita un marcador despues de la ultima posicion llena
    } else {
        //Creacion del aux
        char ***auxChar;
        int **auxInt;
        auxChar = new char **[capacidad] {
        };
        auxInt = new int*[capacidad] {
        };
        for (int i = 0; libros[i]; i++) {
            auxChar[i] = libros[i];
            auxInt[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = auxChar;
        stock = auxInt;
    }
}

void almacenarDatosLibros(char **reglibro, char *codigo, char *descrip, char *autor) {
    reglibro[0] = codigo;
    reglibro[1] = descrip;
    reglibro[2] = autor;
}

void almacenarDatosStock(int *regStock, int bffStock) {
    regStock[0] = bffStock;
    regStock[1] = 0; //inicializado en 0 la cantidad no atebdida   
}

void pruebaDeLecturaDeLibros(const char *nomArch, char ***libros, int **stock) {
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep, nomArch);
    for (int i = 0; libros[i]; i++) {
        char **auxLib = libros[i];
        int *auxStock = stock[i];
        archRep << left << setw(10) << auxLib[0] << setw(60) << auxLib[1] <<
                setw(50) << auxLib[2] << right << setw(10) << auxStock[0] <<
                setw(10) << auxStock[1] << endl;
    }
}
//Pregunta 2

void atencionDePedidos(const char *nomArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);
    //inicializacion de punteros (para el primer caso)
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    pedidosAtendidos = nullptr;

    //1.Para clientes
    int cantClien = 0, capClien = 0;
    int arrCantCli[400]{}, arrCapCli[400]{};

    //para libros Ped
    int capPedidos = 0;
    int arrCantPedLib[400]{}, arrCapPedLib[400]{};

    int dni, codigoPedido;
    char c;
    //000059,34460612   CRY6839    VYG3594
    //000140,42302422   WPU8819    
    //000167,34460612   PQZ1316    XCC4070
    while (true) {
        arch >> codigoPedido;
        if (arch.eof()) break;
        arch >> c >> dni;
        //1.Para Cliente
        int posCliente = buscarCliente(pedidosClientes, dni); // busca al cliente

        if (posCliente == NO_ENCONTRADO) {//Si no ha encontrado el registro del cliente
            if (cantClien == capClien) //se verifica si aun hay espacios disponibles
                aumentarEspaciosCli(pedidosClientes, cantClien, capClien);

            posCliente = cantClien - 1; //se resta -1 por que esta incluido la ultima posicion
            pedidosClientes[posCliente] = nullptr; //inicializa ya que aun no tiene espacios asiganados
            cantClien++;
        }

        if (arrCantCli[posCliente] == arrCapCli[posCliente])//verifica que el segundo nivel tiene espacios suficientes
            aumentarEspacioRegCli(pedidosClientes[posCliente], arrCantCli[posCliente], arrCapCli[posCliente], dni);
        int posRegCliente = arrCantCli[posCliente] - 1; //ya que se toma en cuenat la posicion vacia

        pedidosClientes[posCliente][posRegCliente] = codigoPedido;
        pedidosClientes[posCliente][1]++; //aumenta la cantidad de pedidos
        arrCantCli[posCliente]++; //aumenta los espacios 

        //2.Para Libros
        if (capPedidos <= codigoPedido + 1)
            aumentarEspaciosPedidos(pedidosAtendidos, pedidosLibros, codigoPedido, capPedidos);
        while (arch.get() != '\n') {
            if (arrCantPedLib[codigoPedido] == arrCapPedLib[codigoPedido])
                aumentarEspacioRegLib(pedidosLibros[codigoPedido], pedidosAtendidos[codigoPedido], arrCantPedLib[codigoPedido], arrCapPedLib[codigoPedido]);
            int posRegLib = arrCantPedLib[codigoPedido] - 1;
            char codigoLib[8];
            arch >> codigoLib;
            pedidosLibros[codigoPedido][posRegLib] = new char [strlen(codigoLib) + 1];
            strcpy(pedidosLibros[codigoPedido][posRegLib], codigoLib);

            int posLib = buscaLibro(libros, codigoLib);
            if (stock[posLib][0] > 0) {
                stock[posLib][0]--;
                pedidosAtendidos[codigoPedido][posRegLib] = true;
            } else {
                stock[posLib][1]++;
                pedidosAtendidos[codigoPedido][posRegLib] = false;
            }
            arrCantPedLib[codigoPedido]++;
        }

    }
}

int buscaLibro(char ***libros, char *codigoLib) {
    for (int i = 0; libros[i]; i++) {
        if (strcmp(libros[i][0], codigoLib) == 0)return i;
    }
    cout << "No encontre el libro" << endl; //solo por si acaso
    return NO_ENCONTRADO;
}

int buscarCliente(int **pedidosClientes, int dni) {
    if (pedidosClientes == nullptr) return NO_ENCONTRADO; //en caso aun no haya nada
    for (int i = 0; pedidosClientes[i]; i++) {
        int *auxPedCli = pedidosClientes[i];
        if (auxPedCli[0] == dni) return i;
    }
    return NO_ENCONTRADO;
}

void aumentarEspaciosCli(int **&pedidosClientes, int &cantClien, int &capClien) {
    capClien += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int *[capClien] {
        };
        cantClien = 1;
    } else {
        int **auxPedCli = new int *[capClien] {
        };
        for (int i = 0; pedidosClientes[i]; i++) {
            auxPedCli[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxPedCli;
    }
}

void aumentarEspacioRegCli(int *&regCliente, int &cant, int &cap, int dni) {
    cap += INCREMENTO;
    if (regCliente == nullptr) {
        regCliente = new int [cap] {
        };
        regCliente[0] = dni;
        regCliente[1] = 0;
        cant = (regCliente[1] + 2) + 1; //la cantidad de espacios asignados mas el vacio
    } else {
        int *auxRegCli = new int [cap] {
        };
        for (int i = 0; regCliente[i]; i++) {
            auxRegCli[i] = regCliente[i];
        }
        delete regCliente;
        regCliente = auxRegCli;
    }
}

void aumentarEspaciosPedidos(bool **&pedidosAtendidos, char ***&pedidosLibros, int codigoPedido, int &capPedidos) {
    int cant = capPedidos; //esto ya que no se llena en orden los numeros de pedido
    capPedidos = (codigoPedido + 1) + INCREMENTO;
    if (pedidosLibros == nullptr) {
        pedidosLibros = new char **[capPedidos] {
        };
        pedidosAtendidos = new bool *[capPedidos] {
        };
    } else {
        char ***auxPedLib = new char **[capPedidos] {
        };
        bool **auxPedAte = new bool *[capPedidos] {
        };
        for (int i = 0; i < cant; i++) {//aca es un erro poner pedidosLibros[i] ya que no todos los anteriores estan llenos 
            auxPedLib[i] = pedidosLibros[i];
            auxPedAte[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxPedLib;
        pedidosAtendidos = auxPedAte;
    }
}

void aumentarEspacioRegLib(char **&regPedLib, bool *&regPedAten, int &cant, int &cap) {
    cap += INCREMENTO;
    if (regPedLib == nullptr) {
        regPedLib = new char *[cap] {
        };
        regPedAten = new bool [cap] {
        };
        cant = 1;
    } else {
        char **auxPedLib = new char *[cap] {
        };
        bool *auxPedAten = new bool [cap] {
        };
        for (int i = 0; regPedLib[i]; i++) {
            auxPedLib[i] = regPedLib[i];
            auxPedAten[i] = regPedAten[i];
        }
        delete regPedLib;
        delete regPedAten;
        regPedLib = auxPedLib;
        regPedAten = auxPedAten;
    }
}


//Pregunta 3

void ordenarPedidoCliente(int **pedidosClientes) {
    int i = 0;
    for (i; pedidosClientes[i]; i++);
    qSort(pedidosClientes, 0, i - 1);
}

void qSort(int **pedidosClientes, int izq, int der) {
    int limite, pos;
    if (izq >= der) return;
    pos = (izq + der) / 2;
    cambiar(pedidosClientes[izq], pedidosClientes[der]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++) {
        if ((pedidosClientes[i][1] > pedidosClientes[izq][1]) or
                (pedidosClientes[i][1] == pedidosClientes[izq][1] and pedidosClientes[i][0] < pedidosClientes[izq][0])) {
            limite++;
            cambiar(pedidosClientes[limite], pedidosClientes[i]);
        }
    }
    cambiar(pedidosClientes[limite], pedidosClientes[izq]);
    qSort(pedidosClientes, izq, limite - 1);
    qSort(pedidosClientes, limite + 1, der);
}

void cambiar(int *&datoI, int *&datoK) {
    int *aux;
    aux = datoI;
    datoI = datoK;
    datoK = aux;
}

//Pregunta 4

void reporteDeEntregaDePedidos(const char *nomArch, int **pedidosClientes, char ***pedidosLibros,
        bool **pedidoAtendidos) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nomArch);
    arch << setw(45) << "REPORTE TOP 5" << endl;
    arch << setw(48) << "ATENCION DE PEDIDOS" << endl;
    imprimirLineas(arch, CANT_FIN, '=');
    for (int i = 0; i < 5; i++) {
        arch << left << "CLIENTES:   " << setw(20) << pedidosClientes[i][0] <<
                "CANTIDAD PEDIDOS:  " << pedidosClientes[i][1] << endl;
        imprimirLineas(arch, CANT_FIN, '=');
        for (int j = 2; pedidosClientes[i][j]; j++) {
            arch << setw(10) << ' ' << setw(15) << "Pedido No." << setw(20) << "Codigo del libro" <<
                    "Observaciones" << endl;
            imprimirLineas(arch, CANT_FIN, '-');
            arch << setw(10) << ' ' << right << setfill('0') << setw(6) << pedidosClientes[i][j] <<
                    setfill(' ') << left << endl;
            int numeroPedido = pedidosClientes[i][j];
            for (int k = 0; pedidosLibros[numeroPedido][k]; k++) {
                arch << setw(31) << ' ' << setw(17) << pedidosLibros[numeroPedido][k];
                if (pedidoAtendidos[numeroPedido][k] == true)arch << "ATENDIDO" << endl;
                else arch << "NO ATENDIDO" << endl;
            }
            imprimirLineas(arch, CANT_FIN, '-');
        }
        imprimirLineas(arch, CANT_FIN, '=');
    }
}

void imprimirLineas(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++)arch << car;
    arch << endl;

}

