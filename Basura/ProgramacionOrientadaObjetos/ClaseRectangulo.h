

/* 
 * File:   ClaseRectangulo.h
 * Author: andre
 *
 * Created on 20 de mayo de 2024, 13:37
 */

#ifndef CLASERECTANGULO_H
#define CLASERECTANGULO_H

class ClaseRectangulo {
private:
    double base;
    double altura;
public:
    void asignarBase(double);
    void asignarAltura(double);
    void leeDatos(void);
    double entregarBase(void);
    double entregarAltura(void);
    double imprimeDatos(void);
    double area(void);
    double perimetro(void);
    void imprimeResultados(void);
};

#endif /* CLASERECTANGULO_H */

