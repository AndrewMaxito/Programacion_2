
/* 
 * File:   punterosgenericos.cpp
 * Author: 51969
 * 
 * Created on 30 de setiembre de 2024, 16:34
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "punterosgenericos.h"
#define AUMENTO 5
#define CANT_LIN 90

char* leercadenaexacta(ifstream &arch, int lim, char c) {
    char buffer[100], *ptr;
    arch.getline(buffer, lim, c);
    if (arch.eof())return nullptr;
    ptr = new char[strlen(buffer) + 1];
    strcpy(ptr, buffer);
    return ptr;
}

char* leercadenaexacta(ifstream &arch, char c) {
    char buffer[100], *ptr;
    arch.getline(buffer, 100, c);
    if (arch.eof())return nullptr;
    ptr = new char[strlen(buffer) + 1];
    strcpy(ptr, buffer);
    return ptr;
}

void* leerreg(ifstream &arch) {
    char* cod = leercadenaexacta(arch, ',');
    if (cod == nullptr)return nullptr;
    char* nombre = leercadenaexacta(arch, ',');
    double *precio = new double;
    char c, buffer[20], *tipo;
    int *cantPlatSoli = new int (0);
    arch>>*precio >> c>>buffer;
    arch.get(); //salto de linea
    tipo = new char[strlen(buffer) + 1];
    strcpy(tipo, buffer);
    void **datos = new void*[5] {
    };
    datos[0] = cod;
    datos[1] = nombre;
    datos[2] = precio;
    datos[3] = tipo;
    datos[4] = cantPlatSoli;
    return datos;
}

void leerplatos(void* &pla) {
    void *buffplatos[150], *reg;
    //    void** buffplatos=new void*[120]{}, *reg;
    int cantplatos = 0;
    ifstream arch("platos.csv", ios::in);
    if (not arch.is_open())exit(1);

    while (true) {
        reg = leerreg(arch);
        if (reg == nullptr)break;
        buffplatos[cantplatos] = reg;
        cantplatos++;
    }
    void **platos = new void*[cantplatos + 1] {
    };
    for (int i = 0; i < cantplatos; i++)platos[i] = buffplatos[i];
    pla = platos;
}

void imprimirplatos(void* &pla) {
    void**platos = (void**) pla;
    ofstream arch("borradorplatos.txt", ios::out);
    if (not arch.is_open())exit(1);
    for (int i = 0; platos[i]; i++) {
        void** plato = (void**) platos[i];
        char *cod = (char*) plato[0];
        char *nombre = (char*) plato[1];
        double *precio = (double*) plato[2];
        char *tipo = (char*) plato[3];
        int *cantPlatPedi = (int *) plato[4];
        arch << cod << " " << nombre << " " << *precio << " " << tipo << " " << *cantPlatPedi << endl;
    }

}

void* leerrepartidor(ifstream &arch) {
    char buffer[20];

    char *cod = leercadenaexacta(arch, ',');
    if (cod == nullptr)return nullptr;
    char *nombre = leercadenaexacta(arch, ',');
    arch>>buffer;
    arch.get(); //salto de linea
    char *vehiculo = new char[strlen(buffer) + 1];
    strcpy(vehiculo, buffer);
    int *cantCli = new int(0);
    void **datos = new void*[5];
    datos[0] = cod;
    datos[1] = nombre;
    datos[2] = vehiculo;
    datos[3] = nullptr;
    datos[4] = cantCli;

    return datos;
}

void leerrepartidores(void* &rep) {
    void *reg, *buffrepartidores[100];
    ifstream arch("repartidores.csv", ios::in);
    if (not arch.is_open())exit(1);
    int cantrepartidores = 0;

    while (true) {
        reg = leerrepartidor(arch);
        if (reg == nullptr)break;
        buffrepartidores[cantrepartidores] = reg;
        cantrepartidores++;
    }
    void** repartidores = new void*[cantrepartidores + 1] {
    };
    for (int i = 0; i < cantrepartidores; i++)repartidores[i] = buffrepartidores[i];
    rep = repartidores;
}

void imprimirrepartidores(void*rep) {
    void**repartidores = (void**) rep;
    ofstream arch("borradorrepartidores.txt", ios::out);
    if (not arch.is_open())exit(1);
    for (int i = 0; repartidores[i]; i++) {
        void **repartidor = (void**) repartidores[i];
        char *cod = (char*) repartidor[0];
        char* nombre = (char*) repartidor[1];
        char* vehiculo = (char*) repartidor[2];
        arch << cod << " " << nombre << " " << vehiculo << endl;
    }
}

int buscarrep(void**repartidores, char *codrep) {
    void**repartidor;
    for (int i = 0; repartidores[i]; i++) {
        repartidor = (void**) repartidores[i];
        char* cod = (char*) repartidor[0];
        if (strcmp(codrep, cod) == 0)return i;
    }

    cout << "No se encontro el codigo del repartidor" << codrep << endl;
    exit(1);
    return -1;

}

int buscardni(void*clientes, int dni) {
    void **regCliente = (void **) clientes;
    for (int i = 0; regCliente[i]; i++) {
        void**datosCleinte = (void**) regCliente[i];
        int* cod = (int*) datosCleinte[0];
        if (*cod == dni)return i;
    }
    return -1;
}

void aumentarplatos(void** &cliente, int &cap, int &cant, int dni) {
    int *cero = new int, *ptrdni = new int, *ptrcap = new int;







}

int buscarplato(void* pla, char* codplato) {
    void**platos = (void**) pla;
    for (int i = 0; platos[i]; i++) {
        void**plato = (void**) platos[i];
        char *cod = (char*) plato[0];
        if (strcmp(codplato, cod) == 0)return i;
    }

    cout << "No se encontro el plato " << codplato << endl;
    exit(1);
    return -1;

}

void asignarplato(void**&cliente, void* &platos, char* codplato, int cant, int cantplatos, int capplatos, int dni) {








}

void aumentarclientes(void** &clientes, int &cap, int &cant) {




}

void asignarrep(void** &repartidores, void* & platos, int dni, int *caprep,
        int *cantrep, char* buffrep, int cant, char* buffplato, int *arrCapPlatXCli) {







}

void cargarpedidos(void* &rep, void* &platos) {
    int cantrep[69]{}, caprep[69]{};
    void**repartidores = (void**) rep;
    char buffrep[10], buffplato[10];
    ifstream arch("pedidos.txt", ios::in);
    if (not arch.is_open())exit(1);
    int dni, cant;
    void *bufferClien[200]{};
    //12484697 AD-546 2 LAF361
    while (true) {
        arch>>dni;

        if (arch.eof())break;
        arch >> buffplato >> cant>>buffrep;
        int posrep = buscarrep(repartidores, buffrep);
        void **datosRepa = (void **) (repartidores[posrep]);
        int *cantClientes = (int *) (datosRepa[4]);
        if (*cantClientes == 0) {
            bufferClien[posrep] = new void*[100] {
            };
        }
        void **regCliente = (void **) (bufferClien[posrep]);
        int posCliente = buscardni(bufferClien[posrep], dni);
        if (posCliente == -1) {
            posCliente = (*cantClientes);

            regCliente[posCliente] = new void*[100] {
            };
            void **datosCliente = (void **) (regCliente[posCliente]);
            int *dniCli = new int(dni);
            int *cantPla = new int(0);
            datosCliente[0] = dniCli;
            datosCliente[1] = cantPla;
            (*cantClientes)++;
        }
        void **datosClientePI = (void **) (regCliente[posCliente]);
        int *cantPlatosXcli = (int *) (datosClientePI[1]);
        int espacioLibrePla = (*cantPlatosXcli) + 2;
        int *cantDelPlato = new int (cant);
        int posPlato = buscarplato(platos, buffplato);
        void** regPlatos = (void **) platos;
        datosClientePI[espacioLibrePla] = new void*[2] {
            regPlatos[posPlato], cantDelPlato
        };
        (*cantPlatosXcli)++;

    }


    for (int i = 0; repartidores[i]; i++) {
        void **datosRepa = (void **) (repartidores[i]);
        int *cantClientes = (int *) (datosRepa[4]);
        datosRepa[3] = new void*[*cantClientes] {
        };
        void **clientesAten = (void **) (datosRepa[3]); //es impornate entar en este orden 
        void **buffRegClie = (void **) bufferClien[i];
        for (int j = 0; j < (*cantClientes); j++) {
            void **buffDatosCli = (void **) (buffRegClie[j]);
            int *bufDni = (int *) (buffDatosCli[0]);
            int *cantPlatos = (int *) (buffDatosCli[1]);
            clientesAten[j] = new void* [*cantPlatos + 2];
            void** datosClienteAten = (void **) (clientesAten[j]);
            int *dniCliAt = new int (*bufDni);
            int *cantPlatosAten = new int (*cantPlatos);
            datosClienteAten[0] = dniCliAt;
            datosClienteAten[1] = cantPlatosAten;
            for (int k = 0; k < (*cantPlatosAten); k++) {
                datosClienteAten[2 + k] = buffDatosCli[2 + k];
            }
        }
    }
}

void imprimirborradorpedidos(void*rep) {
    ofstream arch("borradorpedido.txt", ios::out);
    if (not arch.is_open())exit(1);
    void**repartidores = (void**) rep;
    arch << right << setw(60) << "Reporte de Entrega de pedidos por repartidor" << endl;
    imprimirLineas(arch, CANT_LIN, '=');
    for (int i = 0; repartidores[i]; i++) {
        void**repartidor = (void**) repartidores[i];
        char* codrep = (char*) repartidor[0];
        char* nombreRep = (char*) repartidor[1];
        int* cantCliAten = (int *) repartidor[4];
        arch << left << "Codigo del repartidor:  " << setw(10) << codrep <<
                setw(70) << nombreRep << endl;
        arch << "Clientes Atendidos:  " << *cantCliAten << endl;
        imprimirLineas(arch, CANT_LIN, '-');
        void**clientes = (void**) repartidor[3];
        for (int j = 0; j < (*cantCliAten); j++) {
            void**cliente = (void**) (clientes[j]);
            int* dni = (int*) cliente[0];
            int* cantPed = (int *) cliente[1];
            arch << right << setfill('0') << setw(2) << j + 1 << ')' <<
                    setfill(' ') << left << setw(2) << ' ' << setw(5) << "DNI: " << *dni << endl;
            for (int k = 0; k < (*cantPed); k++) {
                void **plato = (void **) (cliente[2 + k]);
                void **datosPlato = (void **) (plato[0]);
                int *cantDelPlato = (int *) (plato[1]);
                char* codigoPlato = (char*) (datosPlato[0]);
                char* nombrePlato = (char*) (datosPlato[1]);
                arch << setw(10) << ' ' << *cantDelPlato << " plato(s) de  " << 
                        nombrePlato << " Codigo: " << codigoPlato << endl;
            }
            arch << endl;
            imprimirLineas(arch, CANT_LIN, '-');
        }
        imprimirLineas(arch, CANT_LIN, '=');
    }
}

void imprimirLineas(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++) {
        arch << car;
    }
    arch << endl;
}
