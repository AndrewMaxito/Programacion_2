

/* 
 * File:   Alumno.h
 * Author: andre
 *
 * Created on 11 de junio de 2024, 18:18
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <fstream>
using namespace std;

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
    
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const ;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    //
    virtual void leer(ifstream &)=0;
    virtual void imprime(ofstream &arch)=0;

};

#endif /* ALUMNO_H */

