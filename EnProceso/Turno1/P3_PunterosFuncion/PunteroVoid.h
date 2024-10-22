/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunteroVoid.h
 * Author: andre
 *
 * Created on 21 de octubre de 2024, 22:33
 */

#ifndef PUNTEROVOID_H
#define PUNTEROVOID_H
void cargaVentas(char ***libro,void *&ventas);
void actulizarVentas(int **ventasDniFechaPuntaje,char **ventaLibroCodigo,void *ventas);
int buscarLibro(void *ventas,char *codigoLibVen);
#endif /* PUNTEROVOID_H */
