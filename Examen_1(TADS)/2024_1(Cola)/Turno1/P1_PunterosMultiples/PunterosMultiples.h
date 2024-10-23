/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunterosMultiples.h
 * Author: andre
 *
 * Created on 21 de octubre de 2024, 20:44
 */

#ifndef PUNTEROSMULTIPLES_H
#define PUNTEROSMULTIPLES_H
void cargaVentas(char **&ventaLibroCodigo,int **&ventasDniFechaPuntaje, 
        const char *nomArch);
char *leerCadenaExacta(ifstream &arch, char deli) ;
void aumentarEspaciosVentas(char **&ventaLibroCodigo, int **&ventasDniFechaPuntaje,
        int &cantVentas, int &capVentas) ;
void pruebaDeCargaDeVentas(char **ventaLibroCodigo,int **ventasDniFechaPuntaje, 
        const char *nomArch);
void cargaLibros (char ***&libro, const char *nomArch);
void aumnetarEspaciosLibros(char ***&libro,int &cant,int &cap);
void pruebaDeCargaDeLibros(char ***libro, const char*nomArch) ;
int cmp(const void *valorA, const void *valorB);
#endif /* PUNTEROSMULTIPLES_H */
