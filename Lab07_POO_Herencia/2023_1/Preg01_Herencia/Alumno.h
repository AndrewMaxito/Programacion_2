

/* 
 * File:   Alumno.h
 * Author: andre
 *
 * Created on 5 de noviembre de 2024, 16:17
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void leerDatos(ifstream &arch);
    void imprime(ofstream&arch);
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
};

#endif /* ALUMNO_H */

