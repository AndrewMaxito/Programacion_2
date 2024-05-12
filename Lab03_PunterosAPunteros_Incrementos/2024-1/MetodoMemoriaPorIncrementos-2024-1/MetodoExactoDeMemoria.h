
/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: andre
 *
 * Created on 9 de mayo de 2024, 13:06
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H
//Pregunta 1
void lecturaDeLibros(const char *nomArch,char ***&libros,int **&stock);
void pruebaDeLecturaDeLibros(const char *nomArch,char ***libros,int **stock);
char *leerCadenaExacta(ifstream &arch,char deli);
void aumentarEspacioLibros(char ***&libros, int **&stock, int &cantLibros, int &capacidad);


void imprimirLineas(ofstream &arch,int cant,char car);

//Pregunta 2
void atencionDePedidos(const char *nomArch,char ***libros,int **stock,int **&pedidosClientes,
        char ***&pedidosLibros,bool **&pedidoAtendidos);
void incrementarEspaciosPedidos(char ***&pedidosLibros, bool **&pedidoAtendidos, int &capacidadPedi,
        int numPedido);
void incrementarEspacioLibrosPedidos(char **&pedidosLibros,bool *&pedidoAtendidos,int &buffCap,int &buffCant);
int buscarPosLibro(char ***libros,char *codigoLibro);

void incrementarEspacioClientes(int **&pedidosClientes,int &capClientes,int &cantClientes);
int buscarCliente(int **pedidosClientes, int dniCliente);
void incrementarEspacios(int *&pedidosClientes, int &arrCantCli, int &arrCapCli);


//pregunta 3

void ordenarPedidosClientes(int **pedidosClientes);
void qSort(int **pedidosClientes,int izq,int der);
void cambiar(int *&datoI,int  *&datoK);
//funciones generales

//Pregunta 4
void reporteDeEntregaDePedidos(const char *nomArch,int **pedidosClientes,char ***pedidosLibros,
            bool **pedidoAtendidos);

#endif /* METODOEXACTODEMEMORIA_H */

