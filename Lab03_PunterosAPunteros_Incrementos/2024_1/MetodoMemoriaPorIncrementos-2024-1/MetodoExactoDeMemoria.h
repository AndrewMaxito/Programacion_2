
/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: andre
 *
 * Created on 19 de setiembre de 2024, 14:37
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H
void lecturaDePedidos(const char* nomArch,char ***&libros, int **&stock);
char *leerCadenaExacta(ifstream &arch, char deli);
void incrementarEspaciosLibros(char ***&libros,int **& stock,int &cantLibros,
        int &capLibros);
void pruebaDeLecturaDeLecturaDeLibros(const char *nomArch,char ***libros,int **stock);

//Pregunta 2
void atencionDePedidos(const char *nomArch,char ***libros,int **stock,
        int **&pedidosClientes,char ***&pedidosLibros, bool **&pedidosAtendidos);
void incremnetarEspaciosCli(int **&pedidosClientes,int &cantClientes,int &capClientes);
int buscarPosCliente(int **pedidosClientes,int dniCliente);
void incrementarEspaciosRegClientes(int *&pedidosClientes,int &cant, int &cap);
void incrementarEspaciosPedLib(char ***&pedidosLibros, bool **&pedidosAtendidos,int cant, int &cap);
void incremnetarEspaciosRegLibPed(char **&librosPedidos, bool *&atePedido,int &cant, int &cap) ;
int buscarLibro(char ***libros, char *codigoLib);
//Pregunta 3
void ordenarPedidosClientes(int **pedidosClientes);
void qSort(int **pedidosClientes, int izq, int der);
void cambiar(int *&datoI, int *&datoK);
//Pregunta 4
void reporteDeEntregaDePedidos(const char *nomArch, int **pedidosClientes, char ***pedidosLibros,
        bool **pedidoAtendidos) ;
void imprimirLineas(ofstream &arch, int cant, char car) ;

#endif /* METODOEXACTODEMEMORIA_H */
