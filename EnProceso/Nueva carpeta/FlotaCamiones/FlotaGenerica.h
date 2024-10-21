/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FlotaGenerica.h
 * Author: andre
 *
 * Created on 19 de octubre de 2024, 18:40
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H




void cargaCamiones(void *&flota,int numCamiones,int pesoMaximo,
        void *(*leeDatos)(ifstream &), double (*calculaValor)(void *), const char* nomArch);
void costruirPila(void *&camnion);
void push(void *pila,void *dato, double peso);
#endif /* FLOTAGENERICA_H */
