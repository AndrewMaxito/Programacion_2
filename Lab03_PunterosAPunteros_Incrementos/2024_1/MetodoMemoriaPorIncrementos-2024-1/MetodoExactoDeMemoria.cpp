

/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: andre
 * 
 * Created on 19 de setiembre de 2024, 14:37
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#define INCREMENTO 5
#define NO_ENCONTRADO -1
#define CANT_FIN 72

using namespace std;
#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"

void lecturaDePedidos(const char* nomArch, char ***&libros, int **&stock) {

    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);

    //inicializacion de los punteros en nullptr  
    libros = nullptr;
    stock = nullptr;
    //inicializar la cant y la  capacidad
    int cantLibros = 0, capLibros = 0;

    int datStock;
    char *codigoLib, *nomLibro, *autor, c;
    double precio;

    while (true) {
        codigoLib = leerCadenaExacta(arch, ',');
        if (codigoLib == nullptr) break;
        nomLibro = leerCadenaExacta(arch, ',');
        autor = leerCadenaExacta(arch, ',');
        arch >> datStock >> c >>precio;
        arch.get(); // salto de linea
        //vericar hay espacios disponibles
        if (capLibros == cantLibros)
            incrementarEspaciosLibros(libros, stock, cantLibros, capLibros);
        libros[cantLibros - 1] = new char *[3] {
            codigoLib, nomLibro, autor};
        stock[cantLibros - 1] = new int [2] {
            datStock
        }; //para la cantidad no atendida 
        cantLibros++;
    }
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void incrementarEspaciosLibros(char ***&libros, int **& stock, int &cantLibros,
        int &capLibros) {
    capLibros += INCREMENTO;
    if (libros == nullptr) {
        libros = new char **[capLibros] {
        }; //todos inicializados en 0 (es mas practico)
        stock = new int *[capLibros] {
        }; //no es necesario ya que libros es el principal
        cantLibros = 1; //se cuenta el delimitador
    } else {
        char ***auxLibros = new char **[capLibros] {
        };
        int **auxStock = new int *[capLibros] {
        };
        for (int i = 0; libros[i]; i++) { //la condicion funciona aqui ya que ingresa en orden
            auxLibros[i] = libros[i];
            auxStock[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = auxLibros;
        stock = auxStock;
    }
}

void pruebaDeLecturaDeLecturaDeLibros(const char *nomArch, char ***libros, int **stock) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nomArch);
    arch << left << setw(10) << "Codigo" << setw(60) << "Nombre" <<
            setw(45) << "Autor" << setw(10) << "Stock" << setw(10) <<
            "Cant no vendida" << endl << endl;
    for (int i = 0; libros[i]; i++) {
        char **regLib = libros[i];
        int *regStock = stock[i];
        arch << left << setw(10) << regLib[0] << setw(60) << regLib[1] <<
                setw(40) << regLib[2] << right << setw(10) << regStock[0] <<
                setw(10) << regStock[1] << endl;
    }
}

//Pregunta 2

void atencionDePedidos(const char *nomArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);
    //inicializacion de punteros
    pedidosLibros = nullptr;
    pedidosClientes = nullptr;
    pedidosAtendidos = nullptr;

    int cantClientes = 0, capClientes = 0;
    int arrCantPedCli[200]{}, arrCapPedClie[200]{};
    int arrCantLibPed[200]{}, arrCapLibPed[200]{};

    int capPedidos = 0;
    int numeroPed, dniCliente;
    char c, codigoLib[8];
    while (true) {
        arch >> numeroPed;
        if (arch.eof()) break;
        arch >> c >> dniCliente;
        //1.Cargar Clientes y su registro 
        int posCLiente = buscarPosCliente(pedidosClientes, dniCliente);
        if (posCLiente == NO_ENCONTRADO) {//nuevo cliente en el registro
            //verifica que haya sufisiente espacio para cada cliente
            if (cantClientes == capClientes)
                incremnetarEspaciosCli(pedidosClientes, cantClientes, capClientes);
            posCLiente = cantClientes - 1; // para el cliente "vacio"
//            pedidosClientes[posCLiente] = nullptr; (Esto no es necesario ya que ya se inicializo todo )
            //si es nuevo cliente no tiene ningun espacio por ello se crea:
            incrementarEspaciosRegClientes(pedidosClientes[posCLiente], arrCantPedCli[posCLiente], arrCapPedClie[posCLiente]);
            int *auxPedCli = pedidosClientes[posCLiente];
            auxPedCli[0] = dniCliente;
            auxPedCli[1] = 0; // 0 pedidos
            arrCantPedCli[posCLiente] = 3; //2 llenos mas el vacio
            cantClientes++;
        }
        //verificar la cantidad de espacios del reg de UN cliente
        if (arrCantPedCli[posCLiente] == arrCapPedClie[posCLiente])
            incrementarEspaciosRegClientes(pedidosClientes[posCLiente], arrCantPedCli[posCLiente], arrCapPedClie[posCLiente]);
        int cantEspaEnCli = arrCantPedCli[posCLiente] - 1;
        int *auxCliente = pedidosClientes[posCLiente];
        auxCliente[cantEspaEnCli] = numeroPed;
        auxCliente[1]++;
        arrCantPedCli[posCLiente]++;


        //2.Cargar los pedidos de libros/atencion y suregistro de cada uno
        if (numeroPed + 1 >= capPedidos)
            incrementarEspaciosPedLib(pedidosLibros, pedidosAtendidos, numeroPed + 1, capPedidos); //numeroPed +1 -> ya que esa es la cantidad de espacios que tengo
        int posPedido = numeroPed; //segun lo pide el problema
        while (arch.get() != '\n') {
            arch >> codigoLib;
            //verificar si hay espacios suficinetes para los libros en UN pedido
            if (arrCantLibPed[posPedido] == arrCapLibPed[posPedido])
                incremnetarEspaciosRegLibPed(pedidosLibros[posPedido], pedidosAtendidos[posPedido], arrCantLibPed[posPedido], arrCapLibPed[posPedido]);
            int posLibPed = arrCantLibPed[posPedido] - 1;
            char **auxLibPed = pedidosLibros[posPedido];
            bool *auxAte = pedidosAtendidos[posPedido];
            auxLibPed[posLibPed] = new char [strlen(codigoLib) + 1];
            strcpy(auxLibPed[posLibPed], codigoLib);
            int posLibroBas = buscarLibro(libros, codigoLib);
            int *auxStock = stock[posLibroBas];
            if (auxStock[0] > 0) {
                auxStock[0]--;
                auxAte[posLibPed] = true;
            } else {
                auxStock[1]++;
                auxAte[posLibPed] = false;
            }
            arrCantLibPed[posPedido]++;
        }
    }
}

void incremnetarEspaciosCli(int **&pedidosClientes, int &cantClientes, int &capClientes) {
    capClientes += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int *[capClientes] {
        }; //inicializados todos en nullptr
        cantClientes = 1;
    } else {
        int **auxPedClie = new int *[capClientes] {
        };
        for (int i = 0; pedidosClientes[i]; i++) {//si se ingresa en orden (por eso la condicion es valida)
            auxPedClie[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxPedClie;
    }
}

int buscarPosCliente(int **pedidosClientes, int dniCliente) {
    if (pedidosClientes == nullptr)return NO_ENCONTRADO;
    for (int i = 0; pedidosClientes[i]; i++) {
        int *auxPedCli = pedidosClientes[i];
        if (auxPedCli[0] == dniCliente) return i;
    }
    return NO_ENCONTRADO;
}

void incrementarEspaciosRegClientes(int *&pedidosClientes, int &cant, int &cap) {
    cap += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int [cap] {
        }; //todos en 0 
        cant = 1;
    } else {
        int *auxPedCliente = new int [cap] {
        };
        for (int i = 0; pedidosClientes[i]; i++) { //entra en orden
            auxPedCliente[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxPedCliente;
    }
}

void incrementarEspaciosPedLib(char ***&pedidosLibros, bool **&pedidosAtendidos, int cant, int &cap) {
    int capAnterior = cap;
    cap += (cant + INCREMENTO);
    if (pedidosLibros == nullptr) {
        pedidosLibros = new char **[cap] {
        }; //No es necesario inicializarlo aqui
        pedidosAtendidos = new bool *[cap] {
        };
    } else {
        char ***auxPedLib = new char **[cap] {
        };
        bool **auxPedAte = new bool *[cap] {
        };
        for (int i = 0; i < capAnterior; i++) { //como no se almacena en orden por lo menos tendria cant-1 
            auxPedLib[i] = pedidosLibros[i];
            auxPedAte[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        pedidosLibros = auxPedLib;
        pedidosAtendidos = auxPedAte;
    }
}

void incremnetarEspaciosRegLibPed(char **&librosPedidos, bool *&atePedido, int &cant, int &cap) {
    cap += INCREMENTO;
    if (librosPedidos == nullptr) {
        librosPedidos = new char *[cap] {
        }; //si es necesario
        atePedido = new bool [cap] {
        };
        cant = 1;
    } else {
        char **auxLibPed = new char *[cap] {
        };
        bool *auxAtePed = new bool [cap] {
        };
        for (int i = 0; librosPedidos[i]; i++) {//si entra en orden
            auxLibPed[i] = librosPedidos[i];
            auxAtePed[i] = atePedido[i];
        }
        delete librosPedidos;
        librosPedidos = auxLibPed;
        atePedido = auxAtePed;
    }
}

int buscarLibro(char ***libros, char *codigoLib) {
    for (int i = 0; libros[i]; i++) {
        char **auxLib = libros[i];
        if (strcmp(auxLib[0], codigoLib) == 0) return i;
    }
    cout << "no se encontro el libro " << endl; //solo por si acaso en teoria si deberia encontarar el libro
    return NO_ENCONTRADO;
}

void ordenarPedidosClientes(int **pedidosClientes) {
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

void reporteDeEntregaDePedidos(const char *nomArch, int **pedidosClientes, char ***pedidosLibros,
        bool **pedidoAtendidos) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nomArch);
    arch << setw(45) << "REPORTE TOP 5" << endl;
    arch << setw(48) << "ATENCION DE PEDIDOS" << endl;
    imprimirLineas(arch, CANT_FIN, '=');
    for (int i = 0; i < 5; i++) {
        int *auxPedCliente = pedidosClientes[i];
        
        arch << left << "CLIENTES:   " << setw(20) << auxPedCliente[0] <<
                "CANTIDAD PEDIDOS:  " << auxPedCliente[1] << endl;
        imprimirLineas(arch, CANT_FIN, '=');

        for (int j = 2; auxPedCliente[j]; j++) {
            arch << setw(10) << ' ' << setw(15) << "Pedido No." << setw(20) << "Codigo del libro" <<
                    "Observaciones" << endl;
            imprimirLineas(arch, CANT_FIN, '-');
            arch << setw(10) << ' ' << right << setfill('0') << setw(6) << auxPedCliente[j] <<
                    setfill(' ') << left << endl;

            int numeroPedido = auxPedCliente[j];
            char **auxPedLib=pedidosLibros[numeroPedido];
            bool *auxPedAte=pedidoAtendidos[numeroPedido];
            for (int k = 0; auxPedLib[k]; k++) {
                arch << setw(31) << ' ' << setw(17) << auxPedLib[k];
                if (auxPedAte[k] == true)arch << "ATENDIDO" << endl;
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

