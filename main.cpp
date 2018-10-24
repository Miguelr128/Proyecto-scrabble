#include <cstdlib>
#include<iostream>
#include <stdlib.h>
#include <fstream>

#include "tablero.h"
#include "ficha.h"
#include "diccionario.h"

using namespace std;

string obtenerValor(istream&, char);
int obtenerValorEntero(istream&, char = '\t');
char obtenerValorCaracter(istream&, char = '\t');

int main() {
    
    vectorficha* fichasSistema = new vectorficha();
    diccionario* palabrasDiccionario = new diccionario(3000);
    fstream archivo_dic;
    string linea_dic;
    string palabra_dic;
    fstream archivo_fic;
    string linea_fic;
    string letra_fic;
    int valorLetra_fic;
    int i = 0;
    
    archivo_dic.open("diccionario.txt", ios::in);
    archivo_fic.open("fichas.txt", ios::in);
   
    while (archivo_fic.good()) {
        getline(archivo_fic, linea_fic);
        stringstream x(linea_fic);        
        try {
            letra_fic = obtenerValorCaracter(x, '\t');
            fichasSistema->setLetra(i, letra_fic);
            valorLetra_fic = obtenerValorEntero(x, '\t');
            fichasSistema->setValor(i, valorLetra_fic);
//            cout << valorLetra_fic << ";" << letra_fic << endl;
            i++;
        } catch (int ex) {
        }
    }
    
    while (archivo_dic.good()) {
        getline(archivo_dic, linea_dic);
        stringstream r(linea_dic);
        try {
            palabra_dic = obtenerValor(r, '\t');
            palabrasDiccionario->agregar(palabra_dic);
//            cout << palabra_dic << endl;
        } catch (int ex) {
        }
    }
    
//    cout<<fichasSistema->toString()<<endl;
    cout<<palabrasDiccionario->toString()<<endl;
    
    tablero* tab = new tablero(13, 13);
//    cout << tab -> toString();

    archivo_dic.close();
    archivo_fic.close();
    delete fichasSistema;
    
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