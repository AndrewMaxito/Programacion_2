

/* 
 * File:   Libro.h
 * Author: andre
 *
 * Created on 17 de noviembre de 2024, 12:30 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;
class Libro {
public:
    Libro();
    virtual ~Libro();
    double GetPeso() const;
    void SetNombre(const char* cad);
    virtual void lee(ifstream &arch);
    virtual void actualiza() = 0;
    virtual void imprime(ofstream &arch);
private:
    char *nombre;
    int paginas;
    double peso;
};
#endif /* LIBRO_H */

