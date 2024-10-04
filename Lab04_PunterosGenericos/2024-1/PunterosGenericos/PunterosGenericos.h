
/* 
 * File:   PunterosGenericos.h
 * Author: andre
 *
 * Created on 21 de setiembre de 2024, 19:55
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

//#include <fstream>
//using namespace std;

void cargaClientes(void *&clientes);
void *leerRegistroClientes(ifstream &arch);
void incrementarEspaciosParaCliente(void *&regClientes,int &cantCli,int &capCli);

//Pregunta 2
void creaReserva(void *&reserva);
void *leerRegistroLibros(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char del);

//Pregunta 3
void cargaRerserva(void *clientes,void *reserva);
int buscarLibro(const void *reserva, const char *codigoLib);
int buscarCliente(const void *clientes, const int dni);

#endif /* PUNTEROSGENERICOS_H */
