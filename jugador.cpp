#include "jugador.h"

jugador::jugador(string nombre, vectorficha* fi, bool t) : nombre(nombre), puntos(0), turno(t), ptrMatrizFichas(new vectorfichajugador(7, fi)) {
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

jugador::~jugador() {
}