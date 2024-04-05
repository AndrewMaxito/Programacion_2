#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "BibliotecaEstatica.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"

bool operator>>(ifstream &archCliente, struct Cliente &cliente) {

    int dni;
    archCliente>>dni;
    if (archCliente.eof()) return false;
    cliente.dni = dni;
    archCliente.get();
    archCliente.getline(cliente.nombre, 60, ',');
    archCliente >> cliente.telefono;
    cliente.cantidadProductosEntrgados = 0;
    cliente.montoTotal = 0;
    return true;
}

bool operator>>(ifstream &archPro, struct Producto &prod) {

    char buff[8], c;
    archPro.getline(buff, 8, ',');
    if (archPro.eof()) return false;
    strcpy(prod.codigo, buff);
    archPro.getline(prod.descripcion, 60, ',');
    archPro >> prod.precio >> c >> prod.stock;
    archPro.get();

    prod.cantidadClientesServidos = 0;
    prod.cantidadClientesNoServidos = 0;

    return true;
}

bool operator>>(ifstream &archPedi, struct Pedido &pedi) {
    char buff[8];

    archPedi.getline(buff, 8, ',');
    if (archPedi.eof()) return false;
    archPedi >> pedi.dniCliente;
    archPedi.get();
    cout << pedi.dniCliente << endl;
    strcpy(pedi.CodigoProducto, buff);

    pedi.precioProducto = 0;
    return true;
}

void operator+=(struct Cliente *arrCli, const struct Pedido &Ped) {
    int pos = 0, flag = 0;
    for (pos; arrCli[pos].dni != 0; pos++)
        if (arrCli[pos].dni == Ped.dniCliente) {
            flag = 1;
            break;
        }

    //Incrementar 

    if (flag == 1) {
        int prodEntre = arrCli[pos].cantidadProductosEntrgados;
        strcpy(arrCli[pos].productosEntregados[prodEntre].codigo, Ped.CodigoProducto);
        arrCli[pos].productosEntregados[prodEntre].precio = 0;
        arrCli[pos].cantidadProductosEntrgados++;

    } else cout << "No se encontro al cliente" << endl;

}

bool operator+=(struct Producto *arrPro, const struct Pedido &Ped) {
    int pos = 0, flag = 0;
    for (pos; strcmp(arrPro[pos].codigo, "XXXXXXX") != 0 and arrPro[pos].codigo[0] != '\0'; pos++)
        if (strcmp(arrPro[pos].codigo, Ped.CodigoProducto) == 0) {
            flag = 1;
            break;
        }
    //    
    if (flag == 1) {

        if (arrPro[pos].stock > 0) {
            int cantClientes = arrPro[pos].cantidadClientesServidos;
            arrPro[pos].clientesServidos[cantClientes] = Ped.dniCliente;
            arrPro[pos].cantidadClientesServidos++;
            arrPro[pos].stock--;
            return true;
        } else {
            int cantClientes = arrPro[pos].cantidadClientesNoServidos;
            arrPro[pos].clientesNoServidos[cantClientes] = Ped.dniCliente;
            arrPro[pos].cantidadClientesNoServidos++;
            return false;
        }
    }
    cout << "No se encontro el producto chichobelo" << endl;
    return false;
}

void operator<<(ofstream &arch, const struct Cliente &cliente) {

    arch << cliente.dni << left << setw(5) << ' ' << setw(40) << cliente.nombre << setw(11) <<
            cliente.telefono << setw(11) << cliente.montoTotal << "PRODUCTOS ENTREGADOS:  ";
    if (cliente.cantidadProductosEntrgados != 0) {
        for (int i = 0; i < cliente.cantidadProductosEntrgados; i++)
            arch << cliente.productosEntregados[i].codigo;
    } else arch << "NO SE LE ENTREGARON PRODUCTOS";
    arch << right << endl;
}

void operator<<(ofstream &arch, const struct Producto &Pro) {
    arch << left << setw(9) << Pro.codigo << setw(60) << Pro.descripcion << setw(8) <<
            Pro.precio << Pro.stock << endl;
    if (Pro.cantidadClientesServidos > 0) {
        arch << "CLIENTES ATENDIDOS:   ";
        for (int i = 0; i < Pro.cantidadClientesServidos; i++) arch << Pro.clientesServidos[i] << "   ";
        arch << endl;
        if (Pro.cantidadClientesNoServidos > 0) {
            for (int i = 0; i < Pro.cantidadClientesNoServidos; i++) arch << Pro.clientesNoServidos[i] << "   ";
            arch << endl;
        }else arch<<"NO hay clientes sin atender"<<endl;
    } else arch << "No se atendieron Pedidos" << endl;

}