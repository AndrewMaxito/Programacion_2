/* 
 * Archivo: ConjuntoDePedidos.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ConjuntoDePedidos.hpp"
#include "Pedido.hpp"
#include "Comunes.hpp"
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo) {
    ifstream archivo_de_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_pedidos, nombre_de_archivo);
    archivo_de_pedidos >> conjuntoDePedidos;
    archivo_de_pedidos.close();
}

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePedidos buffer_de_conjuntoDePedidos;
    Pedido pedido;

    inicializar_buffer_de_conjunto_de_pedidos(buffer_de_conjuntoDePedidos, 200);
    while (archivo_de_pedidos >> pedido) {
        buffer_de_conjuntoDePedidos << pedido;
    }
    buffer_de_conjuntoDePedidos >> conjuntoDePedidos;

}

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad) {
    conjuntoDePedidos.enteros = new int*[cantidad];
    conjuntoDePedidos.cadenas = new char**[cantidad];
    conjuntoDePedidos.reales = nullptr;
    for (int i = 0; i < cantidad; i++) {
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    int posCliente = buscar_cliente(buffer_de_conjuntoDePedidos, pedido.dni_cliente);
    if (posCliente == CLIENTE_NO_ENCONTRADO) {
        /*Cliente nuevo*/
        //buscamos la posicion del cliente
        posCliente = obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
        inciializarDatosConjuntoPedidos(buffer_de_conjuntoDePedidos, pedido, posCliente);
    }
    int *ptrEnteros = buffer_de_conjuntoDePedidos.enteros[posCliente];
    char **ptrCadena = buffer_de_conjuntoDePedidos.cadenas[posCliente];
    //
    int cantPlatos = ptrEnteros[1];

    ptrEnteros[cantPlatos + 2] = pedido.cantidad_platos;
    ptrCadena[cantPlatos + 1] = new char [strlen(pedido.codigo_plato) + 1];
    strcpy(ptrCadena[cantPlatos + 1], pedido.codigo_plato);
    ptrEnteros[1]++;
    //Insertar precios por pedido mas la suma total del pedido
    //...
}

void inciializarDatosConjuntoPedidos(ConjuntoDePedidos &buffer_de_conjuntoDePedidos,
        const Pedido &pedido, const int posCliente) {
    /*Cliente nuevo*/
    //buscamos la posicion del cliente
    //crear espacio de memoria para los datos (comos se trata de un buffer requerimos poenr un terminaodor)
    buffer_de_conjuntoDePedidos.enteros[posCliente] = new int [100] {
    };
    buffer_de_conjuntoDePedidos.cadenas[posCliente] = new char *[100] {
    };

    //Incersion de datos llave (se evitar la restricion de matrices)
    int *ptrEnteros = buffer_de_conjuntoDePedidos.enteros[posCliente];
    char **ptrCadena = buffer_de_conjuntoDePedidos.cadenas[posCliente];

    //Enteros
    ptrEnteros[0] = pedido.dni_cliente;
    ptrEnteros[1] = 0;
    //Cadena
    ptrCadena[0] = new char [strlen(pedido.codigo_repartidor) + 1];
    strcpy(ptrCadena[0], pedido.codigo_repartidor);
}

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    int cantidad = obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
    //inicializacion exacra 
    conjuntoDePedidos.enteros = new int *[cantidad + 1] {
    };
    conjuntoDePedidos.cadenas = new char **[cantidad + 1] {
    };
    conjuntoDePedidos.reales = new double *[cantidad + 1] {
    };
    //insertar Datos
    for (int i = 0; buffer_de_conjuntoDePedidos.enteros[i]; i++) {
        int *ptrBuffEnteros = buffer_de_conjuntoDePedidos.enteros[i];
        char **ptrBuffCadena = buffer_de_conjuntoDePedidos.cadenas[i];
        //
        int cantPlatos = ptrBuffEnteros[1];

        conjuntoDePedidos.enteros[i] = new int [cantPlatos + 2];
        conjuntoDePedidos.cadenas[i] = new char *[cantPlatos + 1];
        conjuntoDePedidos.reales[i] = new double [cantPlatos + 1];
        int *ptrEntero = conjuntoDePedidos.enteros[i];
        char **ptrCadena = conjuntoDePedidos.cadenas[i];

        //Insertar Datos Enteros
        for (int j = 0; j < cantPlatos + 2; j++) {
            ptrEntero[j] = ptrBuffEnteros[j];
        }
        //Insertar Cadenas
        for (int j = 0; j < cantPlatos + 1; j++) {
            ptrCadena[j] = ptrBuffCadena[j];
        }
    }
}

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni) {
    int i = 0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        int dni_del_bloque = bloque_de_enteros[0];
        if (dni_del_bloque == dni)
            return i;
        i++;
    }
    return CLIENTE_NO_ENCONTRADO;
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");

    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        int *ptrBuffEnteros = conjuntoDePedidos.enteros[i];
        char **ptrCadena = conjuntoDePedidos.cadenas[i];
        double *ptrPrecio = conjuntoDePedidos.reales[i];
        //
        int cantidadPedidos = ptrBuffEnteros[1];
        for (int j = 1; j < cantidadPedidos + 1; j++) {
            ptrPrecio[j] = (conjuntoDePlatos += ptrCadena[j])* (ptrBuffEnteros[j + 1]);
            ptrPrecio[0] += ptrPrecio[j];
        }
    }
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");

    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        int *ptrBuffEnteros = conjuntoDePedidos.enteros[i];
        char **ptrCadena = conjuntoDePedidos.cadenas[i];
        double *ptrPrecio = conjuntoDePedidos.reales[i];
        //
        int cantidadPedidos = ptrBuffEnteros[1];
        for (int j = 1; j < cantidadPedidos + 1; j++) {
            ptrPrecio[j] = (conjuntoDePlatos += ptrCadena[j])* (ptrBuffEnteros[j + 1]);
            ptrPrecio[0] += ptrPrecio[j];
        }
    }
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {

}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");

    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        int *ptrBuffEnteros = conjuntoDePedidos.enteros[i];
        char **ptrCadena = conjuntoDePedidos.cadenas[i];
        //
        int cantidadPedidos = ptrBuffEnteros[1];
        for (int j = 1; j < cantidadPedidos + 1; j++) {
            ptrCadena[j] = (conjuntoDePlatos == ptrCadena[j]);
        }
    }
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {

    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        char nombreArchivo[50]{};
        int *ptrEnteros = conjuntoDePedidos.enteros[i];
        char **ptrCadena = conjuntoDePedidos.cadenas[i];
        double *ptrReales = conjuntoDePedidos.reales[i];
        obtener_nombre_archivo(nombreArchivo, ptrEnteros[0]);

        ofstream archReporte(nombreArchivo, ios::out);
        if (!archReporte) {
            cout << "No  se pudo abrir el archivo reporte" << endl;
            exit(1);
        }
        
        archReporte <<fixed<<setprecision(2);
        imprimir_linea(archReporte);
        archReporte << "    D.N.I. CLIENTE: " << ptrEnteros[0] << endl;
        archReporte << " CODIGO REPARTIDOR: " << ptrCadena[0] << endl;
        imprimir_linea(archReporte);

        archReporte << "ITEM PLATO                 CANT SUBTOTAL" << endl;
        imprimir_linea(archReporte, '-');
        for (int j = 0; j < ptrEnteros[1]; j++) {
            archReporte << right << setfill('0') << setw(2) << j + 1 << setfill(' ');
            archReporte << left << setw(3) << ' ' << setfill('.')<< setw(25)  <<
                    ptrCadena[j + 1]<< setfill(' ')<< right  << ptrEnteros[j+2]   <<
                    setw(7) << ptrReales[j+1] <<endl;

        }
        imprimir_linea(archReporte, '-');
        archReporte <<right<<setw(31) <<"SUBTOTAL: " << setw(7) << ptrReales[0] << endl;
        double igb = ptrReales[0]*(18.0/100);
        archReporte << setw(31)<<"I.G.V.: " << setw(7) << igb << endl;
        archReporte << setw(31)<<"TOTAL: " << setw(7) <<igb + ptrReales[0]  << endl;
        imprimir_linea(archReporte);
    }
}

void obtener_nombre_archivo(char *nombre_archivo, int dni_numero) {
    char dni_cadena[9];
    mi_itoa(dni_numero, dni_cadena);//convierte el numero a cadena
    strcpy(nombre_archivo, "comprobante/");
    strcat(nombre_archivo, dni_cadena);
    strcat(nombre_archivo, ".txt");
}

void imprimir_linea(ofstream &archDeReporte, char c) {
    for (int i = 0; i < MAXIMO_POR_LINEA; i++)
        archDeReporte << c;
    archDeReporte << endl;
}

int obtener_cantidad_cliente(const ConjuntoDePedidos &conjuntoDePedidos) {
    int i = 0;
    while (conjuntoDePedidos.enteros[i] != nullptr)
        i++;
    return i;
}