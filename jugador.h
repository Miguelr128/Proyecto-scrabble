#ifndef JUGADOR_H
#define JUGADOR_H

#include "vectorficha.h"
#include "vectorfichajugador.h"
#include "tablero.h"

#include <string.h>
#include <string>
using std::string;


class jugador {
public:
    jugador(string, vectorficha*, jugador*, bool);
    virtual ~jugador();
    string formarPalabra(string);
    void colocarFicha(int, int, ficha*);
    void nuevasFichas();
    void fichasInicio();
    void cambiarFichas(int);
    void pasarTurno();
    void cambiarComodin(int, string);
    
private:
    string nombre;
    bool turno;
    tablero* juego;
    vectorfichajugador* ptrMatrizFichas;
    jugador* otroJugador;
    int puntos;
};
#endif /* JUGADOR_H */