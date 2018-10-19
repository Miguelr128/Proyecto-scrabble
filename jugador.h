#ifndef JUGADOR_H
#define JUGADOR_H

#include "vectorficha.h"

#include <string>
using std::string;

class jugador {
public:
    jugador(string);
    virtual ~jugador();
//    void formarPalabra();
//    void colocarPalabra(tablero*);
//    void nuevasFichas(vectorficha*);
//    void cambiarFichas();
//    void pasarTurno();
//    void cambiarComodin(char);
    
private:
    string nombre;
    vectorficha* fichasDisponibles;
    int puntos;
};
#endif /* JUGADOR_H */