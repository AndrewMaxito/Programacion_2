
/* 
 * File:   FuncionesRegistro.h
 * Author: andre
 *
 * Created on 11 de mayo de 2024, 18:34
 */

#ifndef FUNCIONESREGISTRO_H
#define FUNCIONESREGISTRO_H

void *leeregistro(ifstream &arch);
void imprimeregistro(ofstream &arch,void *dato);
int cmpregistro(void *dato1,void *dato2);

#endif /* FUNCIONESREGISTRO_H */

