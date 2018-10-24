#include "diccionario.h"

diccionario::diccionario(int a): tamano(a), cantidad(0), palabras(new string[a]) {
}

void diccionario::agregar(string pa){
    palabras[cantidad++] = pa;
}

string diccionario::toString(){
    stringstream s;
    for(int i = 0; i < cantidad; i++){
        s<<palabras[i]<<endl;
    }
    return s.str();
}

diccionario::~diccionario() {
}