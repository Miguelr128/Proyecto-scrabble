#include "jugador.h"

jugador::jugador(string nombre, vectorficha* fi, jugador* j2, bool t) : nombre(nombre), puntos(0), turno(t), otroJugador(j2) ptrMatrizFichas(new vectorfichajugador(7, fi)) {
}

void jugador::fichasInicio(){
    ptrMatrizFichas->primerasFichas();
}

void jugador::cambiarFichas(int i){
    ptrMatrizFichas->cambiar(i);
}

void jugador::pasarTurno(){
    turno = false;
}

char jugador::formarPalabra(string ficha) {
    char letrasPalabra [7];
    strcat(letrasPalabra, ficha.c_str());
    for (int i = 0; i < 7; i++)
        return letrasPalabra[i];
}

void jugador::nuevasFichas(){
    ptrMatrizFichas->nuevasFichas();
}

void jugador::cambiarComodin(int i, string l){
    ptrMatrizFichas->cambiarComodin(i, l);
}

jugador::~jugador() {
}