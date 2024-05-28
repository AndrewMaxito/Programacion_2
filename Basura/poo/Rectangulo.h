
#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
public:
    void setBase(double);
    void setAltura(double);
    double getBase();
    double getAltura();
    void mostrarResultados();
    double area();
    double perimetro();
private:
    double base;
    double altura;
};

#endif /* RECTANGULO_H */

