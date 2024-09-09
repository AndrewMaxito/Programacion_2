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
void cargaStock(ifstream &arch, int *stock) ;
void pruebaDePedidos(const char *nomArch, char ***libros, int **stock) ;

#endif /* METODOEXACTODEMEMORIA_H */
