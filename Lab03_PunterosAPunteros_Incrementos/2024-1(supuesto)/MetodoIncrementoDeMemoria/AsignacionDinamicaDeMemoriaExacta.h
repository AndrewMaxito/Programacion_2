
/* 
 * File:   AsignacionDinamicaDeMemoriaExacta.h
 * Author: andre
 *
 * Created on 18 de abril de 2024, 13:09
 */

#ifndef ASIGNACIONDINAMICADEMEMORIAEXACTA_H
#define ASIGNACIONDINAMICADEMEMORIAEXACTA_H
void lecturaDeLibros(const char *nomArch, char ***& libros, int **& stock) ;
char *leerCadenaExacta(ifstream &arch, char del) ;
void aumentarEspacios(char ***& libros, int **& stock,int &cantLib,int &cap);
void pruebaDeLecturaDeLibros(const char *nomArch, char ***libros, int ** stock);

void atencionDePedidos(const char *nomArch, char ***libros, int ** stock,int **& pedidosClientes, 
        char ***&pedidosLibros, bool **&pedidosAtendidos);
void aumentarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, int &cantPedidos,
        int &cap);

int buscarPosLibro(char ***libros, char *codigoPed);
void aumentarEspacios(int **&pedidosClientes,int &cantClientes,int &capClientes);
int buscarCliente(int **pedidosClientes, int numDni);
void aumentarEspacio(int *pedidosClientes,int &arrCantLibros,int &arrCapLibros);
#endif /* ASIGNACIONDINAMICADEMEMORIAEXACTA_H */

