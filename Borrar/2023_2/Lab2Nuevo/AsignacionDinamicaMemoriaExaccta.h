/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AsignacionDinamicaMemoriaExaccta.h
 * Author: andre
 *
 * Created on 11 de septiembre de 2024, 05:56 PM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACCTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACCTA_H


void lecturaDeProductos(const char *nomArch, char ***&productos, int *&stock,
        double *&precios);
char *leerCadenaExacta(ifstream &arch,char deli);

void pruebaDeLecturaDeProductos(const char *nomARch,char ***productos, int *stock,
        double *precios);

//Pregunta 2
void lecturaDePedidos(const char *nomArch, int *&fechaPedidos, char ***&codigoPedidos,
        int ***&dniCanPedidos) ;
int buscarFecha(int fecha,int *buffFechPedidos);
void agregarDatosPedidos(char **regCodPedidos, char *codigo,int **regDniPed,
        int dniCanPedidos,int cantPed);

void pruebaDeLecturaDePedidos(const char *nomArch, int *fechaPedidos, char ***codigoPedidos,
        int ***dniCanPedidos);
void imprimirFecha(ofstream &arch,int fecha);

//Pregunta 3
void reporteDeEnvioDePedidos(const char *nomArch,char ***productos, int *stock,
            double *precios,int *fechaPedidos, char ***codigoPedidos, 
            int ***dniCanPedidos);
int buscarCodigoLibro(char *codigo,char ***productos);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACCTA_H */
