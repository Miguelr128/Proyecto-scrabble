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
    jugador(string, vectorficha*, jugador*, tablero*, bool);
    virtual ~jugador();
    int getPuntaje();
    jugador* getOtroJugador();
    string getNombre();
    bool getTurno();
    ficha* getFicha(int);
    string formarPalabra(string);
    void colocarFicha(int, int, ficha*);
    void nuevasFichas();
    void fichasInicio();
    void cambiarFichas(int);
    void pasarTurno();
    void cambiarComodin(int, string);
    void puntosPorPalabra(int, int);
    string toString();
    
private:
    string nombre;
    bool turno;
    tablero* juego;
    vectorfichajugador* ptrVectorFichas;
    jugador* otroJugador;
    int puntos;
};
#endif /* JUGADOR_H */