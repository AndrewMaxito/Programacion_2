
/* 
 * File:   Pregunta02Examen01PunterosGenericos.h
 * Author: andre
 *
 * Created on 13 de mayo de 2024, 18:40
 */

#ifndef PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H
#define PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H

void cargarProductos(void *&productos, const char *nomArch);
void  *leerRegistroDatos(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char deli);
void crearEspacios(void *&productos,int &cantProd,int &capProd);
int cmpProdcutos(const void *reg1, const void *reg2);

void pruebaDecargarDeProductos(void *productos);


#endif /* PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H */

