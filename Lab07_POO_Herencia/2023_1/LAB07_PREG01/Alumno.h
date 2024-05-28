/* 
 * File:   Alumno.h
 * Author: andre
 *
 * Created on 27 de mayo de 2024, 18:27
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <fstream>
using namespace std;

class Alumno {
private:
    int codigo;
    char* nombre;
    int escala;
    double total;

public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* cad);
    void GetNombre(char* cad) const ;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    //
    void leerDatos(ifstream& arch);
    void imprime(ofstream&arch);

};

#endif /* ALUMNO_H */

