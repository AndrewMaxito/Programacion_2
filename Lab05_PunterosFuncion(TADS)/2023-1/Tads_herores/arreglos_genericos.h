/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   arreglos_genericos.h
 * Author: andre
 *
 * Created on 9 de octubre de 2024, 19:56
 */

#ifndef ARREGLOS_GENERICOS_H
#define ARREGLOS_GENERICOS_H
#include <fstream>
using namespace std;

void llenar_arreglo_heroes(void *&arrHeroes,int &cantHerores, const char* nomArch);
void *leerDatosHeroe(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char del);
int cmp_multicriterio_void(const void*A, const void*B);
#endif /* ARREGLOS_GENERICOS_H */
