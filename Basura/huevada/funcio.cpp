#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "funcio.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1

void atencionDePedidos(const char *nomArch, int **&pedidosClientes) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "error de apertura" << endl;
        exit(1);
    }
    int numPedido, dniPedido, cap = 0, cant = 0;
    int arrCant[600]{}, arrCap[600]{};
    pedidosClientes = nullptr;


    while (true) {
        arch>>numPedido;
        if (arch.eof()) break;
        arch.get();
        arch>>dniPedido;
        while (arch.get() != '\n');
        int flag = 0;
        int posCliente = buscarCliente(pedidosClientes, dniPedido);


        if (posCliente == NO_ENCONTRADO) {
            if (cant == cap) incrementarEspacios(pedidosClientes, cant, cap);
            posCliente = cant - 1;
            pedidosClientes[posCliente] = nullptr;
            flag = 1;
            cant++;
        }
        if (arrCant[posCliente] == arrCap[posCliente]) {
            incrementarEspacios(pedidosClientes[posCliente], arrCant[posCliente], arrCap[posCliente]);
        }

        if (flag == 1) {
            pedidosClientes[posCliente][0] = dniPedido;
            pedidosClientes[posCliente][1] = 1;
            pedidosClientes[posCliente][2] = numPedido;
            arrCant[posCliente] = 4;
        } else {
            pedidosClientes[posCliente][arrCant[posCliente] - 1] = numPedido;
            pedidosClientes[posCliente][1]++;
            arrCant[posCliente]++;
        }
    }
    for (int i = 0; pedidosClientes[i]; i++) {
        for (int j = 0; pedidosClientes[i][j]; j++) {
            cout << pedidosClientes[i][j] << " ";
            if(pedidosClientes[i][j]==107)cout<<"------"<<endl;
        }
         cout << endl;
    }
}

void incrementarEspacios(int **&pedidosClientes, int &cant, int &cap) {
    int **aux;
    cap += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int *[cap] {
        };
        cant = 1;
    } else {
        aux = new int *[cap] {
        };
        for (int i = 0; pedidosClientes[i]; i++)aux[i] = pedidosClientes[i];
        delete[] pedidosClientes;
        pedidosClientes = aux;
    }
}

int buscarCliente(int **pedidosClientes, int dniPedido) {
    for (int i = 0; pedidosClientes != nullptr and pedidosClientes[i]; i++)
        if (pedidosClientes[i][0] == dniPedido) return i;
    return NO_ENCONTRADO;
}

void incrementarEspacios(int *&pedidosClientes, int &cant, int &cap) {
    int *aux;
    cap += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int [cap] {
        };
        cant = 1;
    } else {
        aux = new int [cap] {
        };
        for (int i = 0; pedidosClientes[i]; i++)aux[i] = pedidosClientes[i];
        delete[] pedidosClientes;
        pedidosClientes = aux;
    }

}