#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Persona.h"
#include "Funciones.h"

int main(int argc, char** argv) {
    
    

    struct Persona p;
    struct Persona p2 {
        32767, "Juan Gomez", 5674.64
    };

    struct Persona p3 {
        129136, "Maria Ruiz", 74653.87
    };
    ifstream arch("personas.csv", ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo personas.csv" << endl;
        exit(1);
    }
    struct Persona empleados[100];
    int n = 0;

    while (true) {
        arch >> empleados[n];
        if (arch.eof()) break;
        n++;
    }

    for (int i = 0; i < n; i++) {
        cout << empleados[i];
    }

//     cin>>p;
//    // p *= 0.2;
//     cout<<p<<p2<<p3<<endl;
//    //// cout<<p2;
//    //// cout<<p3;

    return 0;
}


