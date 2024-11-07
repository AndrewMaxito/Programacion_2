
/* 
 * File:   Medicamentos.h
 * Author: andre
 *
 * Created on 28 de mayo de 2024, 12:36
 */

#ifndef MEDICAMENTOS_H
#define MEDICAMENTOS_H
#include <fstream>
using namespace std;

class Medicamentos {
private:
    int codigo;
    char* nombre;
    int cantidad;
    double precio;
    int fecha; //aaaammdd

public:
    Medicamentos();
    virtual ~Medicamentos();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char* cad) ;
    void GetNombre(char *cad) const ;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    //
    void cargarDatosMedicamento(int codigoMedicamneto,int cantMedi,int fecha,
        ifstream& archMedicamneto);

};

#endif /* MEDICAMENTOS_H */

