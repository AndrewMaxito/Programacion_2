/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 10 de mayo de 2024, 21:20
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream arch("Pedidos2.csv", ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << endl;
        exit(1);
    }
    int dni;
    char coidgo[8];
    while (true) {
        arch>>dni;
        if (arch.eof()) break;
        arch.get();
        while (true) {
            arch>>ws;
            arch.getline(coidgo,8);
            if (arch.fail()) arch.clear();
            cout << coidgo << " ";
            if (arch.get()=='\n') break;
        }
        cout<<endl;
    }
    return 0;
}

