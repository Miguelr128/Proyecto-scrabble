#include "sistema.h"

sistema::sistema(jugador* j, tablero* t):primerJugador(j), ptrTablero(t), finalizar(false) {
}

string sistema::ganador(){
    stringstream s;
    jugador* jugador2 = primerJugador->getOtroJugador();
    if(primerJugador->getPuntaje() == jugador2->getPuntaje()){
        s<<"Empate";
    }
    else
        if(primerJugador->getPuntaje() > jugador2->getPuntaje()){
            s<<"Primer jugador es el ganador";
        }
        else
            s<<"Segundo jugador es el ganador";
    return s.str();
}

void sistema::finalizarJuego(){
    finalizar = true;
}

bool sistema::getFinalizar(){
    return finalizar;
}

void sistema::sumarPuntos(jugador* j, int f, int c){
    j->puntosPorPalabra(f, c);
}

sistema::~sistema() {
}