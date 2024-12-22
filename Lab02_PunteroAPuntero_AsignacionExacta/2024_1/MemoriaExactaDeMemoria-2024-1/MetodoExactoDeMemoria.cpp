
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "MetodoExactoDeMemoria.h"
#define NO_ENCONTRADO -1
#define LINEAS 69

//Pregunta 1

void lecturaDePedidos(const char *nomArch, char ***& libros, int **&stock) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    int cantLib = 0;
    char **buffLib[500], *codigo, c;
    int *buffStock[500];
    double precio;


    while (true) {
        codigo = leerCadenaExacta(arch, ',');
        if (codigo == nullptr) break;
        buffLib[cantLib] = new char *[3];
        buffLib[cantLib][0] = codigo;
        buffLib[cantLib][1] = leerCadenaExacta(arch, ',');
        buffLib[cantLib][2] = leerCadenaExacta(arch, ',');
        buffStock[cantLib] = new int [2];
        arch >> buffStock[cantLib][0] >> c >> precio;
        buffStock[cantLib][1] = 0;
        arch.get();
        cantLib++;
    }
    buffLib[cantLib] = nullptr;
    buffStock[cantLib] = nullptr;
    cantLib++;
    libros = new char **[cantLib];
    stock = new int *[cantLib];
    for (int i = 0; buffLib[i]; i++) {
        libros[i] = buffLib[i];
        stock[i] = buffStock[i];
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

void pruebaDeLecturaDePedidos(const char *nomArch, char ***libros, int **stock) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << right << setw(60) << "Reporte inicial Libros" << endl;
    arch << left << setw(10) << "Codigo" << setw(60) << "Nombre Libro" << setw(30) << "Autor" <<
            setw(15) << "Stock Inicial" << "Cantidad " << endl;
    for (int i = 0; libros[i]; i++) {
        arch << left << setw(10) << libros[i][0] << setw(60) << libros[i][1] << setw(30) << libros[i][2] <<
                right << setw(7) << stock[i][0] << setw(12) << stock[i][1] << endl;
    }
}


//Pregunta 2 

void atencionDePedidos(const char *nomArch, char ***libros, int **stock, int **&pedidosClientes,
        char ***&pedidosLibros, bool **&pedidosAtendidos) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    int arrCantLibro[300]{};
    int *buffPedidosClientes[300]{}, numPedido, dniPedido, cantCliPed = 0, cantPed = 0;
    char **buffPedidoLib[300]{}, c;
    bool *buffPedAtendidos[300]{};

    while (true) {
        arch >> numPedido;
        if (arch.eof()) break;
        arch >> c >> dniPedido;
        int posPedidoCli = buscarPosCliente(buffPedidosClientes, dniPedido);
        if (posPedidoCli == NO_ENCONTRADO) {
            posPedidoCli = cantCliPed;
            buffPedidosClientes[posPedidoCli] = new int [200] {
            };
            buffPedidosClientes[posPedidoCli][0] = dniPedido;
            buffPedidosClientes[posPedidoCli][1] = 0;
            cantCliPed++;
        }
        int cantidadPedidosCliente = buffPedidosClientes[posPedidoCli][1] + 2;
        buffPedidosClientes[posPedidoCli][cantidadPedidosCliente] = numPedido;
        buffPedidosClientes[posPedidoCli][1]++;


        int cantLibros = 0;

        buffPedidoLib[numPedido - 1] = new char *[200] {
        };
        buffPedAtendidos[numPedido - 1] = new bool [200] {
        };
        while (arch.get() != '\n') {
            buffPedidoLib[numPedido - 1][cantLibros] = new char [7];
            arch >> buffPedidoLib[numPedido - 1][cantLibros];


            int posLibro = buscarLibro(libros, buffPedidoLib[numPedido - 1][cantLibros]);
            if (stock[posLibro][0] > 0) {

                stock[posLibro][0]--;
                buffPedAtendidos[numPedido - 1][cantLibros] = true;
            } else {
                stock[posLibro][1]++;
                buffPedAtendidos[numPedido - 1][cantLibros] = false;
            }
            cantLibros++;
        }
        arrCantLibro[numPedido - 1] = cantLibros;
        cantPed++;
    }


    buffPedidosClientes[cantCliPed] = nullptr;
    buffPedidoLib[cantPed] = nullptr;
    buffPedAtendidos[cantPed] = nullptr;
    cantCliPed++;
    cantPed++;

    cargarArreglos(buffPedAtendidos, buffPedidoLib, buffPedidosClientes, arrCantLibro, cantCliPed,
            cantPed, pedidosClientes, pedidosLibros, pedidosAtendidos);


}

int buscarPosCliente(int **buffPedidosClientes, int dniPedido) {
    for (int i = 0; buffPedidosClientes[i]; i++)
        if (buffPedidosClientes[i][0] == dniPedido) return i;
    return NO_ENCONTRADO;
}

int buscarLibro(char ***libros, char *buffPedidoLib) {
    for (int i = 0; libros[i]; i++)
        if (strcmp(libros[i][0], buffPedidoLib) == 0) return i;


    //    cout<<buffPedidoLib<<endl;
    cout << "No se encontro el libros" << endl;
    return NO_ENCONTRADO;
}

void cargarArreglos(bool **buffPedAtendidos, char ***buffPedidoLib, int **buffPedidosClientes,
        int *arrCantLibro, int cantCliPed, int cantPed, int **&pedidosClientes, char ***&pedidosLibros,
        bool **&pedidosAtendidos) {
    pedidosClientes = new int *[cantCliPed];
    pedidosLibros = new char **[cantPed];
    pedidosAtendidos = new bool *[cantPed];

    for (int i = 0; buffPedidosClientes[i]; i++) {
        pedidosClientes[i] = new int [buffPedidosClientes[i][1] + 2];
        for (int j = 0; j < (buffPedidosClientes[i][1] + 2); j++) {
            pedidosClientes[i][j] = buffPedidosClientes[i][j];
        }
        delete buffPedidosClientes[i];
    }
    pedidosClientes[cantCliPed - 1] = nullptr;



    for (int i = 0; buffPedidoLib[i]; i++) {
        int cantLibros = arrCantLibro[i];
        pedidosLibros[i] = new char *[cantLibros + 1];
        pedidosAtendidos[i] = new bool [cantLibros + 1];
        for (int j = 0; j < cantLibros; j++) {
            pedidosLibros[i][j] = buffPedidoLib[i][j];
            pedidosAtendidos[i][j] = buffPedAtendidos[i][j];
        }
        pedidosLibros[i][cantLibros] = nullptr;
        delete buffPedidoLib[i];
        delete buffPedAtendidos[i];
    }
    pedidosLibros[cantPed - 1] = nullptr;
    pedidosAtendidos[cantPed - 1] = nullptr;

}

//pregunta 3

void reporteDeEntrega(const char *nomArch, int **pedidosClientes, char ***pedidosLibros,
        bool **&pedidosAtendidos) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << right << setw(60) << "Reoirte de atencion de pedidos" << endl;
    imprimirLineas(arch, LINEAS, '=');

    for (int i = 0; pedidosClientes[i]; i++) {
        arch << left << setw(15) << "CLIENTE: " << pedidosClientes[i][0] << endl;
        imprimirLineas(arch, LINEAS, '=');
        for (int j = 2; j < (pedidosClientes[i][1] + 2); j++) {
            arch << left << setw(12) << ' ' << setw(20) << "Pedido No." << setw(20) <<
                    "Codigo del libro" << "Observaciones" << endl;
            imprimirLineas(arch, LINEAS, '-');
            arch << left << setw(14) << ' ' << right << setfill('0') << setw(6) << pedidosClientes[i][j] <<
                    setfill(' ') << left << setw(20) << ' ' << endl;
            int numPedi = pedidosClientes[i][j] - 1;


            for (int k = 0; pedidosLibros[numPedi][k]; k++) {
                arch << left << setw(35) << ' ' << setw(23) << pedidosLibros[numPedi][k];
                if (pedidosAtendidos[numPedi][k] == true) {
                    arch << "ATENDIDO" << endl;
                } else arch << "NO ATENDIDO" << endl;

            }
            imprimirLineas(arch, LINEAS, '-');
        }
        imprimirLineas(arch, LINEAS, '=');
    }
}

void imprimirLineas(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++)arch << car;
    arch << endl;
}

