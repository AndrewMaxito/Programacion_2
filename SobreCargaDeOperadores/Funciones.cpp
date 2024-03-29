#include <iostream>
#include <fstream>
#include <iomanip>

#include "Persona.h"
using namespace std;

void operator*=(struct Persona &p, double porcent) {
    p.sueldo *= (1 + porcent);
}

ostream & operator<<(ostream &out, const struct Persona &p) {
    out.precision(2);
    out << fixed;
    out << setw(10) << p.dni << " " << left << setw(45) << p.nombre << right << setw(10) << p.
            sueldo << endl;
    return out;
}

//void operator <<(ostream &out, const struct Persona &p){
// out.precision(2);
// out<<fixed;
// out<<"DNI: "<<p.dni<<endl;
// out<<"Nombre: "<<p.nombre<<endl;
// out<<"Sueldo: "<<p.sueldo<<endl<<endl;
//}

void operator>>(ifstream &arch, struct Persona &p) {
    arch >> p.dni;
    if (arch.eof())return;
    arch.get(); // sacamos la coma
    arch.getline(p.nombre, 60, ',');
    arch >> p.sueldo;
}

//istream & operator >>(ifstream &arch, struct Persona &p){
////istream & operator >>(istream &in, struct Persona &p){
// arch>>p.dni;
// if(arch.eof())return arch;
// arch.get(); // sacamos la coma
//
// arch.getline(p.nombre,60,',');
// arch>>p.sueldo;
// return arch;
//}


//istream & operator >> (istream &in, struct Persona &p) {
//    in >> p.dni; 
//    in >> p.sueldo;
//    in.getline(p.nombre,60,',');
//    in.clear();
//    return in;
//}