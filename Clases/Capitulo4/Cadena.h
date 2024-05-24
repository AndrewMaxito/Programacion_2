
/* 
 * File:   Cadena.h
 * Author: andre
 *
 * Created on 21 de mayo de 2024, 14:56
 */

#ifndef CADENA_H
#define CADENA_H

class Cadena {
private:
    char *cadena;
    int longitud;
    int capacidad;
public:
    //Inicializador o Constructores
    Cadena();
    Cadena(const char *cad);
    Cadena(int cap);
    Cadena(const Cadena& otra); // constructor copia
    //Destructores
    ~Cadena();
    //...............................
    void inicializarCadena(void);
    //--------------------------------
    
    //Metodo Setters
    void setCadena(const char* cadena);
    
    //Metodo de Asignacion 
    
    void assign(const char *cad);
    void assign(const Cadena& otra);
    void append(const char *cad);
    void append(const Cadena& otra);
    void swap(Cadena& otra);
    void print() const;
    //Sobrecarga
    void operator = (const char *cad);
    void operator = (const Cadena& otra);
    Cadena operator+(const Cadena& otra)const;
    
    
    
};

#endif /* CADENA_H */

