/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: andre
 *
 * Created on 11 de abril de 2024, 10:30
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H
#include <fstream>
using namespace std;

void lecturaDeProductos(const char *nomArch,char  ***&productos,
        int *&stock, double  *&precios);
void pruebaDeLecturaDeProductos(const char *nomArch,char  ***productos,
        int *stock, double  *precios);

void lecturaDePedidos(const char *nomArch,int *&fechaPedidos,char ***&CodigoPedidos,
        int ***&dniCantPedidos);
void pruebaDeLecturaDePedidos(const char *nomArch,int *fechaPedidos,char ***CodigoPedidos,
        int ***dniCantPedidos);

char **leerProducto(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char delimi);

int buscarFecha(int *buffFechas,int fecha,int cantidadFechas);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

