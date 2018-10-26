#include "jugador.h"

jugador::jugador(string nombre, vectorficha* fi, jugador* j2,tablero* tab, bool t) : nombre(nombre), puntos(0), turno(t)
, otroJugador(j2), juego(tab), ptrMatrizFichas(new vectorfichajugador(7, fi)) {
}

int jugador::getPuntaje(){
    return puntos;
}

jugador* jugador::getOtroJugador(){
    return otroJugador;
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

void jugador::puntosPorPalabra(int i, int j){
    puntos = puntos + juego->contarPuntos(i, j);
}

jugador::~jugador() {
}