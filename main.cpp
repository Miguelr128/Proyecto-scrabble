#include <cstdlib>
#include<iostream>
#include <stdlib.h>
#include <fstream>

#include "tablero.h"

using namespace std;

string obtenerValor(istream&, char = '\t');

int main() {
    fstream archivo;
    string linea;
    string palabra;
    archivo.open("diccionario.txt", ios::in);
    while (archivo.good()) {
        getline(archivo, linea);
        stringstream r(linea);
        try {
            palabra = obtenerValor(r);
            cout << palabra << endl;
        } catch (int ex) {
        }
    }

    tablero* tab = new tablero(13, 13);
    tab -> toString();

    archivo.close();
    return 0;
}

string obtenerValor(istream &entrada, char delimitador) {
    string r;
    getline(entrada, r, delimitador);

    if (entrada.fail()) {
        throw -1;
    }
    return r;
}