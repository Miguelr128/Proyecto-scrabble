#include <cstdlib>
#include<iostream>
#include <stdlib.h>
#include <fstream>

#include "tablero.h"

using namespace std;

string obtenerValor(istream&, char = '\t');
int obtenerValorEntero(istream&, char = '\t');
char obtenerValorCaracter(istream&, char = '\t');

int main() {
    fstream archivo_dic;
    string linea_dic;
    string palabra_dic;
    fstream archivo_fic;
    string linea_fic;
    char letra_fic;
    int valorLetra_fic;
    int cantidadLetra_fic;
    
    archivo_dic.open("../diccionario.txt", ios::in);
    archivo_fic.open("../fichas.txt", ios::in);
    while (archivo_dic.good() && archivo_fic.good()) {
        getline(archivo_dic, linea_dic);
        getline(archivo_fic, linea_fic);
        stringstream r(linea_dic);
        stringstream x(linea_fic);
        try {
            palabra_dic = obtenerValor(r);
            letra_fic = obtenerValorCaracter(x);
            valorLetra_fic = obtenerValorEntero(x);
            cantidadLetra_fic = obtenerValorEntero(x);
            cout << palabra_dic << endl;
            cout << valorLetra_fic << ";" << cantidadLetra_fic << endl;
        } catch (int ex) {
        }
    }
    
    tablero* tab = new tablero(13, 13);
    cout << tab -> toString();

    archivo_dic.close();
    archivo_fic.close();
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

int obtenerValorEntero(istream &entrada, char delimitador) {
    string s = obtenerValor(entrada, delimitador);
    stringstream r(s);
    int v;
    if (!(r >> v)) {
        throw -1;
    }
    return v;
}

char obtenerValorCaracter(istream &entrada, char delimitador) {
    string s = obtenerValor(entrada, delimitador);
    stringstream r(s);
    char v;
    if (!(r >> v)) {
        throw -1;
    }
    return v;
}