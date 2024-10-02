/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   punterosgenericos.h
 * Author: 51969
 *
 * Created on 30 de setiembre de 2024, 16:34
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#endif /* PUNTEROSGENERICOS_H */

char* leercadenaexacta(ifstream &arch, int lim, char c);

void* leerreg(ifstream &arch);


char* leercadenaexacta(ifstream &arch, char c);
void leerplatos(void* &pla);
void imprimirplatos(void* &pla);

void* leerrepartidor(ifstream &arch);

void leerrepartidores(void* &rep);

void imprimirrepartidores(void*rep);
int buscarrep(void**repartidores, char *codrep);
int buscardni(void*clientes, int dni);
void aumentarplatos(void** &cliente, int &cap, int &cant, int dni);

int buscarplato(void* pla,char* codplato);
void asignarplato(void**&cliente, void* &platos,char* codplato, int cant, int cantplatos, int capplatos, int dni);
void aumentarclientes(void** &clientes, int &cap, int &cant);
void asignarrep(void** &repartidores,void* & platos,int dni, int *caprep, int *cantrep,char* buffrep,int cant,char* buffplato,int *arrCapPlatXCli);

void cargarpedidos(void* &rep, void*&platos);
void imprimirborradorpedidos(void*rep);

void imprimirLineas(ofstream &arch,int cant,char car);
