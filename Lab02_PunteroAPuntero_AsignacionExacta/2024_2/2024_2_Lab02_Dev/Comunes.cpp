/* 
 * Archivo: Comunes.cpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 23:33
 */

#include <cstring>
#include <fstream>
#include "Comunes.hpp"

using namespace std;

char *mi_strdup(const char *cadena) {
    size_t tamanho_cadena = strlen(cadena);
    char *bloque_nuevo = new char[tamanho_cadena + 1];
    strcpy_s(bloque_nuevo, tamanho_cadena ,cadena);
    return bloque_nuevo;
}

void mi_itoa(int numero, char *cadena){    
    int i = 0;
    while (numero != 0) {
        int digito = numero % 10;
        numero /= 10;
        cadena[i++] = '0' + digito;
    }
    invierte_cadena(cadena, 0, i-1);
    cadena[i] = '\0';    
}

void invierte_cadena(char *cadena, int inicio, int fin) {    
    while (inicio < fin) {
        char aux = cadena[inicio];
        cadena[inicio] = cadena[fin];
        cadena[fin] = aux;
        fin--;
        inicio++;
    }
}


char* leerCadenaExacata(istream& archivo_de_platos, char deli) {
    char buff[150], * ptr;
    archivo_de_platos.getline(buff, 150, deli);
    if (archivo_de_platos.eof())return nullptr;
    ptr = new char[strlen(buff) + 1];
    strcpy_s(ptr, strlen(buff) + 1, buff);
    return ptr;
}