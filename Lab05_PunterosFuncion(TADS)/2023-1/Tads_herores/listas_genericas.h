

/* 
 * File:   listas_genericas.h
 * Author: andre
 *
 * Created on 9 de octubre de 2024, 19:57
 */

#ifndef LISTAS_GENERICAS_H
#define LISTAS_GENERICAS_H
void *leer_heroe(void *regHer);
void crear_lista_heroes(void *arreglo_heroes,void *&lista_heroes,void *(*leer_heroe)(void *regisHer));
void imprimir_registro_heroe(ofstream &arch,void *dat);
void imprimir_lista_heroes(void *lista_heroes, 
        void (*imprimir_registro_heroe)(ofstream &, void *), const char*nomArch);

void eliminar_registro(void *actual, void *&siguiente);
void eliminar_lista_heroes_repetidos(void *&lista_heroes, void (*eliminar_registro)(void *, void*&));

void imprimirLineas(ofstream &arch,int cant,char car);
#endif /* LISTAS_GENERICAS_H */
