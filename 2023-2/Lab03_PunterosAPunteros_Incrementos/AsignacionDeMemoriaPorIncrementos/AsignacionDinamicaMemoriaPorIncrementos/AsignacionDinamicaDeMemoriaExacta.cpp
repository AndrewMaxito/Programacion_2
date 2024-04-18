
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "AsignacionDinamicaDeMemoriaExacta.h"
#define INCREMENTO 5 //Aqui se pone de cuanto en cuanto sera el incremento de lso datos
#define NO_ENCONTRADO -1

void lecturaDeProductos(const char *nomArch, char ***&productos, int *&stock, double *&precio) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    //1.-Inicializar los punteros (nullptr) y ademas poner la capacidad y el numero de datos

    int numDat = 0, cap = 0;
    productos = nullptr;
    stock = nullptr;
    precio = nullptr;

    //Aqui se crean los almacenamientos temporrales de los datos
    int buffStock;
    double buffPrecio;
    char *codigo, *descrip, c;
    //2.-Lectura de los datos del archivo para su almacenamiento
    while (true) {
        codigo = leerCadenaExacta(arch, ',');
        if (codigo == NULL) break;
        descrip = leerCadenaExacta(arch, ',');
        arch >> buffPrecio >> c>>buffStock;
        arch.get(); //descarta el salto de linea final

        //3.-Verifico que aun se ha llenado y en caso si incremneto el espacio en 5
        if (numDat == cap) { //Si cumple esta condicion significa que se le acabaron los espacios
            cap += INCREMENTO;
            aumentarEspacios(stock, numDat, cap);
            aumentarEspacios(precio, numDat, cap);
            aumentarEspacios(productos, numDat, cap);
        }
        //4.- Se incorparon los datos a los espacios dinamicos de memoria
        stock[numDat - 1] = buffStock;
        precio[numDat - 1] = buffPrecio;
        insertarDatosProducto(productos[numDat - 1], codigo, descrip);
        numDat++;
    }
}

void PruebaDeLecturaDeProductos(const char *nomArch, char ***productos, int *stock, double *precio) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    for (int i = 0; stock[i]; i++) {
        arch << productos[i][0] << " " << productos[i][1] << " " << precio[i] << " " << stock[i] << endl;
    }



}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[500], *ptr;
    arch.getline(buff, 500, deli);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}
//

void aumentarEspacios(int *&stock, int &numDat, int cap) {
    int *aux;
    //Aqui se toma en cuento el caso base y los posteriores
    if (stock == nullptr) {
        stock = new int [cap] {
        }; //las {} son importantes
        numDat = 1;
    } else {
        aux = new int [cap] {
        };
        for (int i = 0; stock[i]; i++) aux[i] = stock[i]; //Analisar mejor por que ocurre esto
        delete[] stock;
        stock = aux;
    }
}

void aumentarEspacios(double *&precio, int numDat, int cap) {
    double *aux;
    //Aqui se toma en cuento el caso base y los posteriores
    if (precio == nullptr) {
        precio = new double [cap] {
        }; //las {} son importantes 
    } else {
        aux = new double [cap] {
        };
        for (int i = 0; precio[i]; i++) aux[i] = precio[i]; //Analisar mejor por que ocurre esto
        delete[] precio;
        precio = aux;
    }
}

void aumentarEspacios(char ***&productos, int numDat, int cap) {
    char ***aux;
    if (productos == nullptr) {
        productos = new char **[cap] {
        };
    } else {
        aux = new char **[cap] {
        };
        for (int i = 0; productos[i]; i++) aux[i] = productos[i];
        delete[] productos;
        productos = aux;
    }
}

void insertarDatosProducto(char **&producto, char *codigo, char *descrip) {
    producto = new char *[2];
    producto[0] = codigo;
    producto[1] = descrip;
}

void lecturaDePedidos(const char *nomArch, int *&fechaPedidos, char ***&codigoPedidos,
        int ***&dniCantPedidos) {

    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    //JXD-139,50375303,6,24/08/2023
    int buffFecha, buffDni, buffCantidad, dd, mm, aaaa;
    char *codigo, c;
    //
    int cantFechas = 0, cap = 0, arrCapacidad[800]{}, arrContCapacidad[800]{};
    fechaPedidos = nullptr;
    codigoPedidos = nullptr;
    dniCantPedidos = nullptr;

    while (true) {
        codigo = leerCadenaExacta(arch, ',');
        if (codigo == nullptr) break;
        arch >> buffDni >> c >> buffCantidad >> c >> dd >> c >> mm >> c>>aaaa;
        arch.get();
        buffFecha = aaaa * 10000 + mm * 100 + dd;

        //-----------------------------------------------
        int posFecha = buscarFecha(fechaPedidos, buffFecha, cantFechas);

        if (cantFechas == cap) {
            cap += INCREMENTO;
            aumentarEspacios(fechaPedidos, cantFechas, cap);
            aumentarEspacios(codigoPedidos, cantFechas, cap);
            aumentarEspacios(dniCantPedidos, cantFechas, cap);
        }
        ////        Agregar Fecha
        ////        GUARADAR EN UN ARREGLO SU CAPACIDAD PARA CADA PEDIDO ESE MISMO ARREGLO FUNCIONARA PARA 
        ////        dniCantPedidos
        if (posFecha == NO_ENCONTRADO) {
            posFecha = cantFechas - 1;
            fechaPedidos[posFecha] = buffFecha; // y si pongo la condicion arriba y de frente lo agrego ? 
            codigoPedidos[posFecha] = nullptr;
            dniCantPedidos[posFecha] = nullptr;
            cantFechas++;
        }

        if (arrContCapacidad[posFecha] == arrCapacidad[posFecha]) {
            arrCapacidad[posFecha] += INCREMENTO;
            aumentarEspacios(codigoPedidos[posFecha], arrContCapacidad[posFecha], arrCapacidad[posFecha]); //tambien creo que cantFechas es por las
            aumentarEspacios(dniCantPedidos[posFecha], arrContCapacidad[posFecha], arrCapacidad[posFecha]);
        }
        int cantProductos = arrContCapacidad[posFecha] - 1;
        codigoPedidos[posFecha][cantProductos] = codigo;
        dniCantPedidos[posFecha][cantProductos] = new int [2];
        dniCantPedidos[posFecha][cantProductos][0] = buffDni;
        dniCantPedidos[posFecha][cantProductos][1] = buffDni;
        arrContCapacidad[posFecha]++;
    }
}
//---------------------------------------------

void aumentarEspacios(int **&dniCantPedidos, int cantPedFecha, int cap) {
    int **aux;
    if (dniCantPedidos == nullptr) {
        dniCantPedidos = new int *[cap] {
        };
    } else {
        aux = new int *[cap] {
        };
        for (int i = 0; dniCantPedidos[i]; i++)aux[i] = dniCantPedidos[i];
        delete[] dniCantPedidos;
        dniCantPedidos = aux;
    }

}

void aumentarEspacios(char **&codigoPedidos, int &cantPedFecha, int cap) {
    char **aux;
    if (codigoPedidos == nullptr) {
        codigoPedidos = new char *[cap] {
        };
        cantPedFecha = 1;
    } else {
        aux = new char *[cap] {
        };
        for (int i = 0; codigoPedidos[i]; i++)aux[i] = codigoPedidos[i];
        delete[] codigoPedidos;
        codigoPedidos = aux;
    }
}

void aumentarEspacios(int ***&dniCantPedidos, int cantFechas, int cap) {
    int ***aux;
    if (dniCantPedidos == nullptr) {
        dniCantPedidos = new int **[cap] {
        };
    } else {
        aux = new int **[cap] {
        };
        for (int i = 0; dniCantPedidos[i]; i++)aux[i] = dniCantPedidos[i];
        delete[] dniCantPedidos;
        dniCantPedidos = aux;
    }
}

int buscarFecha(int *fechaPedidos, int buffFecha, int cantFechas) {
    for (int i = 0; fechaPedidos != nullptr and fechaPedidos[i]; i++)
        if (fechaPedidos[i] == buffFecha) return i;
    return NO_ENCONTRADO;
}

void PruebaDeLecturaDePedidos(const char *nomArch, int *fechaPedidos, char ***codigoPedidos,
        int ***dniCantPedidos) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    int dd, mm, aaaa;


    arch << setw(60) << "Registro de los Pedidos por Fecha:  " << endl;
    for (int i = 0; fechaPedidos[i]; i++) {
        aaaa = fechaPedidos[i] / 10000;
        mm = (fechaPedidos[i] - aaaa*10000) / 100;
        dd = fechaPedidos[i] % 100;
        arch <<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aaaa<<setfill(' ') <<endl;
        for (int j=0;codigoPedidos[i][j];j++){
            arch<<left<<setw(10)<<codigoPedidos[i][j]<<" "<<dniCantPedidos[i][j][0]<<" "<<dniCantPedidos[i][j][1]<<endl;
        }
        arch<<endl;
    }
}