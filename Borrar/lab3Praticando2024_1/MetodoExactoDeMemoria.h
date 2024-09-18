/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: andre
 *
 * Created on 18 de septiembre de 2024, 11:02 AM
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H
void lecturaDeLibros(const char *nomArch,char ***&libros,int **&stock);
char *leerCadenaExacta(ifstream &arch, char del);
void aumentarEspacioLib(char ***&libros, int **&stock, int &cantLibros, int &capacidad);
void almacenarDatosLibros(char **Reglibro,char *codigo,char *descrip,char *autor);
void almacenarDatosStock(int *regStock,int bffStock);
void pruebaDeLecturaDeLibros(const char *nomArch, char ***libros, int **stock);

//Pregunta 2
void atencionDePedidos(const char *nomArch,char ***libros,int **stock,
        int **&pedidosClientes,char ***&pedidosLibros, bool **&pedidosAtendidos);
int buscaLibro(char ***libros, char *codigoLib);
int buscarCliente(int **pedidosClientes, int dni);
void aumentarEspaciosCli(int **&pedidosClientes, int &cantClien, int &capClien) ;
void aumentarEspacioRegCli(int *&regCliente,int &cant,int &cap,int dni);
void aumentarEspaciosPedidos(bool **&pedidosAtendidos, char ***&pedidosLibros, int codigoPedido, int capPedidos) ;
void aumentarEspacioRegLib(char **&regPedLib, bool *&regPedAten, int &cant, int &cap) ;
#endif /* METODOEXACTODEMEMORIA_H */
