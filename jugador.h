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
    jugador* getOtroJugador();
    string getNombre();
    bool getTurno();
    int getPuntos();
    void eliminar(int);
    void setTurno(bool);
    void setPuntos(int);
    ficha* getFicha(int);
    string formarPalabra(string[], int);
    void colocarFicha(int, int, ficha*);
    void nuevasFichas();
    void fichasInicio();
    void cambiarFichas(int);
    void pasarTurno();
    bool estaLleno();
    void cambiarComodin(int, string);
    void puntosPorPalabra(int, int);
    string toString();
    vectorfichajugador* getPtrVectorFichas();
private:
    string nombre;
    bool turno;
    tablero* juego;
    vectorfichajugador* ptrVectorFichas;
    jugador* otroJugador;
    int puntos;
};
#endif /* JUGADOR_H */