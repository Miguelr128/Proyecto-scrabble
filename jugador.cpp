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



jugador::~jugador() {
}