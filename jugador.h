#ifndef JUGADOR_H
#define JUGADOR_H

#include "vectorficha.h"
#include "tablero.h"

#include <string>
using std::string;

class jugador {
public:
    jugador(string);
    virtual ~jugador();
//    void formarPalabra();
//    void colocarFicha(int, int, ficha*);
//    void nuevasFichas(vectorficha*);
//    void cambiarFichas();
//    void pasarTurno();
//    void cambiarComodin(char);
    
private:
    string nombre;
    tablero* juego;
    vectorficha* fichasDisponibles;
    jugador* otroJugador;
    int puntos;
};
#endif /* JUGADOR_H */