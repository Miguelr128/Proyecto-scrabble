#include "vectorfichajugador.h"

vectorfichajugador::vectorfichajugador(int x, vectorficha* fi) :tamano(x), cantidad (x), fichasSistema(fi), vector(new ficha*[x]) {
    for(int i = 0; i < tamano; i++){
        vector[i] = NULL;
    }
}

vectorfichajugador::~vectorfichajugador() {
}

void vectorfichajugador::primerasFichas() {
    int numero, rango = fichasSistema->getCantidad();
    srand (time (NULL));
    for (int i = 0; i < tamano; i++) {
        numero = rand() % rango;
        vector[i] = fichasSistema->getFicha(numero);
        fichasSistema->eliminarFicha(numero);
        rango = rango -1;
    }
}

void vectorfichajugador::cambiar(int i){
    int numero, rango = fichasSistema->getCantidad();
    ficha* aux;
    numero = rand() % rango;
    aux = vector[i];
    vector[i] = fichasSistema->getFicha(numero);
    fichasSistema->setFicha(numero, aux);
}

void vectorfichajugador::nuevasFichas(){
    int numero, rango = fichasSistema->getCantidad();
    for (int i = 0; i < tamano; i++) {
        if(vector[i] == NULL){
            numero = rand() % rango;
            vector[i] = fichasSistema->getFicha(numero);
            fichasSistema->eliminarFicha(numero);
            rango = rango -1;
        }
    }
}

void vectorfichajugador::cambiarComodin(int i, string l){
    vector[i]->setLetra(l);
}

ficha* vectorfichajugador::buscarFicha(int i){
    return vector[i];
}

string vectorfichajugador::toString(){
    stringstream s;
    for(int i = 0; i < cantidad; i++){
        s<<vector[i]<<" | ";
    }
    return s.str();
}

void vectorfichajugador::eliminar(int i){
    vector[i] = NULL;
}
