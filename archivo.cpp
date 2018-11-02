#include "archivo.h"

archivo::archivo() : cantidad (0), puntos (0), palabra("") {
}

archivo::~archivo() {
}

void archivo::guardarPalabras(string palabras, jugador* j) {
    ofstream fout;
    fout.open("palabras.txt", ios::out);
    if (fout.fail()) {
        exit(1);
    }
    fout << "Palabra Formada por " <<j->getNombre()<<": "<< palabras<<endl;
    
    fout.close();
}

void archivo::guardarPuntaje(int punt, jugador* j){
    ofstream fout;
    fout.open("puntaje.txt", ios::out);
    if (fout.fail()) {
        exit(1);
    }
    fout << "Puntaje obtenido por " <<j->getNombre()<<": "<< punt<<endl;
    
    fout.close();
}

void archivo::leer() {
    ifstream fin;
    string aux;
    fin.open("datos.txt", ios::in);
    if (fin.fail()) {
        exit(1);
    }
    while (!fin.eof()) {
        getline (fin, aux);
    }
    fin.close();
}

string archivo::toString() {
    
}