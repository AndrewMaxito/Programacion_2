
/* 
 * File:   FuncionesRegistro.h
 * Author: andre
 *
 * Created on 9 de octubre de 2024, 12:07
 */

#ifndef FUNCIONESREGISTRO_H
#define FUNCIONESREGISTRO_H

#include <fstream>
using namespace std;
void *leeRegistro(ifstream &arch);
void imprimeRegistro(ofstream &arch,void *dato);
int cmpRegistro(void *a,void *b);

#endif /* FUNCIONESREGISTRO_H */
