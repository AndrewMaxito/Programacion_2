

/* 
 * File:   listas_genericas.h
 * Author: andre
 *
 * Created on 1 de mayo de 2024, 13:43
 */

#ifndef LISTAS_GENERICAS_H
#define LISTAS_GENERICAS_H

void *leer_heroe(void *registroHeroe);
void crear_lista_heroes(void *arreglo_heroes,void *&lista_heroes,void *(*leer_heroe)(void *));
void imprimir_lista_heroes(void *lista_heroes,void (*imprimir_registro_heroe)(ofstream&,void *));
void imprimir_registro_heroe(ofstream &arch,void *dato);
void eliminar_lista_heroes_repetidos(void *&lista_heroes,void (*eliminar_registro)(void *,void *));

void eliminar_registro(void *,void *);

#endif /* LISTAS_GENERICAS_H */

