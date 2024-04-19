
/* 
 * File:   funcio.h
 * Author: andre
 *
 * Created on 18 de abril de 2024, 20:12
 */

#ifndef FUNCIO_H
#define FUNCIO_H
void atencionDePedidos(const char *nomArch,int **&pedidosClientes);
void incrementarEspacios(int **&pedidosClientes, int &cant, int &cap);
int buscarCliente(int **pedidosClientes,int dniPedido);
void incrementarEspacios(int *&pedidosClientes,int &cant,int &cap);
#endif /* FUNCIO_H */

