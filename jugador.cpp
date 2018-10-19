#include "jugador.h"

jugador::jugador(string nombre) : nombre(nombre), puntos(0), fichasDisponibles(new vectorficha(7)) {
}

jugador::~jugador() {
}