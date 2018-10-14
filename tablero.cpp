/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tablero.cpp
 * Author: MIGUEL
 * 
 * Created on October 4, 2018, 6:30 PM
 */

#include "tablero.h"

tablero::tablero(int f, int c): filas(f),columnas(c), casillas(new casilla**[f]){
    for(int i=0; i < f; i++){
        casillas[i] = new casilla*[c];
    }
    
    for(int i=0; i < f; i++){
        for(int j=0; j < c; j++){
            casillas[i][j] = new casilla();
        }
    }
}

tablero::~tablero() {
}

string tablero::toString() const{
    stringstream s;
    s<<"";
    for(int m = 0; m < columnas; m++){
        s<<"\t "<<m<<"  ";
    }
    s<<endl;
    for(int i=0; i < filas; i++){
        s<<i<<" ";
        for(int j=0; j < columnas; j++){
            s<<"\t"<<"["<<casillas[i][j]<<"]";
        }
        s<<endl;
    }
    return s.str();
}
