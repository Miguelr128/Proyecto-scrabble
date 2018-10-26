#ifndef SISTEMA_H
#define SISTEMA_H

#include "jugador.h"
#include "tablero.h"

class sistema {
public:
    sistema(jugador*, tablero*);
    virtual ~sistema();
    bool getFinalizar();
//    string toString;
    void sumarPuntos(jugador*, int, int);
//    int puntosScrabble(jugador*);
    void finalizarJuego();
    string ganador();
private:
    jugador* primerJugador;
    tablero* ptrTablero;
//    int puntajeTotal;
//    int puntajeTurno;
    bool finalizar;
};
#endif /* SISTEMA_H */