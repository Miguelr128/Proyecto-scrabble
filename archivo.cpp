#include "archivo.h"

archivo::archivo() {
}

archivo::~archivo() {
}

//void archivo::escribir(string palabras, int puntos) {
//    ofstream fout;
//    fout.open("datos.txt", ios::out);
//    if (fout.fail()) {
//        exit(1);
//    }
//    fout << "Palabra Formada: " << palabras << "Puntos obtenidos: " << puntos << endl;
//    fout.close();
//}
//
//void archivo::leer() {
//    ifstream fin;
//    string aux;
//    fin.open("datos.txt", ios::in);
//    if (fin.fail()) {
//        exit(1);
//    }
//    while (!fin.eof()) {
//        getline (fin, aux);
//    }
//    fin.close();
//}