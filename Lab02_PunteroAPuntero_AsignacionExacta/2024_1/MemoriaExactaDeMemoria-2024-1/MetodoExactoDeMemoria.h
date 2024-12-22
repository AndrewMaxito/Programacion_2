
/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: andre
 *
 * Created on 28 de abril de 2024, 12:32
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

//Pregunta 1
void lecturaDePedidos(const char *nomArch,char ***& libros,int **&stock);
char *leerCadenaExacta(ifstream &arch,char deli);
void pruebaDeLecturaDePedidos(const char *nomArch,char ***libros,int **stock);

//pregunta 2 
void atencionDePedidos(const char *nomArch, char ***libros, int **stock,int **&pedidosClientes,
        char ***&pedidosLibros,bool **&pedidosAtendidos);
int buscarPosCliente(int **buffPedidosClientes,int dniPedido);
int buscarLibro(char ***libros, char *buffPedidoLib);
void cargarArreglos(bool **buffPedAtendidos, char ***buffPedidoLib, int **buffPedidosClientes,
        int *arrCantLibro,int cantCliPed, int cantPed, int **&pedidosClientes, char ***&pedidosLibros,
        bool **&pedidosAtendidos);


//pregunta 3
void reporteDeEntrega(const char *nomArch, int **pedidosClientes, char ***pedidosLibros, 
        bool **&pedidosAtendidos);
void imprimirLineas(ofstream &arch, int cant, char car);


#endif /* METODOEXACTODEMEMORIA_H */

