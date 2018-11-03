#include "vectorfichajugador.h"

vectorfichajugador::vectorfichajugador(int x, vectorficha* fi) :tamano(x), cantidad (x), fichasSistema(fi), vector(new ficha*[x]) {
    for(int i = 0; i < x; i++){
        vector[i] = NULL;
    }
    primerasFichas();
}

vectorfichajugador::~vectorfichajugador() {
}

void vectorfichajugador::setFichas(int i, ficha* f){
    vector[i] = f;
}

void vectorfichajugador::primerasFichas() {
    int numero, rango = fichasSistema->getCantidad();
    ficha* fi;
    for (int i = 0; i < cantidad; i++) {
        numero = rand() % rango;
        srand (time (NULL));
        fi = fichasSistema->getFicha(numero);
        setFichas(i, fi);
        fichasSistema->eliminarFicha(numero);
        rango = rango -1;
    }
}

int vectorfichajugador::buscarPosicionFicha(string ficha) {
    for (int i = 0; i < cantidad; i++)
        if (vector[i] ->getLetra() == ficha)
            return i;
}

void vectorfichajugador::cambiar(int i){
    int numero, rango = fichasSistema->getCantidad();
    ficha* aux;
    numero = rand() % rango;
    srand (time (NULL));
    aux = vector[i];
    vector[i] = fichasSistema->getFicha(numero);
    fichasSistema->setFicha(numero, aux);
}

bool vectorfichajugador::estaLleno(){
    for(int i = 0; i < cantidad; i++){
        if(vector[i] == NULL)
            return false;
    }
    return true;
}

void vectorfichajugador::nuevasFichas(){
    int numero, rango = fichasSistema->getCantidad();
    for (int i = 0; i < tamano; i++) {
        if(vector[i] == NULL){
            numero = rand() % rango;
            srand (time (NULL));
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
    s<<"  0   1   2   3   4   5   6"<<endl;
    s<<"| ";
    for(int i = 0; i < cantidad; i++){
        if(vector[i]==NULL){
            s<<" - |";
        }
        s<<vector[i]->toString()<<" | ";
    }
    return s.str();
}

void vectorfichajugador::eliminar(int i){
    vector[i] = NULL;
}
