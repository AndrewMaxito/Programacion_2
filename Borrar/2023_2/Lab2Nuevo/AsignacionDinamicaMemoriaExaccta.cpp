
/* 
 * File:   AsignacionDinamicaMemoriaExaccta.cpp
 * Author: andre
 * 
 * Created on 11 de septiembre de 2024, 05:56 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define NO_ENCONTRADO -1
#include "AsignacionDinamicaMemoriaExaccta.h"

void lecturaDeProductos(const char *nomArch, char ***&productos, int *&stock,
        double *&precios) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    char **buffProductos[300];
    int buffStock[300];
    double buffPrecios[300];
    //BIT-434,Campana Extractora modelo Glass,375.09,10
    //SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,23
    char *ptr, c;
    int cantProd = 0;
    while (true) {
        ptr = leerCadenaExacta(arch, ',');
        if (ptr == nullptr) break;
        buffProductos[cantProd] = new char *[2];
        char **auxBuffProd = buffProductos[cantProd];
        auxBuffProd[0] = ptr;
        auxBuffProd[1] = leerCadenaExacta(arch, ',');
        arch >> buffPrecios[cantProd] >> c >> buffStock[cantProd];
        arch.get(); //salto de linea
        cantProd++;
    }
    buffProductos[cantProd] = 0;
    buffStock[cantProd] = 0;
    buffPrecios[cantProd] = 0;
    cantProd++;

    productos = new char **[cantProd];
    stock = new int [cantProd];
    precios = new double [cantProd];

    for (int i = 0; buffProductos[i]; i++) {
        productos[i] = buffProductos[i];
        stock[i] = buffStock[i];
        precios[i] = buffPrecios[i];
    }
    productos[cantProd - 1] = nullptr;
    stock[cantProd - 1] = 0;
    precios[cantProd - 1] = 0;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void pruebaDeLecturaDeProductos(const char *nomARch, char ***productos, int *stock,
        double *precios) {
    ofstream archRe(nomARch, ios::out);
    if (!archRe.is_open()) {
        cout << "No se pudo abrir el archivo: " << nomARch << endl;
        exit(1);
    }
    for (int i = 0; productos[i] != nullptr; i++) {
        char **auxProd = productos[i];
        archRe << left << setw(15) << auxProd[0] << setw(60) << auxProd[1] <<
                right << setw(10) << stock[i] << setw(20) << precios[i] << endl;
    }
}

void lecturaDePedidos(const char *nomArch, int *&fechaPedidos, char ***&codigoPedidos,
        int ***&dniCanPedidos) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abriri el archivo " << nomArch << endl;
        exit(1);
    }
    //JXD-139,50375303,6,24/08/2023
    //CRU-009,50375303,5,3/09/2023
    int buffFechPedidos[300], **buffDniCantPedidos[300];
    char **buffCodigoPedidos[300];

    int dd, mm, aa, fecha;
    int dniPedidos, cantPed;
    char codigo[8], c;
    int cantFechas = 0, arrcantLibrosXfecha[300]{};
    while (true) {
        arch.getline(codigo, 8, ',');
        if (arch.eof())break;
        arch >> dniPedidos >> c >> cantPed >> c >> dd >> c >> mm >> c>>aa;
        arch.get(); //salto de linea
        fecha = aa * 10000 + mm * 100 + dd;
        int posFecha = buscarFecha(fecha, buffFechPedidos);
        if (posFecha != NO_ENCONTRADO) {
            agregarDatosPedidos(buffCodigoPedidos[posFecha], codigo,
                    buffDniCantPedidos[posFecha], dniPedidos, cantPed);
        } else {
            posFecha = cantFechas;
            buffFechPedidos[posFecha] = fecha;
            buffCodigoPedidos[posFecha] = new char *[300] {
            };
            buffDniCantPedidos[posFecha] = new int *[300] {
            };
            agregarDatosPedidos(buffCodigoPedidos[posFecha], codigo,
                    buffDniCantPedidos[posFecha], dniPedidos, cantPed);
            cantFechas++;
        }
        arrcantLibrosXfecha[posFecha]++;
    }

    buffFechPedidos[cantFechas] = 0;
    buffCodigoPedidos[cantFechas] = nullptr;
    buffDniCantPedidos[cantFechas] = nullptr;
    cantFechas++;


    fechaPedidos = new int [cantFechas];
    codigoPedidos = new char **[cantFechas];
    dniCanPedidos = new int **[cantFechas];

    for (int i = 0; buffFechPedidos[i]; i++) {
        fechaPedidos[i] = buffFechPedidos[i];
        codigoPedidos[i] = new char *[arrcantLibrosXfecha[i] + 1] {
        };
        dniCanPedidos[i] = new int *[arrcantLibrosXfecha[i] + 1] {
        };
        char **auxBuffChar = buffCodigoPedidos[i];
        char **auxCoPed = codigoPedidos[i];
        int **auxBuffdni = buffDniCantPedidos[i];
        int **auxdni = dniCanPedidos[i];
        for (int j = 0; j < arrcantLibrosXfecha[i]; j++) {
            auxCoPed[j] = auxBuffChar[j];
            auxdni[j] = auxBuffdni[j];
        }
    }
    fechaPedidos[cantFechas - 1] = 0;
    codigoPedidos[cantFechas - 1] = nullptr;
    dniCanPedidos[cantFechas - 1] = nullptr;
}

int buscarFecha(int fecha, int *buffFechPedidos) {
    for (int i = 0; buffFechPedidos[i]; i++) {
        if (fecha == buffFechPedidos[i]) return i;
    }
    return NO_ENCONTRADO;
}

void agregarDatosPedidos(char **regCodPedidos, char *codigo, int **regDniPed,
        int dniCanPedidos, int cantPed) {
    int posVacio = 0;
    for (posVacio = 0; regCodPedidos[posVacio]; posVacio++);
    regCodPedidos[posVacio] = new char [strlen(codigo) + 1];
    regDniPed[posVacio] = new int [2];
    strcpy(regCodPedidos[posVacio], codigo);
    int *aux = regDniPed[posVacio];
    aux[0] = dniCanPedidos;
    aux[1] = cantPed;
}

void pruebaDeLecturaDePedidos(const char *nomArch, int *fechaPedidos, char ***codigoPedidos,
        int ***dniCanPedidos) {
    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    for (int i = 0; fechaPedidos[i]; i++) {
        arch << "Fecha :";
        imprimirFecha(arch, fechaPedidos[i]);
        arch << endl;
        for (int j = 0; dniCanPedidos[i][j]; j++) {
            arch << right << setfill('0') << setw(2) << j + 1 << setfill(' ') <<
                    ")  " << left << setw(10) << dniCanPedidos[i][j][0];
            arch << setw(10) << codigoPedidos[i][j] << setw(10) <<
                    dniCanPedidos[i][j][1] << endl;
        }
        arch << endl;
    }
}

void imprimirFecha(ofstream &arch, int fecha) {
    int aa = fecha / 10000;
    int mm = (fecha - aa * 10000) / 100;
    int dd = fecha % 100;
    arch << right << setfill('0') << setw(2) << dd << '/' << setw(2) << mm << 
            '/' << aa << setfill(' ');
}

void reporteDeEnvioDePedidos(const char *nomArch, char ***productos, int *stock,
        double *precios, int *fechaPedidos, char ***codigoPedidos,
        int ***dniCanPedidos) {
    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    double totalGanado = 0;
    double totaPerdido = 0;
    arch << fixed << setprecision(2);

    for (int i = 0; fechaPedidos[i]; i++) {
        double Ganado = 0;
        double Perdido = 0;
        arch << "Fecha :";
        imprimirFecha(arch, fechaPedidos[i]);
        arch << endl;
        arch << left << setw(4) << "No." << setw(25) << "DNI" << setw(65) <<
                "Producto" << setw(18) << "Cantidad" << setw(15) << "Precio" <<
                "Total Ingresado" << endl;
        for (int j = 0; dniCanPedidos[i][j]; j++) {
            int posLiro = buscarCodigoLibro(codigoPedidos[i][j], productos);
            if (stock[posLiro] >= dniCanPedidos[i][j][1]) {
                stock[posLiro] -= dniCanPedidos[i][j][1];
                arch << right << setfill('0') << setw(2) << j + 1 << setfill(' ') <<
                        ")  " << left << setw(10) << dniCanPedidos[i][j][0];
                arch << left << setw(12) << ' ' << setw(10) << 
                        codigoPedidos[i][j] << setw(60) << productos[posLiro][1] << 
                        right << setw(2) << dniCanPedidos[i][j][1] << setw(20) << 
                        precios[posLiro] << setw(17) << 
                        dniCanPedidos[i][j][1] * precios[posLiro] << endl;
                Ganado += dniCanPedidos[i][j][1] * precios[posLiro];
            } else {
                Perdido += dniCanPedidos[i][j][1] * precios[posLiro];
            }
        }
        arch << left << setw(15) << "total ganado :" << right << setw(15) << 
                Ganado << endl;
        arch << left << setw(15) << "total Perdido :" << right << setw(15) << 
                Perdido << endl;
        totalGanado += Ganado;
        totaPerdido += Perdido;
        arch << endl;
    }
    arch << "RESUMEN" << endl;
    arch << right << "total de ingresos en el periodo :" << setw(15) << totalGanado << endl;
    arch << "total de perdidas en el periodo :" << setw(15) << totaPerdido << endl;
}

int buscarCodigoLibro(char *codigo, char ***productos) {
    for (int i = 0; productos[i]; i++) {
        if (strcmp(productos[i][0], codigo) == 0)return i;
    }
    cout << "no lo encontre beba" << endl; //solo por si acaso
    return NO_ENCONTRADO;
}