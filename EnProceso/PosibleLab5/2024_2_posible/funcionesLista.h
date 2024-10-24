/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funcionesLista.h
 * Author: andre
 *
 * Created on 24 de octubre de 2024, 16:56
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H
void crearLista(void *&listaPlatos, void *(*leerRegistro)(ifstream &arch ), const char* nomArch) ;
void *cosntruirLista();
bool esListaVacia(void *listaPlatos);
void insertaLista(void *listaPlatos,void *dato);
void *buscaNodoPlato(void *listaPlatos, char *buffCodPla) ;
void actualizarLista(void *listaPlatos, const char *nomArch) ;
#endif /* FUNCIONESLISTA_H */
