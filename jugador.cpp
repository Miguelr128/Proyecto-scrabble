#include "jugador.h"

jugador::jugador(string nombre, vectorficha* fi, jugador* j2, bool t) : nombre(nombre), puntos(0), turno(t)
, otroJugador(j2), ptrMatrizFichas(new vectorfichajugador(7, fi)) {
}

void jugador::fichasInicio() {
    ptrMatrizFichas->primerasFichas();
}

void jugador::cambiarFichas(int i) {
    ptrMatrizFichas->cambiar(i);
}

void jugador::pasarTurno() {
    turno = false;
}

string jugador::formarPalabra(string ficha) {
    string palabra = NULL;
    palabra = palabra + ficha;
    return palabra;
}

void jugador::nuevasFichas() {
    ptrMatrizFichas->nuevasFichas();
}

void jugador::cambiarComodin(int i, string l) {
    ptrMatrizFichas->cambiarComodin(i, l);
}

void jugador::colocarFicha(int fi, int co, ficha* ficha) {
    juego->reservarPosicion(fi, co, ficha);
}

jugador::~jugador() {
}