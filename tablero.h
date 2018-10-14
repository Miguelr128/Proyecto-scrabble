/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tablero.h
 * Author: MIGUEL
 *
 * Created on October 4, 2018, 6:30 PM
 */

#ifndef TABLERO_H
#define TABLERO_H

#include <sstream>
using namespace std;

class tablero {
public:
    tablero(int, int);
    void reservarPosicion(int,int);
    string toString() const;
     virtual ~tablero();
private:
    int filas;
    int columnas;
    casilla** casillas;
   
};

#endif /* TABLERO_H */

