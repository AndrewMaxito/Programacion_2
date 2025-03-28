/* 
 * Archivo: Comunes.hpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 23:33
 */

#ifndef COMUNES_HPP
#define COMUNES_HPP
#include <fstream>
using namespace std;
char *mi_strdup(const char *cadena);

void invierte_cadena(char *cadena, int inicio, int fin);

void mi_itoa(int numero, char *cadena);
char* leerCadenaExacata(istream& archivo_de_platos, char deli);
#endif /* COMUNES_HPP */

