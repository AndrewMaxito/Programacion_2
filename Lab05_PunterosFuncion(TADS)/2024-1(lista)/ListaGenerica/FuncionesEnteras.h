/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesEnteras.h
 * Author: andre
 *
 * Created on 9 de octubre de 2024, 12:07
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H
#include <fstream>
using namespace std;
void *leeNum(ifstream &arch);
void imprimeNum(ofstream &,void *dato);
int cmpNum(void *a,void *b);
#endif /* FUNCIONESENTERAS_H */
