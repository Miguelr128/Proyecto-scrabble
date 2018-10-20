#include <cstdlib>
#include<iostream>

#include "tablero.h"

using namespace std;

int main() {
    tablero* tab = new tablero (8,13);
    
    cout<<tab->toString();
    
    return 0;
}