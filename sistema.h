#ifndef SISTEMA_H
#define SISTEMA_H

#include "jugador.h"
#include "tablero.h"
#include "diccionario.h"
#include "archivo.h"

class sistema {
public:
    sistema(jugador*, tablero*, diccionario*);
    virtual ~sistema();
    bool getFinalizar();
    void sumarPuntos(jugador*, int, int);
    bool puntosScrabble(string);
    void iniciarJuego();
    void turno(int, jugador*, int);
    bool palabrasIguales(string, string);
    void finalizarJuego();
    bool validarPalabraVFJ(string, int, jugador*);
    string ganador();
private:
    jugador* primerJugador;
    tablero* ptrTablero;
    diccionario* dic;
    bool finalizar;
    archivo* ptrArchivo;
};
#endif /* SISTEMA_H */