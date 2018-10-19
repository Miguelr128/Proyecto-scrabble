#include <cstdlib>
#include<iostream>

#include "tablero.h"

using namespace std;

int main() {
    int borrador = 5;
    casilla* cas = new casilla (borrador);
    tablero* tab = new tablero (13,13);
    return 0;
}