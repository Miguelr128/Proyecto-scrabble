#include <cstdlib>
#include<iostream>
#include <stdlib.h>
#include <fstream>
#include <csetjmp>

#include "tablero.h"
#include "ficha.h"
#include "diccionario.h"
#include "sistema.h"

using namespace std;

string obtenerValor(istream&, char);
int obtenerValorEntero(istream&, char = ('\t' || '/'));

int main() {
    fstream archivo_dic;
    string linea_dic;
    string palabra_dic;
    fstream archivo_fic;
    string linea_fic;
    string letra_fic;
    int valorLetra_fic;
    int i = 0;
    fstream archivo_guardar;
    
    int opcion;
    bool seguirPrograma = true;
    string nombreJug1;
    string nombreJug2;

    archivo_dic.open("diccionario.txt", ios::in);
    archivo_fic.open("fichas.txt", ios::in);
    archivo_guardar.open("datos.txt", ios::out);
    vectorficha* fichasSistema = new vectorficha();
    diccionario* palabrasDiccionario = new diccionario(1550);
    
    while (archivo_fic.good()) {
        getline(archivo_fic, linea_fic);
        stringstream x(linea_fic);
        try {
            letra_fic = obtenerValor(x, '\t');
            fichasSistema->setLetra(i, letra_fic);
            valorLetra_fic = obtenerValorEntero(x, '\t');
            fichasSistema->setValor(i, valorLetra_fic);
            i++;
        } catch (int ex) {
        }
    }
    while (!archivo_dic.eof()) {
        getline(archivo_dic, linea_dic);
        stringstream r(linea_dic);

            getline(r, palabra_dic, '\n');
            palabrasDiccionario->agregar(palabra_dic);
    }
    
//    cout<<palabrasDiccionario->toString();

    do {
        system("cmd /c color 79");
        system("cmd /c cls");
        cout << "*******************SCRABBLE*******************\n";
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Digite la opcion que desea:\n";
        cout << endl;
        cout << "[1] Continuar partida.\n";
        cout << "[2] Nueva partida.\n";
        cout << "[3] Finalizar programa.\n";
        cout << endl;
        cout<<"opcion: ";
        cin>>opcion;
        switch (opcion) {
            case 1: {
                system("cmd /c cls");
                cout << "Hola" << endl;
                system("cmd /c pause");
                break;
            }
            case 2: {
                system("cmd /c cls");
                tablero* tab = new tablero(8, 13);
                cout << "Digite el nombre del primer Jugador" << endl;
                cout<<"Nombre: ";
                cin >> nombreJug1;
                cout << "Digite el nombre del segundo Jugador" << endl;
                cout<<"Nombre: ";
                cin >> nombreJug2;
                jugador* jug2 = new jugador (nombreJug2, fichasSistema, NULL, tab, false);
                jugador* jug1 = new jugador (nombreJug1, fichasSistema, jug2, tab, true);
                sistema* sis = new sistema (jug1, tab, palabrasDiccionario);
                sis->iniciarJuego();
                system("cmd /c pause");
                break;
                delete tab;
                delete jug1;
                delete jug2;
                delete sis;
            }
            case 3: {
                system("cmd /c cls");
                cout << "Hola" << endl;
                system("cmd /c pause");
                seguirPrograma = false;
                break;
            }
        }
    } while (seguirPrograma);
    
    archivo_dic.close();
    archivo_fic.close();
    archivo_guardar.close();
    delete fichasSistema;
    delete palabrasDiccionario;
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