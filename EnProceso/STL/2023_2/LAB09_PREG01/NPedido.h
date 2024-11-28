
/* 
 * File:   NPedido.h
 * Author: andre
 *
 * Created on 27 de noviembre de 2024, 08:52 PM
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H
#include <fstream>
using namespace std;
class NPedido {
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetCodigo(const char* cad);
    void GetCodigo(char *cad) const;
    void leerDatosVehiculo(ifstream &arch);
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    //
    void operator=(const NPedido& right);
    void imprimirDatosCamion(ofstream &arch)const;

private:
    char *codigo;
    int cantidad;
    double peso;
};

#endif /* NPEDIDO_H */

