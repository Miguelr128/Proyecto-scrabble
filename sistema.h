#ifndef SISTEMA_H
#define SISTEMA_H

#include "jugador.h"
#include "tablero.h"
#include "diccionario.h"

class sistema {
public:
    sistema(jugador*, tablero*, diccionario*);
    virtual ~sistema();
    bool getFinalizar();
//    string toString();
    void sumarPuntos(jugador*, int, int);
    bool puntosScrabble(string);
    void iniciarJuego();
    void turno(int, jugador*);
    bool palabrasIguales(string, string);
    void finalizarJuego();
    bool validarPalabraVFJ(string, int, jugador*);
    string ganador();
    void encontrarPalabraFormada();
private:
    jugador* primerJugador;
    tablero* ptrTablero;
    diccionario* dic;
//    int puntajeTotal;
//    int puntajeTurno;
    bool finalizar;
};
#endif /* SISTEMA_H */