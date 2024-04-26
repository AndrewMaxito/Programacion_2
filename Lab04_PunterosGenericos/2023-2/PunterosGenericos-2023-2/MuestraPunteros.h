/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MuestraPunteros.h
 * Author: andre
 *
 * Created on 25 de abril de 2024, 12:53
 */

#ifndef MUESTRAPUNTEROS_H
#define MUESTRAPUNTEROS_H
void imprimeProductos(void *productos);
void leerProducto(ofstream &arch,void *registroProd);

void imprimeClientes(void *clientes);
void leerCliente(ofstream &arch,void *registroClientes);

#endif /* MUESTRAPUNTEROS_H */

