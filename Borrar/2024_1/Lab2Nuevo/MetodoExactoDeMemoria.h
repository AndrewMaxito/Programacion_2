/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: andre
 *
 * Created on 8 de septiembre de 2024, 11:04 PM
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H
void lecturaDeLibros(const char *nomArch,char ***&libros,int **&stock);
char **leerDatosLibros(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char deli);
void pruebaDePedidos(const char *nomArch, char ***libros, int **stock) ;
int *leerDatosStock(ifstream &arch);

//parte 2 
void atencionDepedidos(const char *nomArch,char ***libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros, bool **&pedidosAtendidos);
void ingresarDatosArrPedidosCliente(ifstream &arch, int **buffPedidosClien, 
        int &numeroPedido,int &cantClientes);


int buscarPosCliente(int dniCliente, int **buffPedidosClien) ;
void cargarDatos(int *datosCliente,int dniCliente,int numeroPedido);
void ingresarDatosLibros(ifstream &arch, char ***libros, int **&stock, bool *registroPedAten,
        char **registroPedLib, int numPedido,int &cantLibros) ;
int buscarPosLibro(char *codigo, char ***libros) ;


void reporteDeEntrega(const char *nomArch, int **pedidosClientes, char ***pedidosLibros, 
        bool **&pedidosAtendidos);
void imprimirLineas(ofstream &arch, int cant, char car);



#endif /* METODOEXACTODEMEMORIA_H */
