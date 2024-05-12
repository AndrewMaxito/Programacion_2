#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5
#define CANT_MAX 151
#define CANT_FIN 72

void lecturaDeLibros(const char *nomArch, char ***&libros, int **&stock) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);
    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    libros = nullptr;
    stock = nullptr;

    int cantLibros = 0, capacidad = 0;
    char *codigo, *descrip, *autor, c;
    int buffStock;
    double precio;

    while (true) {
        codigo = leerCadenaExacta(arch, ',');
        if (codigo == nullptr) break;
        descrip = leerCadenaExacta(arch, ',');
        autor = leerCadenaExacta(arch, ',');
        arch >> buffStock >> c >> precio;
        arch.get(); //salto de linea final

        if (cantLibros == capacidad) aumentarEspacioLibros(libros, stock, cantLibros, capacidad);
        libros[cantLibros - 1] = new char *[3];
        stock[cantLibros - 1] = new int [2];
        libros[cantLibros - 1][0] = codigo;
        libros[cantLibros - 1][1] = descrip;
        libros[cantLibros - 1][2] = autor;
        stock[cantLibros - 1][0] = buffStock;
        stock[cantLibros - 1][1] = 0;
        cantLibros++;
    }
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[200], *ptr;
    arch.getline(buff, 200, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void aumentarEspacioLibros(char ***&libros, int **&stock, int &cantLibros, int &capacidad) {
    char ***auxChar;
    int **auxInt;
    capacidad += INCREMENTO;

    if (libros == nullptr) {
        libros = new char **[capacidad] {
        }; // inicializados en 0
        stock = new int *[capacidad] {
        };
        cantLibros = 1;
    } else {
        auxChar = new char **[capacidad] {
        };
        auxInt = new int *[capacidad] {
        };
        for (int i = 0; libros[i]; i++) {
            auxChar[i] = libros[i];
            auxInt[i] = stock[i];
        }
        delete[] libros;
        delete[] stock;
        libros = auxChar;
        stock = auxInt;
    }
}

void pruebaDeLecturaDeLibros(const char *nomArch, char ***libros, int **stock) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nomArch);
    arch << setw(60) << "Reporte De Libros " << endl;
    arch << left << setw(10) << "Codigo" << setw(70) << "Nombre del Libro" << setw(35) << "Autor" <<
            setw(12) << "Stock" << "Cantidad no atendida" << endl;
    imprimirLineas(arch, CANT_MAX, '=');

    for (int i = 0; libros[i]; i++) {
        arch << left << setw(10) << libros[i][0] << setw(70) << libros[i][1] << setw(30) <<
                libros[i][2] << right << setw(7) << stock[i][0] << setw(20) << stock[i][1] << endl;
    }
}

void imprimirLineas(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++)arch << car;
    arch << endl;

}

//Pregunta 2
void atencionDePedidos(const char *nomArch, char ***libros, int **stock, int **&pedidosClientes,
        char ***&pedidosLibros, bool **&pedidoAtendidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);
    
    //000059,34460612   CRY6839    VYG3594
    int numPedido, dniCliente, capacidadPedi = 0, cantClientes = 0, capClientes = 0, buffCap[200]{}, buffCant[200]{};
    char codigoLibro[7], *ptrCodigo;
    int arrCantCli[600]{}, arrCapCli[600]{};
    //inicializacion del los punteros
    pedidosClientes = nullptr;
    pedidoAtendidos = nullptr;
    pedidosLibros = nullptr;

    while (true) {
        arch >> numPedido;
        if (arch.eof()) break;
        arch.get(); // se lee la coma 
        arch >> dniCliente;
        if (capacidadPedi <= numPedido)
            incrementarEspaciosPedidos(pedidosLibros, pedidoAtendidos, capacidadPedi, numPedido);
        //Para libros y pedidos atendidos
        while (arch.get() != '\n') {

            arch >> codigoLibro;
            if (buffCap[numPedido] == buffCant[numPedido])
                incrementarEspacioLibrosPedidos(pedidosLibros[numPedido],
                    pedidoAtendidos[numPedido], buffCap[numPedido], buffCant[numPedido]);
            
            ptrCodigo = new char [strlen(codigoLibro) + 1];
            strcpy(ptrCodigo, codigoLibro);
            int cantidadLibros = buffCant[numPedido];
            pedidosLibros[numPedido][cantidadLibros - 1] = ptrCodigo;
            int posLibro = buscarPosLibro(libros, codigoLibro);
            if (stock[posLibro][0] > 0) {
                stock[posLibro][0]--;
                pedidoAtendidos[numPedido][cantidadLibros - 1] = true;
            } else {
                pedidoAtendidos[numPedido][cantidadLibros - 1] = false;
                stock[posLibro][1]++;
            }
            buffCant[numPedido]++;
        }
        ptrCodigo = new char [8];
        strcpy(ptrCodigo, "XXXXXX");
        if (buffCant[numPedido] == 0) {
            pedidosLibros[numPedido] = new char *[1];
            pedidosLibros[numPedido][0] = ptrCodigo;
        } else  pedidosLibros[numPedido][buffCant[numPedido] - 1] = ptrCodigo;
           
        //para clientes
        int flag = 0;
        int posCliente = buscarCliente(pedidosClientes, dniCliente);
        if (posCliente == -1) {
            if (cantClientes == capClientes)
                incrementarEspacioClientes(pedidosClientes, capClientes, cantClientes);
            posCliente = cantClientes - 1;
            pedidosClientes[posCliente] = nullptr;
            flag = 1;
            cantClientes++;
        }
        if (arrCantCli[posCliente] == arrCapCli[posCliente])
            incrementarEspacios(pedidosClientes[posCliente], arrCantCli[posCliente], arrCapCli[posCliente]);
        if (flag == 1) {
            pedidosClientes[posCliente][0] = dniCliente;
            pedidosClientes[posCliente][1] = 1;
            pedidosClientes[posCliente][2] = numPedido;
            arrCantCli[posCliente] = 4; //estamos una pos adelantado p
        } else {
            pedidosClientes[posCliente][arrCantCli[posCliente] - 1] = numPedido;
            pedidosClientes[posCliente][1]++;
            arrCantCli[posCliente]++;
        }
    }
}

void incrementarEspaciosPedidos(char ***&pedidosLibros, bool **&pedidoAtendidos, int &capacidadPedi,
        int numPedido) {
    char ***auxChar;
    bool **auxBool;
    int capacidadAnterior = capacidadPedi;
    capacidadPedi = numPedido + INCREMENTO;

    if (pedidosLibros == nullptr) {
        pedidosLibros = new char **[capacidadPedi + 1] {
        };
        pedidoAtendidos = new bool *[capacidadPedi + 1] {
        };

    } else {
        auxChar = new char **[capacidadPedi + 1] {
        };
        auxBool = new bool *[capacidadPedi + 1] {
        };
        for (int i = 0; i < capacidadAnterior; i++) { //el dato pedidosLibros[0] esta vacio por condiciones del problema
            auxChar[i] = pedidosLibros[i];
            auxBool[i] = pedidoAtendidos[i];
        }
        delete[] pedidosLibros;
        delete[] pedidoAtendidos;
        pedidosLibros = auxChar;
        pedidoAtendidos = auxBool;
    }

}

void incrementarEspacioLibrosPedidos(char **&pedidosLibros, bool *&pedidoAtendidos,
        int &buffCap, int &buffCant) {

    buffCap += INCREMENTO;
    char **auxChar;
    bool *auxBool;
    if (pedidosLibros == nullptr) {
        pedidosLibros = new char *[buffCap] {
        };
        pedidoAtendidos = new bool [buffCap] {
        };
        buffCant = 1;
    } else {
        auxChar = new char *[buffCap] {
        };
        auxBool = new bool [buffCap] {
        };
        for (int i = 0; pedidosLibros[i]; i++) {
            pedidosLibros[i] = auxChar[i];
            pedidoAtendidos[i] = auxBool[i];
        }
        delete [] pedidosLibros;
        delete []pedidoAtendidos;
        pedidosLibros = auxChar;
        pedidoAtendidos = auxBool;
    }
}

int buscarPosLibro(char ***libros, char *codigoLibro) {
    for (int i = 0; libros[i]; i++)
        if (strcmp(codigoLibro, libros[i][0]) == 0) return i;
    cout << "No se encontro el libro" << endl;
    return -1;
}

void incrementarEspacioClientes(int **&pedidosClientes, int &capClientes, int &cantClientes) {
    capClientes += INCREMENTO;
    int **aux;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int *[capClientes] {
        };
        cantClientes = 1;
    } else {
        aux = new int *[capClientes] {
        };
        for (int i = 0; pedidosClientes[i]; i++) aux[i] = pedidosClientes[i];
        delete[] pedidosClientes;
        pedidosClientes = aux;
    }
}

int buscarCliente(int **pedidosClientes, int dniCliente) {
    for (int i = 0; pedidosClientes != nullptr and pedidosClientes[i]; i++)
        if (pedidosClientes[i][0] == dniCliente) return i;
    return -1;
}

void incrementarEspacios(int *&pedidosClientes, int &arrCantCli, int &arrCapCli) {
    int *aux;
    arrCapCli += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int [arrCapCli] {
        };
        arrCantCli = 1;
    } else {
        aux = new int [arrCapCli] {
        };
        for (int i = 0; pedidosClientes[i]; i++) aux[i] = pedidosClientes[i];
        delete[]pedidosClientes;
        pedidosClientes = aux;
    }
}


//Pregunta 3 

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
            for (int k = 0; strcmp(pedidosLibros[numeroPedido][k], "XXXXXX") != 0; k++) {
                arch << setw(31) << ' ' << setw(17) << pedidosLibros[numeroPedido][k];
                if (pedidoAtendidos[numeroPedido][k] == true)arch << "ATENDIDO" << endl;
                else arch << "NO ATENDIDO" << endl;
            }
            imprimirLineas(arch, CANT_FIN, '-');
        }
        imprimirLineas(arch, CANT_FIN, '=');
    }
}

