#include "jugador.h"

jugador::jugador(string nombre, vectorficha* fi, jugador* j2,tablero* tab, bool t) : nombre(nombre), puntos(0), turno(t)
, otroJugador(j2), juego(tab), ptrVectorFichas(new vectorfichajugador(7, fi)) {
}

int jugador::getPuntaje(){
    return puntos;
}

jugador* jugador::getOtroJugador(){
    return otroJugador;
}

ficha* jugador::getFicha(int i){
    return ptrVectorFichas->buscarFicha(i);
}

string jugador::getNombre(){
    return nombre;
}

bool jugador::getTurno(){
    return turno;
}

void jugador::fichasInicio() {
    ptrVectorFichas->primerasFichas();
}

void jugador::cambiarFichas(int i) {
    ptrVectorFichas->cambiar(i);
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
    ptrVectorFichas->nuevasFichas();
}

void jugador::cambiarComodin(int i, string l) {
    ptrVectorFichas->cambiarComodin(i, l);
}

void jugador::colocarFicha(int fi, int co, ficha* ficha) {
    juego->reservarPosicion(fi, co, ficha);
}

void jugador::puntosPorPalabra(int i, int j){
    puntos = puntos + juego->contarPuntos(i, j);
}

string jugador::toString(){
    stringstream s;
    s<<ptrVectorFichas->toString();
    return s.str();
}

jugador::~jugador() {
}