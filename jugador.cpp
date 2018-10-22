#include "jugador.h"

jugador::jugador(string nombre) : nombre(nombre), puntos(0), ptrMatrizfichas(new vectorficha()) {
}

jugador::~jugador() {
}