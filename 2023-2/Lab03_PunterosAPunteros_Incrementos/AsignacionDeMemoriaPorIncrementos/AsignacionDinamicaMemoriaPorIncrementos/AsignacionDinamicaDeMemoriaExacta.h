/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaDeMemoriaExacta.h
 * Author: andre
 *
 * Created on 16 de abril de 2024, 13:02
 */

#ifndef ASIGNACIONDINAMICADEMEMORIAEXACTA_H
#define ASIGNACIONDINAMICADEMEMORIAEXACTA_H

void lecturaDeProductos(const char *nomArch,char ***&productos,int *&stock, 
        double *&precio);
void PruebaDeLecturaDeProductos(const char *nomArch,char ***productos,
        int *stock, double *precio);
char *leerCadenaExacta(ifstream &arch,char deli);
void aumentarEspacios(int *&stock, int &numDat, int cap) ;
void aumentarEspacios(double *&precio, int numDat, int cap);
void aumentarEspacios(char ***&productos, int numDat, int cap);
void insertarDatosProducto(char **&producto,char *codigo,char *descrip);
void lecturaDePedidos(const char *nomArch, int *&fechaPedidos, char ***&codigoPedidos,
        int ***&dniCantPedidos);
void PruebaDeLecturaDePedidos(const char *nomArch, int *fechaPedidos, char ***codigoPedidos,
        int ***dniCantPedidos);
int buscarFecha(int *fechaPedidos, int buffFecha, int cantFechas);
void aumentarEspacios(int ***&dniCantPedidos,int cantFechas ,int cap);
void aumentarEspacios(char **&codigoPedidos,int cantPedFecha,int cap);
void aumentarEspacios(int **&dniCantPedidos,int cantPedFecha,int cap);
int cantPedidosAcumulados(char **codigoPedidos);
#endif /* ASIGNACIONDINAMICADEMEMORIAEXACTA_H */

