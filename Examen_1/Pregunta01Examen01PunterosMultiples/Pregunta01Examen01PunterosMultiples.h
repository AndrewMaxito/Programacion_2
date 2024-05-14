/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta01Examen01PunterosMultiples.h
 * Author: andre
 *
 * Created on 13 de mayo de 2024, 16:50
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
void cargaPedidos(int **&fechaClienteCantidad,char **&codigoProducto,const char *nomArch);
void incremetarEspacios(int **&fechaClienteCantidad, int &cantRegFecha, int &capRegFecha) ;
int buscarProducto(char **codigoProducto,char *codigo);
void incremetarEspaciosPro(char **&codigoProducto,int &cantRegPro,int &capRegPro);
int cmpnumero(const void *regI,const void *regJ);


void pruebaCargaDePedidos(int **fechaClienteCantidad,char **codigoProducto,const char *nomArch);


#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */

